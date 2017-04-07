/*
ID:svasude2
PROG: pprime
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;


int Count=0;
int pal[100000]={0};
int isprime(int number)
{
  int root=(int) sqrt(number);
  for (int i=2;i<=root;i++)
    {
      if (number%i==0) return 0;

    }
  return 1;

}
int onetwodigit()
{
  for (int d1=1;d1<=9;d1+=2)
    {
      
      pal[Count]=d1;
      pal[Count+1]=d1*10+d1;
      
      Count+=2;  
    }
}

int threefourdigit()
{
  for (int d1=1;d1<=9;d1+=2)
    {
      for(int d2=0;d2<=9;d2++)
	{
	  pal[Count]=d1*100+d2*10+d1;
	  pal[Count+1]=d1*1000+d2*100+d2*10+d1;
	  //
	  Count+=2;
	} 

    }
  
}
int fivesixdigit()
{

  for (int d1=1;d1<=9;d1+=2)
    {
      for(int d2=0;d2<=9;d2++)
	{
	  for (int d3=0;d3<=9;d3++)
	    {
	      pal[Count]=d1*10000+d2*1000+d3*100+d2*10+d1;
	      pal[Count+1]=d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1;
	      Count+=2;
	    }
	}

    }
  
}
int seveneightdigit()
{

  for (int d1=1;d1<=9;d1+=2)
    {
      for(int d2=0;d2<=9;d2++)
	{
	  for (int d3=0;d3<=9;d3++)
	    {
	      for (int d4=0;d4<=9;d4++)
		{
		  pal[Count]=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
		  pal[Count+1]=d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1;
		  Count+=2;
		}
	    }
	}

    }
  
}




 
int main()
{
  ofstream fout ("pprime.out");
  ifstream fin ("pprime.in"); 
  onetwodigit();
  /*for (int i=0;i<Count;i++)
    {
      cout<<pal[i]<<endl;
      }*/
  // cout<<Count<<endl;
  threefourdigit();
  /*for (int i=0;i<Count;i++)
    {
     
      }*/
  fivesixdigit();
  seveneightdigit();
  /* for (int i=0;i<Count;i++)
    {
      
    }*/
  sort (pal,pal+Count);
  int a,b;
  fin>>a>>b;
  //cout<<a<<b<<endl;
  for (int i=0;i<Count;i++)
    {
      //cout<<pal[i]<<endl;
      if (pal[i]>=a)
	{
	  if (pal[i]<=b)
	    {
	      //   cout<<pal[i]<<endl;
	      if (isprime(pal[i]))
		{
		  
		   fout<<pal[i]<<endl;
		}
	    }
	  else
	    {
	      break;
	    }
	}
    }

}
  
/*

int extract(int digit_number,int Number,int N)
{
  int count=0;
  while(N>0)
    {
      //cout<<Number<<endl;
      count++;
      if (count==digit_number)
	return Number/((int) pow(10,N-1));
      else  Number%=((int) pow(10,N-1));
     
      N--;
    }

}
int Return_Closest_Palindrome(int num,int N)
{
  int L,R,i,j,M;
  
  int no_need=1;
  for(int e=N;e>=N/2;e--)
    {
      L=extract(N-e+1,num,N);                 //extract left middle
      R=extract(e,num,N);             //extract right middle
      //cout<<L<<M<<R<<endl;
      if (L==R)
	{
	  if ((N%2==0)&&(e==N/2+1))
	    {
	      if (!no_need)
		{
		  num+=((int) pow(10,N-e));
		  num+=((int) pow(10,N-e+1));
		  no_need=1;
		}
	    }
	  else if ((N%2!=0)&&(e==N/2+1))
	    {
	      if (!no_need)
		{
		  num+=((int) pow(10,N-e));
		  no_need=1;
		}
	    }

	}
      if (L>R){
	//num+=((int) pow(10,N-i));
	if ((N%2==0)&&(e==N/2+1))
	  {
	    if (!no_need)
	      {
		
		num+=(L-R)*((int) pow(10,N-e));
		no_need=1;
	      }

	  }
	else
	  num+=(L-R)*((int) pow(10,N-e));

      }
      else if (L<R)
	{
	  if ((N%2==0)&&(e==N/2+1))
	    {
	      if (!no_need)
		{
		  num+=((int) pow(10,N-e+1));
		  num-=(R-L-1)*((int) pow(10,N-e));
		  no_need=1;
		}
	      
	    }
	  else
	    {
	      num-=(R-L)*((int) pow(10,N-e));
	      no_need=0;
	    }
	}
      
    }
  return num;	
  
}

 */
