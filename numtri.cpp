/*
ID: svasude2
PROG: numtri
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#define ANS_MAX 500500
using namespace std;

short Tree[500500];
int already_computed[500500]={-1}; 
int Cost=0;
int Current_Cost=0;
int N;
int Max=0;
int Search(int level,int Pos)
{
  //cout<<"Cost: "<<Current_Cost<<"Level: "<<level<<" Pos: "<<Pos<<" Value:"<<Tree[Pos]<<endl;
  //for (int i=0;i<(N*(N+1)/2);i++) cout<<already_computed[i]<<" ";  cout<<endl;
    
  if (level==N) return 0;
  if  (already_computed[Pos]!=-1) return already_computed[Pos];
  else
    {
      already_computed[Pos]=Tree[Pos]+max(Search(level+1,Pos+level+1),Search(level+1,Pos+level+2));
      // cout<<max(Search(level+1,Pos+level+1),Search(level+1,Pos+level+2))<<"dummy"<<endl;
      level--;
      return already_computed[Pos];
    }

}
  

int main()
{

  ofstream fout("numtri.out");
  ifstream fin("numtri.in");
  fin>>N;
  
  for (int i=0;i<(N*(N+1)/2);i++){
    fin>>Tree[i];
    already_computed[i]=-1;
  }
  
  Cost= Search(0,0);

  fout<<Cost<<endl;
}
