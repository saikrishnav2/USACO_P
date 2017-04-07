/*
ID:svasude2
PROG:sort3
LANG:C++


 */
#include <fstream>
#include <iostream>
#define MAX_N 1000
using namespace std;
ofstream fout("sort3.out");
ifstream fin("sort3.in");
int N;
int array[MAX_N]={0};
int count_swaps=0;
int main()
{
  fin>>N;
  int count_one=0;
  int count_two=0;
  int count_three=0;
  for (int i=0;i<N;i++)
    {
      fin>>array[i];
      if (array[i]==1) count_one++;
      else if (array[i]==2) count_two++;
      else count_three++;
    }
  
  for (int i=count_one;i<N;i++)
    {
      // for (int p=0;p<N;p++) cout<<array[p]<<" ";
      //cout<<endl;
      if (array[i]==1)
	{

	  if (i<count_one+count_two)
		{
		  for (int j=0;j<count_one;j++)
		    {
		      if(array[j]==2)
			{
			  array[i]=2;
			  array[j]=1;
			  count_swaps++;
			  break;
			}
		      
		    }
		}
	  else
	    {
	      for (int j=0;j<count_one;j++)
		{
		  if(array[j]==3)
		    {
		      array[i]=3;
		      array[j]=1;
		      count_swaps++;
		      break;
		    }
		      
		}
	      
	      
	    }
	  
	}
      

    }
  //swap the remaining ones out of place
  
  for (int i=count_one;i<N;i++)
    {
      if (array[i]==1)
	{
	  for (int j=0;j<count_one;j++)
	    {
	      if (array[j]!=1)
		{
		  array[i]=array[j];
		  array[j]=1;
		  count_swaps++;
		  break;
		}
	    }

	}
    }
  //count the nummber of 2's
 
  for (int i=count_one+count_two;i<N;i++)
    {
      if (array[i]==2)
	{
	  count_swaps++;
	}
    }
  fout<<count_swaps<<endl;
}
