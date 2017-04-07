/*
ID: svasude2
PROG: sprime
LANG: C++
 */

#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
int Current_Number=0;
ofstream fout("sprime.out");
int isprime(int number)
{
  if ((number==1)) return 0;
  if ((number==2)) return 1;

  int root=(int) sqrt(number);
  for (int i=2;i<=root;i++)
    {
      if (number%i==0) return 0;

    }
  return 1;

}
int Search(int N)
{
  
  if (!isprime(Current_Number/((int) pow(10,N))))
    {
      
      //  cout<<Current_Number/((int) pow(10,N))<<endl;
      return 0;
    }
  if (N==0)
    {
      fout<<Current_Number<<endl;
      return 0;
    }
  for (int i=1;i<=9;i++)
    {
      Current_Number+=i*(int) pow(10,N-1);
      Search(N-1);
      Current_Number-=i*(int) pow(10,N-1);
	  
    }
  return 0;
      

}
int main()
{
  
  ifstream fin("sprime.in");
  int N;
  fin>>N;
  //cout<<isprime(3)<<endl;
  Search(N);
  
  
}
  
