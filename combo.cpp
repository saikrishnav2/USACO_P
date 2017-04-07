/*
ID: svasude2
PROG: combo
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
int check(int i,int j,int k,int* Farmer,int* Master,int N)
{
  
  //Check if i, j and k are within a tolerance of 2 for either Farmer or Master Lock Combos.
  //find less of two and check if less+2<=greater or (greater+2)%N<=less;
  
  int lesser_i,greater_i,lesser_j,greater_j,lesser_k,greater_k;
  if (i<=Master[0]) {lesser_i=i;greater_i=Master[0];}
  else  {lesser_i=Master[0];greater_i=i;}
  if (j<=Master[1]) {lesser_j=j;greater_j=Master[1];}
  else  {lesser_j=Master[1];greater_j=j;}
  if (k<=Master[2]) {lesser_k=k;greater_k=Master[2];}
  else  {lesser_k=Master[2];greater_k=k;}
  
  //cout<<greater_i<<" "<<lesser_i<<endl;
  if (((greater_i-lesser_i<=2)||(((greater_i+2)%N<=2)&&(lesser_i<=(greater_i+2)%N)))&&((greater_j-lesser_j<=2)||(((greater_j+2)%N<=2)&&(lesser_j<=(greater_j+2)%N)))&&((greater_k-lesser_k<=2)||(((greater_k+2)%N<=2)&&(lesser_k<=(greater_k+2)%N))))
    {
      //cout<<i<<" "<<j<<" "<<k<<" "<<endl;
    return 1;
    }
  if (i<=Farmer[0]) {lesser_i=i;greater_i=Farmer[0];}
  else  {lesser_i=Farmer[0];greater_i=i;}
  if (j<=Farmer[1]) {lesser_j=j;greater_j=Farmer[1];}
  else  {lesser_j=Farmer[1];greater_j=j;}
  if (k<=Farmer[2]) {lesser_k=k;greater_k=Farmer[2];}
  else  {lesser_k=Farmer[2];greater_k=k;}
  if (((greater_i-lesser_i<=2)||(((greater_i+2)%N<=2)&&(lesser_i<=(greater_i+2)%N)))&&((greater_j-lesser_j<=2)||(((greater_j+2)%N<=2)&&(lesser_j<=(greater_j+2)%N)))&&((greater_k-lesser_k<=2)||(((greater_k+2)%N<=2)&&(lesser_k<=(greater_k+2)%N))))
    {
      //    cout<<i<<" "<<j<<" "<<k<<" "<<endl;
      return 1;
    }
  
  
  return 0;  


}

 
int main() {
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");
  int N;
  fin>>N;
  int Farmer[3]={0};
  int Master[3]={0};
  for (int i=0;i<3;i++) fin>>Farmer[i];
  for (int i=0;i<3;i++) fin>>Master[i];
  int ans=0;
  //N=1;
  //Generate all possible combinations
  for (int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
	{
	  for (int k=1;k<=N;k++)
	    {
	      
	      ans+=check(i,j,k,Farmer,Master,N);
	      
	    }
	}
    }
  fout<<ans<<endl;
}
