/*
ID: svasude42
PROG: gift1
LANG: C++  
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");
  int N;
  fin>>N;
  fin.ignore();
  int* Array=new int[N];
  char** Names=new char*[N]; 
  for(int p=0;p<N;p++)
    {
      Names[p]=new char[15];
      fin.getline(Names[p],15);
      Array[p]=0;
      // cout<<Names[i]<<endl;
    }
  int Amount=0;
  int Split=0;
  int remainder=0;
  int eq=0;
  char* to=new char[15];
  for(int i=0;i<N;i++)
    {
      //fin.ignore(15,'\n');
      //fin.ignore();
      fin.getline(to,15);
      fin>>Amount>>Split;
      // cout<<Amount<<" "<<Split<<endl;
      fin.ignore();
      if (Split!=0) remainder=Amount%Split;
      else remainder=0;
      if (Split!=0)   eq=Amount/Split;
      else eq=0;
      for(int q=0;q<N;q++)
	    {
	      if (strcmp(Names[q],to)==0)
		{
		  
		  Array[q]-=Amount-remainder;
		  break;
		}
	    }
      
      
      for (int j=0;j<Split;j++)
	{
	  fin.getline(to,15);
	  for(int k=0;k<N;k++)
	    {
	      if (strcmp(Names[k],to)==0)
		{
		  Array[k]+=eq;
		  break;
		}
	    }
	}
      /* for(int l=0;l<N;l++)
	{
	  
	  cout<<Names[l]<<" "<<Array[l]<<endl;
	  }*/
      
    }
  for(int l=0;l<N;l++)
    {
      
      fout<<Names[l]<<" "<<Array[l]<<endl;
    }
  
  return 0;
}
