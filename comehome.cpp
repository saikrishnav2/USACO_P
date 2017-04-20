/* 
ID:svasude4
PROG:comehome
LANG:C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <queue>

int N;
using namespace std;
int Visited[52]={0};
struct Node{
  long Distance;
  char from,to;
};
struct node{
  int Distance_From_Source;
  bool is_cow;
  char Vertex;
};

Node Edges[10000];
node Pastures[52]; 
bool operator<(const node& a, const node& b) {
  return a.Distance_From_Source > b.Distance_From_Source;
}
int main()
{
  ifstream fin("comehome.in");
  ofstream fout("comehome.out");
  fin>>N;
  for (int i=0;i<52;i++) Visited[i]=0;
  priority_queue<node, std::vector<node> > q;
  // fin.ignore();
  
  for (int i=0;i<N;i++)
    {
      fin>>Edges[i].from;
      fin.ignore();
      fin>>Edges[i].to;
      fin.ignore();
      fin>>Edges[i].Distance;
      fin.ignore();
      cout<<Edges[i].from<<" "<<Edges[i].to<<endl;
      if ((Edges[i].from>=97)&&(Edges[i].from<=122))
	{
	  

	  // cout<<Edges[i].from<<endl;
	}
      else
	{
	  Pastures[Edges[i].from-65].is_cow=1;
	}

	
      if ((Edges[i].to>=97)&&(Edges[i].to<=122))
	{
	  

	  //cout<<Edges[i].to<<endl;
	}
      else
	{
	  Pastures[Edges[i].to-65].is_cow=1;
	}
      //cout<<"yo "<<Edges[5].from<<endl;
    }
  //cout<<"hi"<<endl;
// cout<<Edges[i].from<<" "<<Edges[i].to<<" "<<Edges[i].Distance<<endl;
  for (int i=0;i<52;i++)
    {
      Pastures[i].Distance_From_Source=987654321;
      Pastures[i].Vertex=i+65;
      if (i>=26) Pastures[i].Vertex=i+97-26;
    }

  //List the source as Z which is the last pasture 
  Pastures[25].Distance_From_Source=0;
  q.push(Pastures[25]);
  
  while(!q.empty())
    {
      node Cur=q.top();
      q.pop();
      //
      // for (int i=0;i<52;i++) cout<<Visited[i]<<" "<<i<<endl;
      int index=(Cur.Vertex<97)?(Cur.Vertex-65):(Cur.Vertex-97+26);
      if (!Visited[index])
	{
	  //	  cout<<Cur.Vertex<<endl;
	  Visited[index]=1;
	  for (int i=0;i<N;i++)
	    {
	      //   if (Cur.Vertex=='e') cout<<Edges[i].from<<" "<<Edges[i].to<<endl; 
	      if (((Edges[i].from==Cur.Vertex)||((Edges[i].to==Cur.Vertex))))
		{
		  int index_from=(Edges[i].from<97)?(Edges[i].from-65):(Edges[i].from-97+26);
		  int index_to=(Edges[i].to<97)?(Edges[i].to-65):(Edges[i].to-97+26);
		 
		  node neigh=(Edges[i].from==Cur.Vertex)?Pastures[index_to]:Pastures[index_from];
		  //	  cout<<Edges[i].from<<" "<<Edges[i].to<<" "<<Cur.Vertex<<" "<<Edges[i].Distance<<" "<<Cur.Distance_From_Source<<" "<<neigh.Distance_From_Source<<endl;
		  if (neigh.Distance_From_Source>(Cur.Distance_From_Source+Edges[i].Distance))
		    {
		      //     cout<<neigh.Vertex<<endl;
		      neigh.Distance_From_Source=Cur.Distance_From_Source+Edges[i].Distance;
		      int index_neigh=(neigh.Vertex<97)?(neigh.Vertex-65):(neigh.Vertex-97+26);
		      Pastures[index_neigh].Distance_From_Source=Cur.Distance_From_Source+Edges[i].Distance;
		      q.push(neigh);
		          
		    }
		}
	    }
	          
	}
    }
  //Print Distances and Pastures
  int min=987654321;
  char min_vertex;
  for (int i=0;i<25;i++)
    {
      //      cout<<Pastures[i].Vertex<<" "<<Pastures[i].Distance_From_Source<<endl;
      if (Pastures[i].is_cow) {
	//cout<<Pastures[i].Vertex<<" "<<Pastures[i].Distance_From_Source<<endl;
	if (Pastures[i].Distance_From_Source<min){
	  min=Pastures[i].Distance_From_Source;
	  min_vertex=Pastures[i].Vertex;
	}
      }
    }
  fout<<min_vertex<<" "<<min<<endl;
}

