/*
ID:svasude4
PROG:fracdec
LANG:C++
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  /*Pseudocode:
    Given N/D

    If Divide N/D
    For Ex: 1/7
    if (N<D)
    Multiply by 10 so that N>D
    Treat digits before decimal point differently than the digits after the decimal point.

    1/7->N<D  So N*10/D 10/7=1
    30/7->4
    20/7->2
    60/7->8
    40/7->5
    50/7->7
    1/7
    Add Quotient to visited nodes
    401/200
    
  */
  
  ifstream fin("fracdec.in");
  ofstream fout("fracdec.out");
  int N,D;
  fin>>N>>D;
  int TempN;
  int count=0;
  char Result[10000000];
  char Rep[2];
  bool Visited[1000000];
  
  for (int i=0;i<1000000;i++) Visited[i]=0;
  int pos=0;
  TempN=N;
  int print_brac=-1;
  int first=1;
  int pos_dot=0;
  int Repeat=0;
  if (TempN<D) sprintf (&Result[pos++], "0");
  while(TempN)
    {
      
      if (TempN<D)
	{
	  count=0;
	  while(TempN<D) {count++; TempN*=10;}
	  //cout<<"TempN "<<TempN<<endl;
	  if (first) {
	    pos_dot=pos;
	    sprintf (&Result[pos++], ".");
	    first=0;
	  }
	  for (int i=0;i<(count-1);i++)
	    {
	      //  cout<<"yo"<<endl;
	      sprintf (&Result[pos++], "0");
	    } 
	  if (Visited[TempN]==1) {Repeat=1;break;}
	   Visited[TempN]=1;
	  sprintf(&Result[pos++],"%d",TempN/D);
	  //	  cout<<TempN/D<<endl;
	  TempN=TempN%D;
	  if (TempN==0) break;
	}
      else
	{
	  int g=TempN/D;
	  int c=0;
	  while(g)
	    {
	      g/=10;
	      c++;
	    }
	  sprintf(&Result[pos],"%d",TempN/D);
	  pos+=c;

	  //	  cout<<Result<<" "<<TempN/D<<endl;
	  TempN=TempN%D;
	}
    }
  
  if (Repeat)
    {
      sprintf(Rep,"%d",TempN/D);
      //count order
      int g=TempN;
      int c=0;
      while(g)
	{
	  g/=10;
	  c++;
	}
      for (int i=pos_dot+1;i<pos;i++)
	{
	  if (Rep[0]==Result[i]) {print_brac=i-count+1;break;}
	  
	}
      if (print_brac<pos_dot+1) print_brac=pos_dot+1;
    }
  int p=0;
  int i;
  int flag=1;
  
  cout<<TempN<<endl;
  for (i=0;i<pos;i++)
    {
      if ((p!=0)&&(p%76==0)) fout<<"\n"; 
      if (print_brac>=0) {
	if (print_brac==i)
	  {
	    fout<<"(";
	    p++;
	  }
      }
      
      fout<<Result[i];
      p++;
      if ((i==pos-count+1) && (print_brac>=0)) {fout<<")";flag=0;break;}
    }
  if ((i==pos-count+1) && (print_brac>=0)&&(flag)) {fout<<")";}
  if (pos_dot==0) fout<<".0";
  fout<<endl;
}
