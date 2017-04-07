/*
ID: svasude2
PROG: frac1
LANG: C++
*/

#include <fstream>
#include <iostream>
#define MAX_N 160
int Combinations[MAX_N][MAX_N]={0};
using namespace std;
ofstream fout("frac1.out");
ifstream fin("frac1.in");
int N;

struct fraction{
  int numerator;
  int denominator;
};
fraction Fractions[25600];
int fraction_count=0;
void read_input(void)
{
  fin>>N;
}
int gcd(int numerator,int denominator)
{
  //  cout<<"GCD : numerator , denominator "<<numerator<<","<<denominator<<endl;
  int remainder=numerator%denominator;
  int dividend=numerator/denominator;
 
  if (remainder==0) return denominator;
  if (remainder<denominator) return gcd(denominator,remainder);
  else return gcd(remainder,denominator);
  
}
fraction reduce(int numerator,int denominator)
{
  int GCD=gcd(numerator,denominator);
  fraction Result={numerator/GCD,denominator/GCD};
  return Result;
  
}
int dfs(int numerator,int denominator)
{
  //  if (denominator==15) cout<<numerator<<"/"<<denominator<<" "<<fraction_count<<endl;
  
  fraction Reduced=reduce(numerator,denominator);
  denominator=Reduced.denominator;
  numerator=Reduced.numerator;
  if (Combinations[numerator][denominator]) return 0;

  
  if (numerator==0 && denominator>1) return 0;
  
  if ((numerator<=N && denominator<=N)&&(numerator<=denominator))
    {
      
      Combinations[numerator][denominator]=1;
      
      dfs(numerator,denominator+1);
      dfs(numerator+1,denominator);
      dfs(numerator+1,denominator+1);
      Fractions[fraction_count].numerator=numerator;
      Fractions[fraction_count].denominator=denominator;
      fraction_count++;
	
      
    }
  return 1;
}
int compare(const void* p1,const void* p2)
{
  fraction* P1=(fraction*) p1;
  fraction* P2=(fraction*) p2;
  int LHS=((P1->numerator)*(P2->denominator));
  int RHS=((P2->numerator)*(P1->denominator));
  if (LHS<RHS) return -1;
  else if (LHS>RHS) return 1;
  else return 0;
}
int main()
{
  
  read_input();
  for (int i=0;i<=N;i++)
    {
      for (int j=1;j<=N;j++)
	{
	  dfs(i,j);
    	}
    } 
  qsort(Fractions,fraction_count,sizeof(Fractions[0]),compare);
  for (int i=0;i<fraction_count;i++){
    fout<<Fractions[i].numerator<<"/"<<Fractions[i].denominator<<endl;
  }
  fraction test=reduce(7,15);
  //  cout<<test.numerator<<"/"<<test.denominator<<endl;
}
