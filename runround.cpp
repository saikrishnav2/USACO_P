/*
ID:svasude2
PROG:runround
LANG:C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;
int visited[10]={0};
int count_digits(int number)
{
  int temp=number;
  int count=0;
  while(temp!=0)
    {
      temp/=10;
      count++;
    }
  return count;
}


int extract_digit(int number,int digit_pos,int digits)
{
  int correct_digit_pos=digits-1-digit_pos;
  for (int i=0;i<correct_digit_pos;i++)
    {
      number/=10;
    }
  return number%10;
  
}
int all_visited(int digits)
{
  for (int i=0;i<digits;i++)
    {
      if (visited[i]==0) return 0;
    }
  return 1;
}
int all_unique(int number,int digits)
{
  //reuse the visited array for this purpose
 
  for (int i=0;i<digits;i++)
    {
      int temp=visited[extract_digit(number,i,digits)];
      if(temp==1) return 0;
      else visited[extract_digit(number,i,digits)]=1;
    }
  return 1;

}
int check(int number,int digits,int position)
{
/*Example:
  81362
  5 digits
  iter 1: (0+8)%5-->Stop at third digit mark digit 1 as visited
  iter 2: (3+6)%5-->Stop at 4th digit mark digit 3 as visited  
  iter 3: (4+2)%5-->Stop at 1st digit mark digit 4 as visited
  iter 4: (1+1)%5-->Stop ar 2nd digit mark digit 1 as visited
  iter 5: (2+3)%5-->Stop at 0th digit and mark digit 2 as visited, Since last iteration check if posiiton is at 0 and if all the nodes are visited. 
*/
  for (int i=0;i<digits;i++)
    {
      int cur=extract_digit(number,position,digits);
      //cout<<cur<<endl;
      visited[position]=1;
      position=(cur+position)%digits;
    }
  if (position==0 && all_visited(digits))
    return 1;
  else return 0;
}
  
int main()
{
  ifstream fin("runround.in");
  ofstream fout("runround.out");
  int N;
  fin>>N;

  /*
    check for runaround numbers starting from N
  */
  for (int j=N+1;j<999999999;j++)
    {
      if (all_unique(j,count_digits(j)))
	{
	  for (int pp=0;pp<10;pp++) visited[pp]=0;
	  if (check(j,count_digits(j),0))
	    {
	      fout<<j<<endl;
	      break;
	    }

	}
      for (int pp=0;pp<10;pp++) visited[pp]=0;
    }
}
