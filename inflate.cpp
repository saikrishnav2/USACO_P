/* 
ID:svasude2
PROG:inflate
LANG:C++
*/

#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
int Points[10000];
int Time[10000];
long long Max_Points[10001];

int Minimum_Time=99999;
long long Maximum_Points=0;
int Current_Time=0;
int Current_Points=0;
int M,N;
void dfs(int);
int main()
{
  ifstream fin("inflate.in");
  ofstream fout("inflate.out");
 
  fin>>M>>N;
  for (int i=0;i<N;i++)
    {
      fin>>Points[i]>>Time[i];
      //  cout<<Points[i]<<" "<<Time[i]<<endl;
    }
  //dfs through all the posibilities
  //dfs(M);
  for (int i=0;i<=M;i++)
    {
      Max_Points[i]=0;
    }
  //Max_Points[0]=0;
  for (int i=0;i<=M;i++)
    {
      for (int j=0;j<N;j++)
	{
	  if (i-Time[j]>=0)
	    {
	      if (Max_Points[i]<(Max_Points[i-Time[j]]+Points[j]))
		{
		  
		  Max_Points[i]=Max_Points[i-Time[j]]+Points[j];
		  
		}

	    }
	}
    }

  //cout<<"Minimum Time: "<<Minimum_Time<<endl;
  fout<<Max_Points[M]<<endl;
}

void dfs(int time)
{
  //cout<<time<<" "<<Current_Points<<endl;
  if (time<=0)
    {
      
      if (Current_Points>Maximum_Points)
	{
	  Maximum_Points=Current_Points;
	  cout <<"Points: "<<Maximum_Points<<endl;
	}
      return;
    }
  else
    {
      for (int i=0;i<N;i++)
	{
	  
	  int flag=0;
	  if (time-Time[i]>=0)
	    {
	      flag=1;
	      Current_Points+=Points[i];
	      Current_Time+=Time[i];
	    }
	  dfs(time-Time[i]);
	  if (flag)
	    {
	      Current_Time-=Time[i];
	      Current_Points-=Points[i];
	    }
	}
    }
}
