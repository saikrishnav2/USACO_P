/*
ID:svasude2
PROG:concom
LANG:C++
*/
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;
int Companies[101][101]={0};
int Dup_Companies[101][101]={0};
int visited[101]={0};
void find(int j)
{
  //cout<<j<<" "<<kk<<endl;
  if (visited[j]) return ;
  //cout<<j<<endl;
  visited[j]=1;
  int sum=0;
  queue<int> nodes;
  for (int pp=1;pp<=100;pp++)
	{
	  if (Companies[j][pp]>50)
	    {
	      if (j!=pp) nodes.push(pp);
	    }
	}
  while(nodes.size())
    {
      int node=nodes.front();
      nodes.pop();
      find(node);
      //if (j==37)
      //{
      //  for(int g=1;g<=100;g++) cout<<"g: "<<g<<" "<<Companies[37][g]<<" "<<node<<endl;
	  
      //  }
      for (int pp=1;pp<=100;pp++)
	{
	  int temp=Companies[j][pp]+Companies[node][pp];
	  //if ((pp==2)&&(j==1)) cout<<j<<" "<<pp<<" "<<temp<<" "<<node<<endl;
	  if ((temp>50) && (Companies[j][pp]<=50)&& (Companies[node][pp]<=50))
	    {
	      // cout<<"Added: "<<j<<" "<<pp<<" "<<temp<<endl;
	      if ((j!=pp)) nodes.push(pp);
	    }
	  Companies[j][pp]=temp;
	  //Companies[j][pp]+=Companies[node][pp];
	}


    }
  
}

int main()
{
  int N;
  int from,to,percentage;
  ifstream fin("concom.in");
  ofstream fout("concom.out");
  fin>>N;
  for(int i=0;i<=100;i++)
    {
      visited[i]=0;
      for (int j=0;j<=100;j++)
	{
	  Companies[i][j]=0;
	  //	  Dup_Companies[i][j]=0;
	}
    }
  for(int i=0;i<N;i++)
    {
      fin>>from>>to>>percentage;
      Companies[from][to]=percentage;
      if (to==1) cout<<from<<" "<<to<<" "<<percentage<<endl;
      //Dup_Companies[from][to]=percentage;
    }


  //Algorithm
  for (int i=1;i<=100;i++) if (!visited[i])  find(i);
  for(int i=1;i<=100;i++)
    {
      for (int j=1;j<=100;j++)
	{
	  if (Companies[i][j]>50) if (i!=j) fout<<i<<" "<<j<<endl;
	}
    }
  
}
	 
