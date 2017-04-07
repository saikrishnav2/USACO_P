/*
ID: svasude42
PROG: friday
LANG: C++    
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");
  int N;
  fin >>N;
  int year=1900;
  //int power=0;
  int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
  //int char*[]={30,28,31,30,31,30,31,31,30,31,30,31};
  //int monthsl[]={30,29,31,30,31,30,31,31,30,31,30,31};
  int count[]={0,0,0,0,0,0,0};
  int day=0;
  for (int i=0;i<N;i++)
    {
      year=1900+i;
      //cout<<"Year "<<year<<endl;
      int leap=0;
      if (year%100!=0)
	{
	  if (year%4==0) leap=1;
	  else leap=0;
	}
      else
	{
	  if (year%400==0) leap=1;
	  else leap=0;
	    
	}
      
      //loop through months
      for (int j=0;j<12;j++)
	{
	  //calculate 13th of each month and update the array;
	  if (day-2<0) day=7+day-2;
	  else day=day-2;
	  //cout<<day<<endl;
	  count[day]+=1;
	  // cout<<day<<endl;
	  //calculate first of next month.
	  int remainder=months[j]-27;
	  if (j==1 && leap==1) remainder=2;
	  day=(remainder+1+day)%7;
	  
	  
	}


    }
  for (int p=0;p<7;p++)
    {
      if (p!=6)   fout<<count[(5+p)%7]<<" ";
      else fout<<count[(5+p)%7]<<"\n";
    }
  
  //fout << a+b << endl;
  return 0;
}
