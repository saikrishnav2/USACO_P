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
int Minimum_Time=99999;
int Maximum_Points=99999;
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
      cout<<Points[i]<<" "<<Time[i]<<endl;
    }
  //dfs through all the posibilities
  dfs(M);
  cout<<"Minimum Time: "<<Minimum_Time<<endl;
  cout<<"Maximum Points: "<<Maximum_Points<<endl;
  

}
void dfs(int points)
{
  cout<<points<<endl;
  if (points<0)
    {
      if (Current_Time<Minimum_Time)
	{
	  Minimum_Time=Current_Time;
	}
      return;
    }
  else
    {
      for (int i=0;i<N;i++)
	{
	  Current_Time+=Time[i];
	  int flag=0;
	  if (points-Points[i]>=0)
	    {
	      flag=1;
	      Current_Points+=Points[i];
	    }
	  dfs(points-Points[i]);
	  if (flag)
	    Current_Points-=Points[i];
	  Current_Time-=Time[i];
	}
    }
}
