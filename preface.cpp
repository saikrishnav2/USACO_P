/*
ID:svasude2
PROG:preface
LANG:C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#define MAX_N 3500
using namespace std;
struct Book{
  int I,V,X,L,C,D,M;
}; 
void Calculate(Book& book,int num)
{
  int temp=num;
  int count=1;
  int mark=0;
  while (temp!=0)
    {
      mark=temp%10;
      temp/=10;
      //for unit's place
      if (count==1)
	{
	  if (mark==4) {book.I+=1;book.V+=1;}
	  else if (mark==9) {book.I+=1;book.X+=1;}
	  else if (mark>=5){book.V+=1;book.I=book.I+(mark-5);}
	  else book.I+=mark;
	}
      //for ten's place
      else if (count==2)
	{
	  if (mark==4) {book.X+=1;book.L+=1;}
	  else if (mark==9) {book.X+=1;book.C+=1;}
	  else if (mark>=5){book.L+=1;book.X=book.X+(mark-5);}
	  else book.X+=mark;
	}
      //for hundred's place
      else if (count==3)
	{
	  if (mark==4) {book.C+=1;book.D+=1;}
	  else if (mark==9) {book.C+=1;book.M+=1;}
	  else if (mark>=5){book.D+=1;book.C=book.C+(mark-5);}
	  else book.C+=mark;
	}
      else if (count==4)
	{
	  book.M+=mark;
	}
      count++;
    }
}
int main()
{
  ifstream fin("preface.in");
  ofstream fout("preface.out");
  int N;
  fin>>N;
  Book book;
  book.I=0;book.V=0;book.X=0;book.L=0;book.C=0;book.D=0;book.M=0;
  //calculate the numbers starting from 0 to N
  for (int i=1;i<=N;i++)
  {
    Calculate(book,i);
    //cout<<"For "<<i<<":\n";
  }
  if (book.I) fout<<"I "<<book.I<<endl;
  if (book.V) fout<<"V "<<book.V<<endl;
  if (book.X) fout<<"X "<<book.X<<endl;
  if (book.L) fout<<"L "<<book.L<<endl;
  if (book.C) fout<<"C "<<book.C<<endl;
  if (book.D) fout<<"D "<<book.D<<endl;
  if (book.M) fout<<"M "<<book.M<<endl;

}

