/*
ID:svasude4
PROG:milk
LANG: C++      
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;
int main() {
  ofstream fout ("milk.out");
  ifstream fin ("milk.in");
  int total_units=0;int N_farm=0;
  fin>>total_units>>N_farm;
  int* cents= new int [N_farm];
  int* units= new int [N_farm];
  int* sorted_mincents=new int [N_farm];
  int* sorted_maxunits=new int [N_farm];
  for (int i=0;i<N_farm;i++)
    {
      fin>>cents[i]>>units[i];
      // cout<<cents[i]<<" "<<units[i]<<endl;
      int a=cents[i];
      int b=units[i];
      //insertion sort 
      if (i==0)
	{
	  sorted_mincents[0]=a;
	  sorted_maxunits[0]=b;
	}
      else
	{
	  for (int j=0;j<i;j++)
	    {
	      if (a>=sorted_mincents[j])
		{
		  if (j+1==i)
		    {
		      sorted_mincents[i]=a;
		      sorted_maxunits[i]=b;
		      break;
		    }
		  else if (a<=sorted_mincents[j+1])
		    {
		      for (int p=i;p>j+1;p--)
			{
			  sorted_mincents[p]=sorted_mincents[p-1];
			  sorted_maxunits[p]=sorted_maxunits[p-1];
			}
		      sorted_mincents[j+1]=a;
		      sorted_maxunits[j+1]=b;
		      break;
		    }
		  
		}
	      else if (a<=sorted_mincents[j])
		{
		  for (int p=i;p>j;p--)
		    {
			  //cout<<p<<endl;
		      sorted_mincents[p]=sorted_mincents[p-1];
		      sorted_maxunits[p]=sorted_maxunits[p-1];
		    }
		  sorted_mincents[j]=a;
		  sorted_maxunits[j]=b;
		  break;
		}

	    }
	  
	}
    }
  /*for(int q=0;q<N_farm;q++)
    {
      cout<<sorted_mincents[q]<<" ";
    }
  cout<<endl;
  for(int o=0;o<N_farm;o++)
    {
      cout<<sorted_maxunits[o]<<" ";
    }
    cout<<endl;*/
    
    //multiply cents*units and compare with total
    int current_units=0;
    int answer=0;
    for (int i=0;i<N_farm;i++)
	  {
	    if (current_units+sorted_maxunits[i]>=total_units)
	      {
		answer+=sorted_mincents[i]*(total_units-current_units);
		break;
	      }
	    else
	      {
		answer+=sorted_mincents[i]*sorted_maxunits[i];
		current_units+=sorted_maxunits[i];
	      }
	  }
	  
      
    fout<<answer<<endl;

    
  return 0;
}
