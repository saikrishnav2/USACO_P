/*
ID: svasude2
PROG: wormhole
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#define MAX_N 12
int Partner[MAX_N+1]={0};
int X[MAX_N+1];
int Visited[MAX_N+1];// 0: never visited,1: in, 2: out;
int Y[MAX_N+1];
int N;
int cycles;
using namespace std;
void print_pairing(void);
int check_cycle(int i,int start)
{
  
  //start from each point and check for point on the same Y value as the current point.
  
  int j;
  int lowest=-1;
  int found_j=-1;
  for (j=1;j<=N;j++)
    {
      
      if ((Y[i]==Y[j]) && (i!=j) && (X[j]>X[i]))
	{
	  if (lowest==-1) {lowest=X[j];found_j=j;}
	  else if (X[j]<lowest) {lowest=X[j];found_j=j;}
	}
      
    }
  if (found_j==-1) return 0;
  j=found_j;
  //search for the point's partner, check if it is visited ,if yes, cycle exists.
  if (Visited[i]==2){
    //   cout<<"Exists"<<endl;
    //print_pairing();
    return 1;
  }
  if (Visited[j]==1){
    //cout<<"Exists"<<endl;
    //print_pairing();
    return 1;
  }
  else Visited[j]=1;
  
  if (!start) Visited[i]=2;
  
  //cout<<"("<<X[i]<<","<<Y[i]<<")"<<"-->"<<"("<<X[j]<<","<<Y[j]<<")"<<"\n ";
  return check_cycle(Partner[j],0);
  
}
void print_pairing(void)
{

    for (int i=1;i<=N;i++) cout<<i<<":"<<Partner[i]<<" ";
      //cout<<"("<<X[i]<<","<<Y[i]<<")"<<":"<<"("<<X[Partner[i]]<<","<<Y[Partner[i]]<<")"<<" ";
  cout<<endl;


}
int solve()
{
  //Find first unpaired point;
  int i;
  for(i=1;i<=N;i++)
    {
     
      if (Partner[i]==0) break;
    }
  //Base Case
  if (i==N+1)
    {
      
      //    print_pairing();
      for (int q=1;q<=N;q++)
	{
	  int result=check_cycle(q,1);
	  for (int clean=1;clean<=N;clean++) Visited[clean]=0;

	  
	  if (result) {cycles++; break;};
	 
	  

	}
      //     cout<<"----------------------------------------------------------------"<<endl;
      return 0;
    }
  //Find another unpaired point to pair with 
  for (int j=i+1;j<=N;j++)
    {
      if (Partner[j]==0)
	{
	  Partner[i]=j;
	  Partner[j]=i;
	  //cout<<"dsa";
	  solve();
	  
	  Partner[i]=Partner[j]=0;
	}
    }
}

int main() {
  ofstream fout ("wormhole.out");
  ifstream fin ("wormhole.in");
  fin>>N;
  
  int i;
  for (i=1;i<=N;i=i+1){
    fin>>X[i]>>Y[i];
  }
  // cout<<N<<endl;
  solve();
  fout<<cycles<<endl;
}
