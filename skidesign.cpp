/*
ID: svasude2
PROG: skidesign
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#define MAX_N 1000
using namespace std;
struct hill{
  int Elevation;
  int Visited;
};
struct hill Hills[MAX_N+1]={0};
int N;
int compare (const void * a, const void * b)
{
  hill *A = (hill *)a;
  hill *B = (hill *)b;
  
  return ( A->Elevation - B->Elevation );
}

int main() {
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");
  fin>>N;
  for (int i=1;i<=N;i++){
    fin>>Hills[i].Elevation;
    Hills[i].Visited=0;
  }
  qsort(Hills,N+1,sizeof(hill),compare);
  //for (int j=1;j<=N;j++) cout<<Hills[j].Elevation<<" ";
  //cout<<endl;
  int largest=Hills[N].Elevation;
  int smallest=Hills[1].Elevation;
  
  int cost=0;
  int left,right,middle;
  int ans=0;
  for (int i=1;i<=83;i++)
    {
      int temp=0;
      for(int j=1;j<=N;j++)
	{
	  if (Hills[j].Elevation<i) {
	    temp+=(i-Hills[j].Elevation)*(i-Hills[j].Elevation);
	    //if (i==4) cout<<temp<<endl;
	  }
	  else if (Hills[j].Elevation>(i+17)) {
	    temp+= (Hills[j].Elevation-i-17)*(Hills[j].Elevation-i-17);
	    //if (i==4) cout<<temp<<endl;
	  }
	}
      if (i==1) ans=temp;
      else if (ans>temp) ans=temp;
      // cout<<i<<":"<<i+17<<" "<<temp<<endl;
    }
  
  fout<<ans<<endl;
  /*


   */  

}
