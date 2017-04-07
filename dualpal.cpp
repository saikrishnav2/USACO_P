/*
ID:svasude4
PROG: dualpal
LANG: C++      
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
using namespace std;
char array[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
int checkforpal(char* square)
{
  int length=strlen(square);
  for (int i=0;i<length/2;i++)
    {

      if (square[i]!=square[length-1-i])
	{
	  //
	  return 0;}
      
    }
  return 1;
}
void itoa(int num,char* result, int base)
{
  //int current_index=0;
  int temp=0;
  int count=0;
  int temp1=num;
  
  while(temp1!=0)
    {
      temp1/=base;
      count++;
    }
  result[count]='\0';
  for (int i=0;i<count;i++)
    {
      temp=num%base;
      num=num/base;
      result[count-1-i]=array[temp];
    }
  

}
int main() {
  ofstream fout ("dualpal.out");
  ifstream fin ("dualpal.in");
  int base,N,S;
  int square_int;
  char square[33];
  char number[33];
  fin >>N >> S;
  int sum=0;
  int i=S+1;
  int count=0;
  while(count<N)
    {
      sum=0;
      for (base=2;base<=10;base++)
	{
	  itoa(i,number,base);
	  //fout<<number<<endl;
	  sum+=checkforpal(number);
	}
      if (sum>1) {
	count++;
	fout<<i<<endl;
      }
      i++;
    }
  return 0;
}
  
