/*
ID:svasude42
PROG: milk2
LANG: C++  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");
  int minstart,maxend,maxgap;
  int gap;
  int a,b,t;
  fin>>t;
  int max_ans1=0;
  maxgap=0;
  int sorted_minstart[5000];
  int sorted_maxend[5000];
  //insertion sort
  for(int i=0;i<t;i++)
    {
      
      fin >> a >> b;
      if (i==0)
	{
	  sorted_minstart[0]=a;
	  sorted_maxend[0]=b;
	}
      else
	{
	  for (int j=0;j<i;j++)
	    {
	      if (a>=sorted_minstart[j])
		{
		  if (j+1==i)
		    {
		      sorted_minstart[i]=a;
		      sorted_maxend[i]=b;
		      break;
		    }
		  else if (a<=sorted_minstart[j+1])
		    {
		      for (int p=i;p>j+1;p--)
			{
			  sorted_minstart[p]=sorted_minstart[p-1];
			  sorted_maxend[p]=sorted_maxend[p-1];
			}
		      sorted_minstart[j+1]=a;
		      sorted_maxend[j+1]=b;
		      break;
		    }
		  
		}
	      else if (a<=sorted_minstart[j])
		{
		  for (int p=i;p>j;p--)
			{
			  //cout<<p<<endl;
			  sorted_minstart[p]=sorted_minstart[p-1];
			  sorted_maxend[p]=sorted_maxend[p-1];
			}
		  sorted_minstart[j]=a;
		  sorted_maxend[j]=b;
		  break;
		}
	      
	    }

	}

       

    }
  /*for(int q=0;q<t;q++)
    {
      cout<<sorted_minstart[q]<<" ";
    }
  cout<<endl;
  for(int o=0;o<t;o++)
    {
      cout<<sorted_maxend[o]<<" ";
    }
    cout<<endl;*/

  for(int i=0;i<t;i++)
    {
      if (i==0) {
	minstart=sorted_minstart[0];
	maxend=sorted_maxend[0];
	max_ans1=maxend-minstart;
      }
      else
	{
	  a=sorted_minstart[i];
	  b=sorted_maxend[i];

	  
	  if (a>=minstart && a<=maxend && b>=maxend)
	    {
	      maxend=b;
	    }
	  else if (a>maxend)
	    {
	      gap=a-maxend;
	      //cout<<gap<<endl;
	      if ((maxend-minstart)>max_ans1)
		{
		  max_ans1=maxend-minstart;
		  
		  
		}
	      if (gap>maxgap) maxgap=gap;
	      minstart=a;
	      maxend=b;

	    }

	}
      
    }
  fout << max_ans1 <<" "<<maxgap<< endl;
  return 0;
}
