/*
ID:svasude2
PROG:subset
LANG:C++
*/
#include <stdio.h>
#include <fstream>
#include <iostream>
#define MAX_M 410
using namespace std;

int main()
{
  ofstream fout("subset.out");
  ifstream fin("subset.in");
  int N,M;
  fin>>N;
  M=N*(N+1)/2;
  long long Matrix[MAX_M][MAX_M];
  if (M%2!=0) {fout<<0<<endl;return 0;}
  M=M/2;
  Matrix[0][0]=1; // Empty set and sum =0
  for(int k=1;k<=M;k++) {Matrix[0][k]=0;Matrix[k][0]=1;}
  for (int i=1;i<=N;i++)
    {
      for (int j=1;j<=M;j++)
	{
	  if (j<i) Matrix[i][j]=Matrix[i-1][j];
	  else if (j>=i) Matrix[i][j]=Matrix[i-1][j-i]+Matrix[i-1][j];
	  // cout<<i<<" "<<j<<": "<<Matrix[i][j]<<endl;
	}
    }
  fout<<Matrix[N][M]/2<<endl;
}
