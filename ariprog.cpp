/*
ID: svasude2
PROG: ariprog
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int mark[125000]={0};
void generate_bisquare(int Bi_max)
{
  for (int p=0;p<=Bi_max;p++)
    {
      for (int q=0;q<=Bi_max;q++)
	{
	  int sum=p*p+q*q;
	  mark[sum]=1;
	    
	  
	}
    }
 
}
int check_sequence(int length,int Bi_max,int sp,int difference,int Max)
{
  int current=sp;
  while(length--)
    {
      //if ((sp==1)&&(difference==4)) cout<<current<<endl;
      if ((mark[current])&& (current<=Max)) current+=difference;
      else return 0;
    }
  //if (mark[current]) return 0;
  return 1;


}
int main() {
  ofstream fout ("ariprog.out");
  ifstream fin ("ariprog.in");

  int length,Bi_max,Max;
  fin>>length>>Bi_max;
  generate_bisquare(Bi_max);
  Max=(Bi_max*Bi_max)+(Bi_max*Bi_max);
  int flag=0;
  
  
  for (int difference=1;difference<=Max;difference++)
    {
     
      for(int sp=0;sp<=Max;sp++)
	{

	
	  if (sp+((length-1)*difference)>Max)
	    {
	      break;
	    }
	  else if (check_sequence(length,Bi_max,sp,difference,Max))
	      {fout<<sp<<" "<<difference<<endl;flag=1;}
	  
	}
      
    }
      if (flag==0) fout<<"NONE"<<endl;
}
