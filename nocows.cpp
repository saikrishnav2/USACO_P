/*
ID:svasude2
PROG:nocows
LANG:C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
#define PRINT 1
int Recurse_level=0;
int bins[200][101]={-1};


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
  #if PRINT
  //for (int i=0;i<Recurse_level;i++) cout<<"  ";
  //if (Levels==6) cout<<"-->Levels: "<<Levels<<" Nodes: "<<Nodes<<endl;
  #endif
  Recurse_level++;
  if (bins[Nodes][Levels]!=-1) return bins[Nodes][Levels];
  if (Nodes==1 && Levels==1) {Recurse_level--;bins[Nodes][Levels]=1;return 1;}
  else if (Nodes>1 && Levels==1) {Recurse_level--; bins[Nodes][Levels]=0; return 0;}
  else if (Nodes==3 && Levels==2) {Recurse_level--;bins[Nodes][Levels]=1;return 1;}
  int total_sum=0;
  int left=0;
  int left_equal=0;
  int right_equal=0;
  int sum_right=0;
  for (int i=1;i<cur_node;i+=2)//Create all the possible combinations)
     {
       left=0;
       sum_right=0;
       left_equal=0;
       right_equal=0;
       
       if ((Levels-1)<=((cur_node-i+1)/2))
	 {
	   // if (i==cur_node-i) {left_equal=Bin(Levels-1,cur_node-i);}//cout<<"yo....."<<endl;}
	   left=Bin(Levels-1,cur_node-i);
	   	    
	 }
       else left=0;
       
       //  Recurse_on_right();
       //Calculate from earliest level to the highest level possible
       int Earliest_Level=(int) ceil(log2(i+1));
       int Highest_Level=Levels-1;
 
       for (int Cur_Level=1;Cur_Level<=Highest_Level;Cur_Level++)
	{
	  if ((Levels-1==Cur_Level)) right_equal=Bin(Cur_Level,i);
	  else sum_right+=Bin(Cur_Level,i);
	}
      //total_sum+=((left%9901)*2*(sum_right%9901))%9901+(left_equal%9901*right_equal%9901)%9901+(left_equal%9901*(2*sum_right)%9901)%9901;
       //int temp=0;
       //if (right_equal>0) temp=(left*(right_equal)%9901)%9901+((left%9901)*(2*sum_right%9901))%9901;
       //else temp=((left%9901)*(2*sum_right%9901))%9901;
       total_sum+=(left*(right_equal)%9901)%9901+((left%9901)*(2*sum_right%9901))%9901;
       //if (Levels==6) cout<<"--> "<<i<<" "<<cur_node-i<<" sum left "<<(left%9901)<<" Sum right "<<(sum_right%9901)%9901<<" Sum equal "<<temp<<endl;*/

     }
  Recurse_level--;
  bins[Nodes][Levels]=total_sum%9901;
  return total_sum%9901;
}

int main()
{
  ifstream fin("nocows.in");
  ofstream fout("nocows.out");
  int Nodes,Levels;
  fin>>Nodes>>Levels;
  for (int i=0;i<200;i++) for(int j=0;j<101;j++) bins[i][j]=-1;
  fout<<Bin(Levels,Nodes)<<endl;



    
}   
    
  

