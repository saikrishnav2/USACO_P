/* 
ID:svasude2
PROG:lamps
LANG:C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;
int LAMPS_ON[MAX_N+1];
int LAMPS_OFF[MAX_N+1];
int even[]={0,3,5,6,9,10,12,15};
int odd[]={1,2,4,7,8,11,13,14};
int LAMPS[MAX_N+1]={1};
int N;
char Char_Results[18][MAX_N+2];
int Result=0;
int count_ones(int number)
{
  int count=0;
  for (int i=0;i<4;i++)
    {
      if (number%2!=0) count++;
      number=number>>1;

    }
  return count;
}
int compare (const void * a, const void * b)
{
  const char* aa=(const char*) a;
  const char* bb=(const char*) b;

  for (int i=0;i<=N;i++)
    {
      
      if ((aa[i]=='1')&&(bb[i]=='0')) return 1;
      else if ((aa[i]=='0')&&(bb[i]=='1')) return -1;
    }
  return 0;
}
void Put_In_Array(void)
{
  int i=0;
  for (i=1;i<=N;i++)
    {
      Char_Results[Result][i-1]=48+LAMPS[i];
    }
  Char_Results[Result++][i-1]='\0';
}
void simulate(int number)
{
  /*
    - Button 1: When this button is pressed, all the lamps change their state: those that are ON are turned OFF and those that are OFF are turned ON.
    - Button 2: Changes the state of all the odd numbered lamps.
    - Button 3: Changes the state of all the even numbered lamps.
    - Button 4: Changes the state of the lamps whose number is of the form 3xK+1 (with K>=0), i.e., 1,4,7,...
  */
  for (int i=0;i<4;i++)
    {
      if (number%2!=0)
	{
	  if (i==0)
	    {
	      for (int j=1;j<N+1;j++)
		{
		  LAMPS[j]=abs(LAMPS[j]-1);
		}
	    }
	  else if (i==1)
	    {
	      for (int j=1;j<=N;j+=2)
		{
		  LAMPS[j]=abs(LAMPS[j]-1);
		}

	    }
	  else if (i==2)
	    {
	      for (int j=2;j<=N;j+=2)
		{
		  LAMPS[j]=abs(LAMPS[j]-1);
		}
	    }
	  else if (i==3)
	    {
	      for (int j=0;j<=N;j++)
		{
		  if ((3*j+1)<=N) LAMPS[3*j+1]=abs(LAMPS[3*j+1]-1);
		  else break;
		}
	    }


	}
      number=number>>1;

    }

}
void print(void)
{
  for (int i=1; i<=N;i++) cout<<LAMPS[i];
  cout<<endl;


}
void reinitialize(void)
{
  for (int i=0;i<N+1;i++)
    LAMPS[i]=1;
}
int main()
{

  ifstream fin("lamps.in");
  ofstream fout("lamps.out");
  int C;

  fin>>N>>C;
  int i=0;
  int temp=0;
  for (i=0;i<N;i++)
    {
      fin>>temp;
      if (temp==-1) break;
      LAMPS_ON[i]=temp;

    }
  int lamps_on=i;
  for (i=0;i<N;i++)
    {
      fin>>temp;
      if (temp==-1) break;
      LAMPS_OFF[i]=temp;
    }
  int lamps_off=i;
  int pp=0;
  int pq=0;
  //count only those which have number of ones <= N
  reinitialize();
  if (C%2==0) //even
    {
      for (int j=0;j<8;j++)
	{
	  if (count_ones(even[j])<=C)
	    {
	      simulate(even[j]);
	      //check if consistent with on lamps
	      for (pp=0;pp<lamps_on;pp++)
		{
		  if (LAMPS[LAMPS_ON[pp]]!=1) break;
		}
	      for (pq=0;pq<lamps_off;pq++)
		{
		  if (LAMPS[LAMPS_OFF[pq]]!=0) break;
		}
	      if ((pp==lamps_on)&&(pq==lamps_off)) {Put_In_Array();}
	      //reinitialize LAMPS
	      reinitialize();
	    }
	}
    }
  else
    {
      for (int j=0;j<8;j++)
	{
	  if (count_ones(odd[j])<=C)
	    {
	      //print();
	      simulate(odd[j]);
	      //check if consistent with on lamps
	      //cout<<odd[j]<<endl;
	      //print();
	      for (pp=0;pp<lamps_on;pp++)
		{
		  if (LAMPS[LAMPS_ON[pp]]!=1) break;
		}
	      for (pq=0;pq<lamps_off;pq++)
		{
		  if (LAMPS[LAMPS_OFF[pq]]!=0) break;
		}
	      if ((pp==lamps_on)&&(pq==lamps_off)) {Put_In_Array();}
	      //reinitialize LAMPS
		  reinitialize();
	    }
	}
      
    }
    
  
  qsort (Char_Results,18,sizeof(char)*102,compare);

  for (int i=0;i<Result;i++) fout<<Char_Results[i]<<endl;
  if (Result==0) fout<<"IMPOSSIBLE"<<endl;
}
