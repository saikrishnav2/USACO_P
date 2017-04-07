/*
ID:svasude2
PROG:maze1
LANG:C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <queue>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

char Grid [201][77];
int Distance[3800][2];
int Visited[3800];
int Parent[3800];
int Repeat[3800];
struct node{
  int Vertex;
  int Distance;
};
node Edges [3800][4];
bool operator<(const node& a, const node& b) {
  return a.Distance > b.Distance;
}

int main()
{
  ifstream fin("maze1.in");
  ofstream fout("maze1.out");
  int W,H;
  fin>>W>>H;
  /*Algorithm
  Representation of graphs :
  In this case each vertices connects a square upwards,downwards,leftwards or rightwards.
  
  Make the vertex at the border having an opening as the destination vertex.

  While reading the file, The even lines should look for '-' and update downwards information of the vertex above it and upwards
    
  //If in odd row, look for odd c 

  for 
  */
  char temp;
  fin.ignore();
  for (int i=0;i<(2*H+1);i++)
    {
      for (int j=0;j<(2*W+1);j++)
	{
	  fin.get(Grid[i][j]);
	  cout<<Grid[i][j];
	}
      fin.ignore();
      cout<<" "<<i<<endl;
    }
  //Go through the border and look for two destination vertices.

  //To go through the upper and lower border look at the odd places and if there is a space it means destination vertex
  int Destination_Vertex[2]={0};
  int count=0;
  for (int i=0;i<W*H;i++)
    {
      //initialize
      Distance[i][0]=987654321;
      Distance[i][1]=987654321;
      Visited[i]=0;
      Parent[i]=-1;
      Repeat[i]=0;
      for (int j=0;j<4;j++)
	{
	  Edges[i][j].Vertex=-1;
	  Edges[i][j].Distance=987654321;
	}
    }
  
  //upper border
  for (int i=1;i<(2*W+1);i+=2) 
    {
      if (Grid[0][i]==' ') Destination_Vertex[count++]=i/2;
    }
  //lower border
  
  for (int i=1;((i<(2*W+1))&&(count<2));i+=2){
    if (Grid[2*H][i]==' ') Destination_Vertex[count++]=(W*(H-1)+(i/2));
  }
  //Left border
  for (int i=1;((i<2*H+1)&&(count<2));i+=2){
    if (Grid[i][0]==' ') Destination_Vertex[count++]=(W*(i/2));
  }
  //Right Border
  for (int i=1;((i<2*H+1)&&(count<2));i+=2){
    if (Grid[i][2*W]==' ') Destination_Vertex[count++]=(W*(i/2)+W-1);
  }
  cout<<Destination_Vertex[0]<<" "<<Destination_Vertex[1]<<endl;
  // Create Edges List
  for (int i=1;i<(2*H+1);i+=2)
    {
      for  (int j=1;j<(2*W+1);j+=2)
	{
	  if ((i/2)!=0)
		{
		  if (Grid[i-1][j]==' ') Edges[W*(i/2)+(j/2)][UP].Vertex=W*((i-2)/2)+(j/2);
		}
	      
	      //look down
	  if ((i/2)!=(H-1))
	    {
	      if (Grid[i+1][j]==' ') Edges[W*(i/2)+(j/2)][DOWN].Vertex=W*((i+2)/2)+(j/2);
	    }
	      
	  //if on the left dont look left
	  if (j/2!=0)
	    {
	      if (Grid[i][j-1]==' ') Edges[W*(i/2)+(j/2)][LEFT].Vertex=W*(i/2)+(j-2)/2;
	      
	    }
	  //if on the right dont look right
	  if ((j/2)!=(W-1))
	    {
	      if (Grid[i][j+1]==' ') Edges[W*(i/2)+(j/2)][RIGHT].Vertex=W*(i/2)+(j+2)/2;
	    }
	  
	}
    }

  //Once Edge list is created run djikstra for each vertex as source and Destination1 and Destination2 as destination vertex. Select the minimum of these shortest paths as the distance for the particular vertex. Output the maxumum of the shortest paths across all vertices.
  priority_queue<node, std::vector<node> > q;
  node p;
  int Max_Distance=0;
  
  
  //Algorithm..Find closest edge to the source vertex that is unvisited.
  
  for(int Source=0;Source<2;Source++)
  {
    //make each Vertex as the Source .

    
	node source;
	source.Vertex=Destination_Vertex[Source];
	
	source.Distance=0;
	Distance[Destination_Vertex[Source]][Source]=0;
	q.push(source);
	
	while(!q.empty())
	  {
	    node Cur=q.top();
	    q.pop();
	    
	    if ((Distance[Cur.Vertex][Source]<=Cur.Distance)&&(!Visited[Cur.Vertex]))
	      {
	    
		Visited[Cur.Vertex]=1;
		//find neighbours
		for (int i=0;i<4;i++)
		  {
		    node neigh=Edges[Cur.Vertex][i];
		    if (neigh.Vertex!=-1)
		      {
			if (Distance[neigh.Vertex][Source]>(Distance[Cur.Vertex][Source]+1))
			  {
			    Distance[neigh.Vertex][Source]=Distance[Cur.Vertex][Source]+1;
			    node to_push;
			    to_push.Vertex=neigh.Vertex;
			    to_push.Distance=Distance[neigh.Vertex][Source];
			    Parent[neigh.Vertex]=Cur.Vertex;
			    q.push(to_push);
			    
			  }
		      }
		    
		  }
	      }
		
	  }
	
	//Store the minimum of the two shortest paths and see if it is greater than the current path
	
	
	
	//Clear Visited,clear Distance,Parent
	
	for (int i=0;i<W*H;i++)
	  {
	    Visited[i]=0;
	    //Distance[i]=987654321;
	  }
    
  }
  for (int i=0;i<W*H;i++) if (Distance[i][0]>Distance[i][1])  Distance[i][0]=Distance[i][1];
  for (int i=0;i<W*H;i++) if (Distance[i][0]>Max_Distance) Max_Distance=Distance[i][0];
  fout<<Max_Distance+1<<endl;
  //for (int i=0;i<W*H;i++)
  //{
  //cout<<"Vertex " <<i<<": "<<Distance[i]<<endl;
      /*for (int j=0;j<4;j++)
	    {
	    cout<<"Edges  " <<i<<" "<<j<<": "<<Edges[i][j].Vertex<<" ";
	    }
      //cout<<endl;
      //}
   

      //}*/

  
}
