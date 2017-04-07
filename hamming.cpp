/*
ID:svasude2
PROG:hamming
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#define MAX_N 64
using namespace std;
int current_list[MAX_N]={0};
int N,B,D;
int hamming(int number,int distance,int count)
{
  
  if (count==0) return 1;
  else if (count>=64) return 0;
  else
    {
      for (int i=0;i<count;i++)
	{
	  int XOR=number^current_list[i];//bitwise xor
	  int temp=0;
	  //cout<<"Count: Number "<<count<<" "<<number<<endl;
	  for(int j=0;j<B;j++)
	    {
	      if (XOR%2==1) temp++;
	      XOR=XOR>>1;
	    }
	  //cout<<"Temp: "<<temp<<endl;
	  if (!(temp>=D)) return 0; 

	}
      return 1;
    }

}

int main()
{

  ifstream fin ("hamming.in");
  ofstream fout ("hamming.out");
  
  fin>>N>>B>>D;
  int Max=(int) pow(2,B);
  int count=0;
  for (int i=0;i<Max;i++)
    {
      count=0;
      for (int j=i;j<Max;j++) {
	if (hamming(j,D,count)){
	  
	  current_list[count++]=j;
	}
      }
      
     if (count>=N) break;
     	//cout<<endl;
    }
  for (int ll=0;ll<N;ll++){
    if ((ll%10==0)&&ll!=0) fout<<endl<<current_list[ll]<<" ";
    else if (((ll+1)%10==0)||(ll==N-1)) fout<<current_list[ll];
    else fout<<current_list[ll]<<" ";
  }
  fout<<endl;




}









  
