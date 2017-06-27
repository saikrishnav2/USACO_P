/*
ID: svasude2
PROG: humble
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int Factors[100];
int Pointers[100];
long Numbers[1000001]kt;
int check(int n,int K)
{
  for (int i=0;i<K;i++)
    {
      if (Factors[i]==n) return 1;
    }
  return 0;

}
int K,N;
/*
  stack 
  pointers
  
  
*/
long Minimum(){
  long minimum=Factors[0]*Numbers[Pointers[0]];
  // cout<<minimum<<endl;
  int index=0;
  for(int i=1;i<K;i++)
    {
      //cout<<Factors[i]*Numbers[Pointers[i]]<<endl;
      if (Factors[i]*Numbers[Pointers[i]]<minimum)
	{
	  minimum=Factors[i]*Numbers[Pointers[i]];
	  index=i;
	}
    }
  Pointers[index]++;
  //cout<<minimum<<endl;
  return minimum;
}

int main()
{
  ifstream fin("humble.in");
  ofstream fout("humble.out");
  
  fin>>K>>N;
  for (int i=0;i<K;i++)
    fin>>Factors[i];
  int count=1;
  Numbers[0]=1;
  for (int i=0;i<K;i++)
    {
      Pointers[i]=0;
    }
  for (int i=1;count<=N;i++)
    {
      Numbers[count++]=Minimum();
      if (count>1 && (Numbers[count-1]==Numbers[count-2])) count--;
      //xcout<<Numbers[count]<<endl;
    }
  fout<<Numbers[count-1]<<endl;
}
/*
int flag=1;
      if (temp%2==0)
	{
	  if (!check(2)) flag=0;
	}
      if (flag)
	{
	  while (temp%2!=0)
	    {
	      temp/=2; 
	    }
	  for (int i=3;i<=(int) sqrt(temp);i+=2)
	    {
	      if (!check(i)) flag=0;
	      while ()
		{

		}

	    }
}*/

/*
while (count<N)
    {
      //find  prime factors of numbers and check if all of them are present in the Factors array
      temp=Number;
      int factor;
      //cout<<"temp: "<<Number<<endl;
      for (int i=0;i<K;i++)
	{
	  

	  factor=Factors[i];
	  //cout<<"Factor: "<<factor<<" temp: "<<temp<<endl; 
	  if (temp%factor!=0)
	    continue;
	  else
	    {
	      while (temp%factor==0)
		{
		  temp/=factor; 
		}
	    }
	  if (temp==1) {
	    count+=1;
	     cout<<count<<" "<<Number<<endl;
	    break;
	  }

	}
      Number++;
    }


*/
