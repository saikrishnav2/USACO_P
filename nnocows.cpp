#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;




int Bin(int Levels,int Nodes)
{
  int cur_node=Nodes-1;
  //Do Levels-1 to account for the root node
  /*for example:
  11-1=10
  1,9
  3,7
  5,5
  */
  cout<<Levels<<Nodes<<endl;
			    
  if (Nodes==1 && Levels==1) return 1;
  int total_sum=0;
  for (i=1;i<=cur_node/2;i++)//Create all the possible combinations)
    {
      //Recurse_on_left(Levels,cur_node-i);
      {
	if (Levels<=(nodes+1)/2)
	  {
	    left=Bin(Levels-1,cur_node-i);
	  }
	else left=0;
      }
      //  Recurse_on_right();
      /*Calculate from earliest level to the highest level possible*/
      int Earliest_Level=(i+1)/2;
      int Highest_Level=(int) log2(i+1)+1;
      int sum_right=0;
      for (int Cur_Level=Earliest_Level;Cur_Level<=Highest_Level;Cur_Level++)
	{
	  sum_right+=Bin(Cur_Level,i);
	}
      total_sum+=(left*2*sum_right);
    }
 
  return total_sum;
}

int main()
{
  ifstream fin("nocows.in");
  ofstream fout("nocows.out");
  int Nodes,Levels;
  fin>>Nodes>>Levels;
  Bin(Levels,Nodes);
    
}   
    
  

