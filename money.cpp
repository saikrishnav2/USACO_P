/*
ID:svasude2
PROG:money
LANG:C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
long long table[10001][26]={0};
int coins[26]={0};
using namespace std;  
int main()
{

  ifstream fin("money.in");
  ofstream fout("money.out");
  int N,money;
  fin>>N>>money;
  for (int pp=1;pp<=N;pp++) fin>>coins[pp];
  
  for (int i=0;i<=N;i++) table[0][i]=1;
  for (int k=1;k<=money;k++) table[k][0]=0;
  //cout<<endl;
  for (int j=1;j<=money;j++)
    for(int i=1;i<=N;i++)
      {
  	{
	  if (j-coins[i]<0){
	    // cout<<j<<" "<<i<<" "<<endl;
	    table[j][i]=table[j][i-1];

	  }
	  //use this coin
	  else table[j][i]=table[j-coins[i]][i]+table[j][i-1];

	}
    }
  /*for (int j=1;j<=money;j++)
    {
      for(int i=1;i<=N;i++)
	{
	  cout<<table[j][i]<<" ";
	}
      cout<<endl;
      }*/
  fout<<table[money][N]<<endl;
}
