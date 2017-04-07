/*
ID: svasude42
PROG: beads
LANG: C++  
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");
  char* q=new char[352];
  int length;
  fin>>length;
  fin.ignore();
  fin.getline(q,351);
  char previous,previous1;
  int count=1;
  int max=0;
  previous=q[0];
  
  for (int i=1; i<strlen(q);i++)
    {
      
      if (q[i]==previous)
	{
	  //cout<<q[i];
	  count+=1;
	  previous=q[i];
	 
	}
      else if (q[i]==119)
	{
	  //cout<<q[i];
	  count+=1;
	}
      else if(previous==119)
	{
	  //cout<<q[i];
	  count+=1;
	  previous=q[i];
	}
       
			  
      else
	{
	  count+=1;
	  //cout<<endl; 
	  // cout<<"end"<<endl;
	  previous=q[i];
	  previous1=q[i];
	  int j=(i+1)%strlen(q);
	  while(true)	    
	      {
		//cout<<q[j];
		if (q[j]==previous1)
		  {
		    count+=1;
		    previous1=q[j];
		    
		  }
		else if (q[j]==119)
		  {
		    count+=1;
		  }
		else if(previous1==119)
		  {
		    count+=1;
		    previous1=q[i];
		  }
      
		else
		  {
		    // cout<<endl;
		    if(count>max)
		      {
			max=count;
			//cout<<"ending index: "<<j<<"count "<<count<<endl;
		      }
		    count=1;
		    //cout<<"start"<<endl;
		    int temp=i-1;
		    while(true)
		      {
			
			
			//cout<<"hi"<<endl;
			if((q[temp]==119) && temp>1)

			  {
			    //cout<<temp<<endl;
			    temp-=1;
			    count+=1;
	      
			  }
			else
			  {
			    break;
			  }
			
		      }
		    break;
		  }
		j=(j+1)%strlen(q);
	      }
	    
	
	}
    }
  if (count==strlen(q)) max=strlen(q);
  fout<<max<<endl;
  return 0;
}
