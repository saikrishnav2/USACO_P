/*
ID: svasude2
PROG: barn1
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");
  int M,S,C;
  fin>>M>>S>>C;
  int gaps[49][3]={0};//0: gap amount 1: start stall 2: end stall
  int prev,New,temp,start,end;
  int cows[201];
  for(int i=0;i<C;i++)
    {
      fin >> New;
      cows[i]=New;
      
    }
  //sort cows array;
  
  for (int j=0;j<C-1;j++)
    {
      for(int i=0;i<C-1;i++)
	{
	  if (cows[i]>cows[i+1])
	    {
	      int temp1=cows[i+1];
	      cows[i+1]=cows[i];
	      cows[i]=temp1;
	    }
	}
    }
  /*for(int q=0;q<C;q++)
    {
      cout<<cows[q]<<endl;
    }
    cout<<"Cows Array"<<endl;*/

  //calculate gaps between each cow stall and keep track of maximum M-1 Gaps.
  int lowest=0;
  int count=0;
  for (int i=0;i<C;i++)
    {
      if (i==0)
	{
	  prev=cows[0];
	  continue;
	}
      else
	{
	  /*if (i==17)
	    {
	      
	      for(int q=M-2;q>=0;q--)
		{
		  cout<<gaps[q][0]-1<<endl;
		}
	      cout<<"Done"<<endl;
	      }*/

	  New=cows[i];
	  temp=New-prev;
	  //cout<<temp<<endl;
	  if ((temp>lowest))
	    {
	      gaps[0][0]=temp;
	      gaps[0][1]=prev;
	      gaps[0][2]=New;
	      count++;
	    }
	  /*else if ((count>=M-2)&&(temp>=lowest))
	    {
	      //replace lowest entry with the current one
	      gaps[0][0]=temp;
	      gaps[0][1]=prev;
	      gaps[0][2]=New;
	      }*/
	  //cout<<gaps[0][0]<<" "<<gaps[0][1]<<" "<<gaps[0][2]<<" temp:  "<<temp<<" lowest: "<<lowest<<" Count: "<<count<<endl;
	}
      //sort according to gaps
      /*cout<<"i:  "<<i<<endl;
       for(int q=0;q<M-1;q++)
	 {
	   cout<<gaps[q][0]-1<<" "<<gaps[q][1]<<" "<<gaps[q][2]<<endl;
	   }*/
      // cout<<"Done"<<endl;
      for (int j=0;j<M-2;j++)
	{
	  for(int i=0;i<M-2;i++)
	    {
	      if (gaps[i][0]>gaps[i+1][0])
		{
		  int temp1=gaps[i+1][1];
		  gaps[i+1][1]=gaps[i][1];
		  gaps[i][1]=temp1;
		      
		  temp1=gaps[i+1][2];
		  gaps[i+1][2]=gaps[i][2];
		  gaps[i][2]=temp1;
		      
		  temp1=gaps[i+1][0];
		  gaps[i+1][0]=gaps[i][0];
		  gaps[i][0]=temp1;
		}
	    }
	}
      
	
	 
	
      lowest=gaps[0][0];
      prev=New;
    }
  
  //sort according to starting stall numbers
  for (int j=0;j<M-2;j++)
	{
	  for(int i=0;i<M-2;i++)
	    {
	      if (gaps[i][1]>gaps[i+1][1])
		{
		  int temp1=gaps[i+1][1];
		  gaps[i+1][1]=gaps[i][1];
		  gaps[i][1]=temp1;
		      
		  temp1=gaps[i+1][2];
		  gaps[i+1][2]=gaps[i][2];
		  gaps[i][2]=temp1;
		      
		  temp1=gaps[i+1][0];
		  gaps[i+1][0]=gaps[i][0];
		  gaps[i][0]=temp1;
		}
	    }
	}
  
  /*for(int q=0;q<M-1;q++)
    {
      cout<<gaps[q][0]<<" "<<gaps[q][1]<<" "<<gaps[q][2]<<endl;
    }
    cout<<"Done"<<endl;*/

  int ans =0;
  start=cows[0];
  end=cows[C-1];
  //count stalls not covered

  for (int j=0;j<M-1;j++)
    {
      ans+=gaps[j][2]-gaps[j][1]-1;
    }
  ans+=S-end;
  ans+=start-1;
  
  
  //cout<<ans<<endl;
  ans=S-ans;
  if (M>=C) fout<<C<<endl;
  else if (M!=1) fout<<ans<<endl;
  else fout<<end-start+1<<endl;    
}

