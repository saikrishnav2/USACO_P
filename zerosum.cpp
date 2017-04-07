/*
ID: svasude2
PROG: zerosum
LANG:C++
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
using namespace std;

char operators[11]={0};
char dup_operators[11]={0};
int num[11]={0};
char results[19683][11];
int ascii_sums[19683]={0};
int ascii_sum=0;
//43: '+', 45: '-'
int count=-1;
int N;
int result=0;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

void dfs(void)
{
  //cout<<ascii_sum<<endl;
  if (count==N-2)
    {
      ascii_sums[result]=ascii_sum;
      for (int i=0;i<=count;i++)
	{
	  results[result][i]=operators[i];
	  // cout<<(int) operators[i]<<" ";
	}
      //cout<<ascii_sums[result]<<endl;
      result++;
    }
  else
    {  
      count++;
      operators[count]=' ';
      dfs();
      operators[count]='+';
      ascii_sum+=43;
      dfs();
      ascii_sum-=43;
      operators[count]='-';
      ascii_sum+=45;
      dfs();
      ascii_sum-=45;
      count--;
    }


}
int group(void)
{
  int start_index=0;
  int end_index=0;
  char prev=dup_operators[0];
  int count=0;
  
  
  int temp=1;
  if (prev!=' ') {num[count++]=1;start_index=1;temp=2;}
  for (int i=1;i<=N-1;i++)
    {
      
      if ((dup_operators[i]==' ')&&(prev==' ')) continue;
      if ((dup_operators[i]==' ')&&(prev!=' ')) start_index=i;

      else
	{
	  end_index=i-1;
	  for (int j=start_index;j<=end_index;j++)
	    {
	      temp=temp*10+j+2;
	    }
	  num[count++]=temp;
	  start_index=i+1;
	  temp=start_index+1;
	}
      prev=dup_operators[i];
    }
  return count;
  
  
}
int count_digits(int temp)
{
  int count=0;
  while(temp!=0)
    {
      count++;
      temp/=10;
    }
  return count;
}
void evaluate(void)
{

  /* for example:
     N=3
     result=9
  */
  for (int i=0;i<result;i++)
    {
      int operator_count=0;
      
      for (int kk=0;kk<N-1;kk++) dup_operators[kk]=results[i][kk];
      dup_operators[N-1]=-1;
      operator_count=group();
      //cout<<" Num ";
      //for (int kk=0;kk<N-1;kk++) dup_operators[kk]=results[i][kk];
      //for (int kk=0;kk<operator_count;kk++) cout<<num[kk]<<" ";
      //cout<<endl;
      long temp=num[0];
      int count=1;
      for (int j=0;j<N-1;j++)
	{
	  if (results[i][j]=='+')
	    temp=temp+num[count++];
	  else if (results[i][j]=='-')
	    temp=temp-num[count++];
	  
	}
      //      cout<<i<<" "<<temp<<endl;
      if (temp==0)
	{
	  int pp=0;
	  for (pp=0;pp<N-1;pp++)
	    {
	      if (results[i][pp]==' ')
		fout<<pp+1<<" ";
	      else
		fout<<pp+1<<results[i][pp];
	    }
	  fout<<pp+1<<endl;
	  
	}
    }
}

int main()
{
   fin>>N;
  dfs();
  //evaluate expression and check if sum is 0
  evaluate();

}
