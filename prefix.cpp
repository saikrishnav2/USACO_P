/* 
ID:svasude2
PROG:prefix
LANG:C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <deque>

//char sequence1[200001];
bool Next_Index[200001]={false};


using namespace std;
string Buffer;
string sequence;
string Primitives[200];
deque<int> myqueue;
int Index;
string Read;

int match(int prim_index,int s_index,int length,string& sequence)
{
  int i=0;
  //cout<<length<<endl;
  // cout<<s_index<<endl;
  for (i=s_index;(i<(s_index+length))&&(i<sequence.size());i++)
    {
      //cout<<Primitives[prim_index][i-s_index]<<" "<<sequence[i]<<endl;
      if (Primitives[prim_index][i-s_index]!=sequence[i])
	return s_index;
    }

  if ((i<=sequence.size())&&(i==(s_index+length))) return i;   
  else return s_index;
}
int get_next(string& sequence)
{
  for (int i=Index+1;i<sequence.size();i++)
    {
      if (Next_Index[i]) return i;
    }
  return -1;
}
int main()
{
  //FILE* fin = fopen ("prefix.in","r");
  ifstream fin("prefix.in");
  ofstream fout("prefix.out");
  //scan for a string until period
  int i=0;
  //sequence1[0]='\0';

  for (;;)
    {
      /* fscanf(fin,"%s",Read);
      if (strcmp(Read,".")==0) break;
      strcpy(Primitives[i++],Read);
      */
      fin>>Read;
      if (Read==".") break;
      Primitives[i++]=Read;
    }
  int len_prim=i;
  for (int j=0;j<i;j++)
    {
      // cout<<Primitives[j]<<endl;
    }
  //scan sequence
  for(;;)
    {
      getline(fin, Buffer);
      if (!fin.eof())
	{
	  sequence+=Buffer;
	}
      else break;
    }
  //  cout<<strlen(sequence)<<endl;
  // Algorithm
  int length=sequence.size();
  Next_Index[0]=true;
  // prev_index;
  myqueue.push_back(0);
  
  // cout<<sequence<<endl;
  //for (int i=0;i<len_prim;i++) cout<<Primitives[i]<<" ";
  //cout<<endl;
  int New_Index=0;
  while(myqueue.size())
    {
      //cout<<"Processing New Index"<<endl;
      Index=myqueue.front();
      myqueue.pop_front();
      //Next_Index[Index+1]=1;
      for (int prim=0;prim<len_prim;prim++)
	{
	  
	  if (Next_Index[Index+Primitives[prim].size()]) continue;

	  //New_Index=match(prim,Index,strlen(Primitives[prim]),sequence);
	  if (sequence.substr(Index,Primitives[prim].size())==Primitives[prim]){
	    New_Index=Index+Primitives[prim].size();
	    Next_Index[New_Index]=1;
	    myqueue.push_back(New_Index);
	  }
	}
    }
  
  fout<<Index<<endl;
}
