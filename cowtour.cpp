/*
ID:svasude2
PROG:cowtour
LANG:C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#define MAX_N 150
using namespace std;
struct Pasture{
  double X,Y;
  int Component,id;
};
bool Adjacency_List[MAX_N][MAX_N];  
Pasture Pastures[MAX_N];
int N;
int num_components=0;
Pasture Component_i[MAX_N];
Pasture Component_j[MAX_N];
Pasture pasture(int X,int Y,int id)
{
  Pasture P;
  P.X=X;
  P.Y=Y;
  P.Component=0;
  P.id=id;
  return P;
}
double Dist[MAX_N][MAX_N];
double Distance(Pasture p1,Pasture p2)
{
  return sqrt(pow((p2.X-p1.X),2)+pow((p2.Y-p1.Y),2));
}

void flood_fill(int new_component)
{
  int num_visited=0;
  do 
    {
      num_visited=0;
      for (int i=0;i<N;i++)
	{
	  if (Pastures[i].Component==-2)
	    {
	      Pastures[i].Component=new_component;
	      num_visited++;
	      //mark neighbouring elements as -2
	      for (int m=0;m<N;m++)
		{
		  if ((Adjacency_List[i][m]==1)&&(i!=m))
		    {
		      if (Pastures[m].Component==0) Pastures[m].Component=-2;
		    }
		}
	    }
	}
    }while(num_visited);
}
void find_components(void)
{
  
  for (int i=0;i<N;i++)
    {
      
      if (Pastures[i].Component==0) 
	{
	  num_components++;
	  Pastures[i].Component=-2;
	  flood_fill(num_components);
	  for (int j=0;j<N;j++)
	    {
	      //	      if (Pastures[j].Component==num_components) cout<<"Component: "<<num_components<<" "<<Pastures[j].X<<","<<Pastures[j].Y<<endl;
	    }
	  
	}
     }
  
}
int main()
{
  ifstream fin("cowtour.in");
  ofstream fout("cowtour.out");
  

  fin>>N;
  int x,y;
  for (int i=0;i<N;i++)
    {
      fin>>x>>y;
      //cout<<x<<" "<<y<<endl;
      Pastures[i]=pasture(x,y,i);
    }
  char temp;
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  fin>>temp;
	  Adjacency_List[i][j]=temp-48;
	  //if (temp-48) //cout<<"Distance between "<<i<<" and "<<j<<" is "<<Distance(Pastures[i],Pastures[j])<<endl;
	  if (i==j) Dist[i][j]=0;
	  else if (temp-48) Dist[i][j]=Distance(Pastures[i],Pastures[j]);
	  else Dist[i][j]=987654321;
	  
	}
      //  cout<<endl;
    }
  //Identify Connected Components (Breadth First Scanning)
  find_components();
  //
  // After find the all the components, select all possible combinations to connect pastures between all possible pairs of components.
  //1. Generate all possible pairs.
  int count_i=0;
  int count_j=0;
  double min_diameter=987654321;
  double diam_comp=0;
  ///////////////////////Floyd Warshall////////////////////////
  int k;
  for (k = 0; k < N; k++)
    {
      // Pick all vertices as source one by one
      for (int i_f = 0; i_f < N; i_f++)
	{
	  // Pick all vertices as destination for the
	  // above picked source
	  for (int j_f = 0; j_f < N; j_f++)
	    {
	      // If vertex k is on the shortest path from
	      // i to j, then update the value of dist[i][j]
	      if ((Dist[i_f][k]!=987654321)&&(Dist[k][j_f]!=987654321))
		{
		  
		  if (Dist[i_f][k] + Dist[k][j_f] < Dist[i_f][j_f])
		    Dist[i_f][j_f] = Dist[i_f][k] + Dist[k][j_f];
		}
	    }
	}
    }
  //find the longest diameter in any component
  for (int o=0;o<N;o++)
    {
      for (int oo=0;oo<N;oo++)
	{
	  if (Dist[o][oo]!=987654321)
	    {
	      //cout<<std::setprecision(6)<<std::fixed<<Dist[o][oo]<<endl;
	      if (diam_comp<Dist[o][oo]) diam_comp=Dist[o][oo];
	    }
	}

    }
  //cout<<min_diameter<<endl;
  cout<<"NUMBER OF COMPONENTS: "<<num_components<<endl;
  for (int i=1;i<=num_components;i++)
    {
      
      for (int j=i+1;j<=num_components;j++)
	{
	  //Look through the pastures array and create all possible pairs of vertices, one from component i and one fron component j
	  
	  count_i=0;
	  count_j=0;
	  for (int k=0;k<N;k++)
	    {
	   
	      if (Pastures[k].Component==i) Component_i[count_i++]=Pastures[k];
	    }
	  for (int k=0;k<N;k++)
	    {
	      if (Pastures[k].Component==j) Component_j[count_j++]=Pastures[k];
	    }
	  //Connect each vertex from component i to component j's and check the diameter by running floyd warshall, and delete the connection afterwards.

	 
	  //////////////////////////////////////////////////////////////////////////////
	  for (int i_c=0;i_c<count_i;i_c++)
	    {
	      
	      for (int j_c=0;j_c<count_j;j_c++)
		{
		  //Connect these two pastures int the graph
		  //		  cout<<"JOINING "<<Component_i[i_c].id<<" : "<<Component_j[j_c].id<<endl;
		  double distance=Distance(Component_i[i_c],Component_j[j_c]);
		  double max1=0;
		  double diameter=0;
		  //		  cout<<" Connecting Edge : "<<Component_i[i_c].id<<"->"<<Component_j[j_c].id<<endl;
		  for (int p=0;p<count_i;p++)
		    {
		      for (int pp=0;pp<count_j;pp++)
			{
			  
			  diameter=Dist[Component_i[p].id][Component_i[i_c].id]+distance+Dist[Component_j[pp].id][Component_j[j_c].id];
			  //if ((diameter<17497.69)&&(diameter>17497.68))  cout<<std::setprecision(6)<<std::fixed<<"Distance between : "<<Component_i[p].id<<" and "<<Component_j[pp].id<<" : " <<diameter<<endl; 
			  if (diameter>max1)
			    max1=diameter;
			}
		    }
		  //cout<<"yo"<<min_diameter<<" "<<max1<<endl;
		  if  (max1<min_diameter) min_diameter=max1;
		}
	      
	    }
	}

    }

  if (diam_comp<min_diameter)  fout<<std::setprecision(6)<<std::fixed<<min_diameter<<endl;
  else   fout<<std::setprecision(6)<<std::fixed<<diam_comp<<endl;
    

}
