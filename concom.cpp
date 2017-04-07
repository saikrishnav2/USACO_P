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
int Result[101][101]={0};
int visited[101]={0};
void find(int j)
{
  // if (j==2) cout<<"gsf"<<endl;
  //cout<<j<<" "<<endl;
  if (visited[j]) return ;
  //cout<<j<<endl;
  visited[j]=1;
  int sum=0;
  queue<int> nodes;
  for (int pp=1;pp<=100;pp++)
	{
	  if (Dup_Companies[j][pp]>50)
	    {
	      if (j!=pp) nodes.push(pp);
	    }
	}
  while(nodes.size())
    {
      int node=nodes.front();
      //     if (node==4) break;
      nodes.pop();
      find(node);
      //if (j==37)
      //{
      //  for(int g=1;g<=100;g++) cout<<"g: "<<g<<" "<<Companies[37][g]<<" "<<node<<endl;
	  
      //  }
      for (int pp=1;pp<=100;pp++)
	{
	  int temp=Dup_Companies[j][pp]+Dup_Companies[node][pp];
	  //if ((pp==2)&&(j==1)) cout<<j<<" "<<pp<<" "<<temp<<" "<<node<<endl;
	  if ((temp>50) && (Dup_Companies[j][pp]<=50)&& (Dup_Companies[node][pp]<=50))
	    {
	      // cout<<"Added: "<<j<<" "<<pp<<" "<<temp<<endl;
	      if ((j!=pp)) nodes.push(pp);
	    }
	  Dup_Companies[j][pp]=temp;
	  //Companies[j][pp]+=Companies[node][pp];
	}


    }
  
}
//2 86 62 31 75 78 95 63 50 80 47 81 71 13 39 26 44 14 59 90 19 34 6 27 79 40 77 9 33 29 53 18 76 98 3 8 5  1 35 43 46 30 38 12 51 17 64 41 67 82 57 73 70 61 61 92 28 74 23 54 55 22 21 97 49 42 99 65 84 96 56 68 68 89 36 20 32 52 72 10 93 83 91 37 60 66 100 16 48 11 25 85 7 94 45 69 4




// 1 35 43 46 30 38 12 51 17 64 41 67 82 57 73 70 61 61 92 28 74 23 54 55 22 21 97 49 42 99 65 84 96 56 68 68 89 36 20 32 52 72 10 93 83 91 37 60 66 100 16 48 11 25 85 7 94 45 69 4
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
	  Dup_Companies[i][j]=0;
	}
    }
  for(int i=0;i<N;i++)
    {
      fin>>from>>to>>percentage;
      Companies[from][to]=percentage;
      //    if (to==1) cout<<from<<" "<<to<<" "<<percentage<<endl;
      Dup_Companies[from][to]=percentage;
    }


  //Algorithm
  //for (int i=1;i<=100;i++) if find(i);
  //find(1);
  for(int t=1;t<=100;t++)
    {
      // cout<<"86 "<<" "<<i<<" "<<Companies[86][i]<<endl;
      find(t);
      for  (int jj=1;jj<=100;jj++) Result[t][jj]=Dup_Companies[t][jj];
      for(int i =1;i<=100;i++)
	{
	  visited[i]=0;
	  for (int j=1;j<=100;j++)
	    {
	      // Companies[i][j]=0;
	      
	      Dup_Companies[i][j]=Companies[i][j];
	    }
	}
    }
  
  //  for(int i=1;i<=100;i++) cout<<"2 "<<" "<<i<<" "<<Result[2][i]<<endl;
  //find(2);
  
  for(int i=1;i<=100;i++)
    {
      for (int j=1;j<=100;j++)
	{
	  if (Result[i][j]>50) if (i!=j) {fout<<i<<" "<<j<<endl;}
	}
    }
  
}
	 
