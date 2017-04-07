/*
ID: svasude2
PROG: ride
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  char temp='\0';
  int sum_comet;
  int sum_group;
  fin.get(temp);
  sum_comet=temp-64;

  while(true)
    {
      fin.get(temp);
      if (temp=='\n') break;
      temp=temp-64;
      sum_comet=sum_comet*temp;
      //fout<<sum_comet<<endl;
    }
  
  

  fin.get(temp);
  sum_group=temp-64;
  while(true)
    {
      fin.get(temp);
      if (temp=='\n') break;
      temp=temp-64;
     
      sum_group=sum_group*temp;
    }
  //fout<<sum_group%47<<endl;
  if (sum_comet%47==sum_group%47) fout<<"GO"<<endl;
  else fout<<"STAY"<<endl;
  return 0;
}
