/* 
ID: svasude4
PROG: contact
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
char input[200001];
int counter[13][4097];
char temp[13];

int bin2dec(int start,int length, char* str )
{
  int po=1;
  int result=0;
  for (int i=start+length-1;i>=start;i--)
    {
      result+=(str[i]-48)*po;
      po*=2;
    }
  return result;
}
char* dec2bin(int dec,int length)
{
  
  int len=0;
  temp[length]='\0';
  while (dec>0)
    {
      temp[length-1-len]=dec%2+48;
      dec/=2;
      len++;
    }
  for (int i=0;i<(length-len);i++)
    {
      temp[i]='0';
    }
  return temp;
}

int main()
{
  //cout<<dec2bin(0,7)<<endl;
  ifstream fin("contact.in");
  ofstream fout("contact.out");
  int A,B,N;
  char temp1[81];
  fin>>A>>B>>N;
  fin>>input;
  int powers[13]={1,2,4,8,16,32,64,128,256,512,1024,2096,4096};
  
  while (true)
    {
      // cout<<"gh"<<endl;
      fin>>temp1;
      if (fin.eof()) break;
      strcat(input,temp1);

    }
  
  //cout<<"input: "<<input<<endl;
  for (int i=A;i<=B;i++)
    {
      for (int j=0;j<powers[i];j++)
	{
	  counter[i][j]=0;
	}
    }

  for (int i=0;i<strlen(input);i++)
    {
      for (int j=A;j<=B;j++)
	{
	  if ((i+j)<=strlen(input))
	    {
	      int re=bin2dec(i,j,input);
	      counter[j][re]++;
	    }
	}
    }
  
  int counts[50];
  int index=0;
  int full=0;
  int min_index;
  int min;
  for (int i=0;i<50;i++)
    {
      counts[i]=0;
    }
  for (int i=A;i<=B;i++)
    {
      for (int j=0;j<powers[i];j++)
	{
	  
	  if (full)
	    {
	      if (counter[i][j]>min)
		{
		  int flag=0;
		  for (int o=0;o<N;o++)
		    {
		      if (counts[o]==counter[i][j]) flag=1 ;
		    }
		  if (flag) continue;
	      
		  counts[min_index]=counter[i][j];
		  min=99999999;
		  for (int p=0;p<N;p++)
		    {
		      if (counts[p]<min) {min=counts[p];min_index=p;}
		    }
		}
	    }
	  else
	    {
	      int flag=0;
	      for (int o=0;o<N;o++)
		{
		  if (counts[o]==counter[i][j]) flag=1 ;
		}
	      if (flag) continue;
	      
	      counts[index++]=counter[i][j];
	      //cout<<"index: "<<index<<endl;
	      if (index==N)
		{
		  full=1;
		  min=99999999;
		  for (int p=0;p<N;p++)
		    {
		      if (counts[p]<min) {min=counts[p];min_index=p;}
		    }
		}
	    }
	}
    }
  sort(counts,counts+N);
  //  for (int i=N-1;i>=0;i--) cout<<counts[i]<<" ";
  cout<<endl;
  for (int p=N-1;p>=0;p--)
    {
      if (counts[p])
      {
	fout<<counts[p]<<endl;
	int fl=0;
	int pattern_count=0;
	for (int i=A;i<=B;i++)
	  {
	    for (int j=0;j<(int) pow(2,i);j++)
	      {
	      
		if (counts[p]==counter[i][j])
		  {
		  
		    if (fl)
		      {
			if (pattern_count%6) fout<<" "<<dec2bin(j,i);
			else fout<<"\n"<<dec2bin(j,i);
			 
		      }
		    else
		      {
			fout<<dec2bin(j,i);
			fl=1;
		      }
		    pattern_count++;
		  }
	      }
	  }
      fout<<endl;
      }
    }
  //  cout<<endl;
  //cout<<dec2bin(3,4)<<endl;
  //cout<<min_index<<endl;
}
