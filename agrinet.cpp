/*
ID:svasude4
PROG:agrinet
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#define MAX_FARMS 100
#define INT_MAX 99999999
using namespace std;
struct node {
  int distance;
  bool intree;
  int source;
};
int Matrix[MAX_FARMS][MAX_FARMS];

int main()
{
  ifstream fin("agrinet.in");
  ofstream fout("agrinet.out");

  /*# distance(j) is distance from tree to node j
# source(j) is which node of so-far connected MST
    #                      is closest to node j
   1   For all nodes i
     2     distance(i) = infinity        # no connections
     3     intree(i) = False             # no nodes in tree
     4     source(i) = nil

      5   treesize = 1                    # add node 1 to tree
      6   treecost = 0
     7   intree(1) = True
      8   For all neighbors j of node 1   # update distances
     9      distance(j) = weight(1,j)
     10     source(j) = 1

     11   while (treesize < graphsize)
	    12     find node with minimum distance to tree; call it node i
	    13     assert (distance(i) != infinity, "Graph Is Not Connected")
	    
	    # add edge source(i),i to MST
	    14     treesize = treesize + 1
	    15     treecost = treecost + distance(i)
	    16     intree(i) = True              # mark node i as in tree
	    
	    # update distance after node i added
	    17     for all neighbors j of node i
	    18       if (distance(j) > weight(i,j))
	    19         distance(j) = weight(i,j)
	    20         source(j) = i
	    

  */
  int N;
  int treesize=1;
  int treecost=0;
  node temp;

  temp.source=-1;
  temp.intree=false;
  temp.distance=INT_MAX;
  fin>>N;
  vector<node> tree;
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  fin>>Matrix[i][j];
	  //cout<<Matrix[i][j]<<" ";
	  
	}
      tree.push_back(temp);
      //cout<<endl;
    }
  tree[0].intree=true;
  for (int i=0;i<N;i++)
    {
      tree[i].distance=Matrix[0][i];
      tree[i].source=0;
      
    }
  //add neighnor's distance of o to the tree vector

 int new_source=0;
  while(treesize<N)
    {
      //find nodes with minimum distance to the tree
      int minimum_distance=INT_MAX;
      int node_to_be_added=-1;
      
      for (int j=0;j<N;j++)
	{
	  if (!tree[j].intree)
	    {
	      if (tree[j].distance<minimum_distance)
		{
		  
		  minimum_distance=tree[j].distance;
		  new_source=tree[j].source;
		  node_to_be_added=j;
		}
	    }
	}


      tree[node_to_be_added].intree=true;
      tree[node_to_be_added].distance=minimum_distance;
      tree[node_to_be_added].source=new_source;
      treecost+=minimum_distance;
      treesize++;

      //update distance of the neighbors
      for(int i=0; i<N; i++)
	{
	  if (!tree[i].intree)
	    {
	      
	      if (node_to_be_added!=i)
		{
		  if (tree[i].distance>Matrix[node_to_be_added][i])
		    {
		      tree[i].distance=Matrix[node_to_be_added][i];
		      tree[i].source=node_to_be_added;
		    }
		}
	    }
	}
    }
  //Print tree;
  /*for (int i=0;i<N;i++)

    {

      cout<<"node "<<i<<endl;
      cout<<"source "<<tree[i].source<<endl;
      cout<<"distance "<<tree[i].distance<<endl;
      cout<<endl<<endl;
	
      
    }
  */
  fout<<treecost<<endl;
  
}
