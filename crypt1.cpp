/*
ID: svasude2
PROG: crypt1
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int Set[10]={0};
int N;
int check(int number,int part)
{
  //Count the number of digits
  int count=0;
  int temp=number;
  int number1=0;
  int main=number;
  while (temp!=0)
    {
      temp/=10;
      count++;
    }
  
  //if (number==44) cout<<"yo"<<endl;
  if ((part==1) && (count !=3)) return 0;
  if ((part==0) && (count !=4)) return 0;
  for (int j=0;j<count;j++)
    {
      int flag=0;
      number1=number%10;
        
      for (int i=0;i<N;i++)
	{
	  if (main==4884)
	    {
	      //cout<<number1<<" "<<Set[i]<<endl;
		//cout<<"Top: "<<Top[i]<<" Bottom: "<<Bottom[j]<<" "<<number<<" "<<zero_in_set<<endl;
	    }
	  if (Set[i]==number1) {
	     

	    flag=1;
	  }
	   
	}
      if(flag==0)
	{

	  if ((j==0) && number1==0 && part==1); 
	  else return 0;
	}

      number/=10;
      
    }
  return 1;
}

int main() {
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");
  
  int Index_Top=0;
  int Index_Bottom=0;
  int Top[810]={0};
  int Bottom[90]={0};
  
  fin>>N;
  int length=N;
  int zero_in_set=0;
  while (length--) {
    fin>>Set[length];
    if (Set[length]==0) zero_in_set=1;
  }
  
    
  
  //////////////////////////////////////////////// Generating Combinations ////////////////////////////////////////////////
  for (int i=0;i<N;i++)
    {
      if (Set[i]==0) continue;
      for (int j=0;j<N;j++)
	{
               for (int k=0;k<N;k++)
		 {
		   
		   Top[Index_Top++]=Set[k]+10*Set[j]+ 100*Set[i];
		   if ((Set[j]!=0)&& (i==N-1)) Bottom[Index_Bottom++]=Set[k]+10*Set[j];
		 }
	}
    }
  //////////////////////////////////////////////---------------------------/////////////////////////////////////////////////
  /*for (int i=0;i<Index_Top;i++)
    cout<<Top[i]<<endl;
  cout<<"Top Done"<<endl;
  for (int j=0;j<Index_Bottom;j++)
    cout<<Bottom[j]<<endl;
    cout<<"Bottom Done"<<endl;*/
  int Total_Top;
  if (zero_in_set) int Total_Top=(N-1)*N*N;
  else Total_Top=(N)*N*N;
  int Total_Bottom;
  if (zero_in_set) Total_Bottom=(N-1)*N;
  else Total_Bottom=(N)*N;
  int part=1;
  int answer=0;
  int number=0;
  //cout<<Total_Top<<Total_Bottom<<endl;
  for (int i=0;i<Total_Top;i++)
    {
      for(int j=0;j<Total_Bottom;j++)
	{
	  
	  
	  part=1;
	  number=Top[i]*(Bottom[j]%10);//	  ..Multiply with first digit of bottom
	  //cout<<Top[i]<<endl;
	  //if (Top[i]==222) cout<<"MF! "<<endl;
	  if ((number==0) && !zero_in_set) continue;
	  if (!check(number,part)) continue;
	  
	  else
	    {
	      
	      number=Top[i]* (Bottom[j]-(Bottom[j]%10))/10;//Multiply with second digit of bottom
	      if (((number==0) && !zero_in_set)) continue;
	      if (!check(number,part)) continue;
	      else
		{

		  
		  number = Top[i]*Bottom[j];//Multiply both the the numbers and check
		  		      
		  if (((number==0) && !zero_in_set)) continue;
		  part=0;
		  if (!check(number,part)) continue;
		  
		  else
		    {
		      cout<<Top[i]*Bottom[j]<<" "<<Top[i]*(Bottom[j]%10)<<" "<<Top[i]* (Bottom[j]-(Bottom[j]%10))/10<<": "<<Top[i]<<" "<<Bottom[j]<<" "<<answer<<endl;
		      answer++;
		    }
		}
	    }
	}
    }
  fout<<answer<<endl;








  
  // cout<<"Set"<<endl;
  //for (int i=0;i<N;i++) cout<<Set[i]<<endl;
  
  /*for (int i=0;i<Index_Top;i++)
    cout<<Top[i]<<endl;
  cout<<"Top Done"<<endl;
  for (int j=0;j<Index_Bottom;j++)
    cout<<Bottom[j]<<endl;
    cout<<"Bottom Done"<<endl;*/
}
