/*
D: svasude42
PROG: transform
LANG: C++    
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int ninety(int** array,int** array2,int N)
{
  //first row --last column
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  //cout<<array[i][j]<<" "<<array2[j][N-1-i]<<endl;
	  if (array[i][j]==array2[j][N-1-i]) continue;
	  else return 0;
	}

    }
  return 1;

}
int oneeighty(int** array,int** array2,int N)
{
  //first row --last column
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  //cout<<array[i][j]<<" "<<array2[j][N-1-i]<<endl;
	  if (array[i][j]==array2[N-1-i][N-1-j]) continue;
	  else return 0;
	}

    }
  return 1;

}
int twoseventy(int** array,int** array2,int N)
{
  //first row --last column
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  //cout<<array[i][j]<<" "<<array2[N-1-j][i]<<endl;
	  if (array[i][j]==array2[N-1-j][i]) continue;
	  else return 0;
	}

    }
  return 1;

}

int ref(int** array,int** array2,int N)
{
  //first row --last column
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  //cout<<array[i][j]<<" "<<array2[i][N-1-j]<<endl;
	  if (array[i][j]==array2[i][N-1-j]) continue;
	  else return 0;
	}

    }
  return 1;

}
int ref90(int** array,int** array2,int N)
{
  //first row --last column
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  //cout<<array[i][j]<<" "<<array2[i][N-1-j]<<endl;
	  if (array[i][j]==array2[N-1-j][N-1-i]) continue;
	  
	  else return 0;
	}

    }
  return 1;

}

int ref180(int** array,int** array2,int N)
{
  //first row --last column
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  //cout<<array[i][j]<<" "<<array2[i][N-1-j]<<endl;
	  if (array[i][j]==array2[N-1-i][j]) continue;
	  
	  else return 0;
	}

    }
  return 1;

}

int ref270(int** array,int** array2,int N)
{
  //first row --last column
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  //cout<<array[i][j]<<" "<<array2[i][N-1-j]<<endl;
	  if (array[i][j]==array2[j][i]) continue;
	  else return 0;
	}

    }
  return 1;

}
int same(int** array,int** array2,int N)
{
  //first row --last column
  for (int i=0;i<N;i++)
    {
      for (int j=0;j<N;j++)
	{
	  //cout<<array[i][j]<<" "<<array2[i][N-1-j]<<endl;
	  if (array[i][j]==array2[i][j]) continue;
	  else return 0;
	}

    }
  return 1;

}

	 
int main() {
  ofstream fout ("transform.out");
  ifstream fin ("transform.in");
  int N;
  fin>>N;
  fin.ignore();
  char inp='\0';
  int** array= new int*[N];
  int** array2= new int*[N];
  for(int j = 0; j < N; j++)
    {
      array[j] = new int[N];
      for(int i=0;i<N+1;i++)
	{
	  if (i==N) fin.ignore();
	  else
	    {
	      fin.get(inp);
	      array[j][i]=(int) inp;
	    }      

	}
    }
  for(int u = 0; u < N; u++)
    {
      array2[u] = new int[N];
      for(int v=0;v<N+1;v++)
	{
	  if (v==N) fin.ignore();
	  else
	    {
	      fin.get(inp);
	      array2[u][v]=(int) inp;
	    }      

	}
    }
  
  //fin >> a >> b;
  for (int p=0;p<N;p++)
    {
      for(int q=0;q<N;q++)
	{
	  cout<<array[p][q]<<" ";
	}
      cout<<endl;
    }
  cout<<endl;
  for (int p=0;p<N;p++)
    {
      for(int q=0;q<N;q++)
	{
	  cout<<array2[p][q]<<" ";
	}
      cout<<endl;
    }
  if (ninety(array,array2,N)) fout<<"1"<<endl;
  else if (oneeighty(array,array2,N)) fout<<"2"<<endl;
  else if (twoseventy(array,array2,N)) fout<< "3"<<endl;
  else if (ref(array,array2,N))  fout<<"4"<<endl;
  else if (ref90(array,array2,N))  fout<<"5"<<endl;
  else if (ref180(array,array2,N))  fout<<"5"<<endl;
  else if (ref270(array,array2,N))  fout<<"5"<<endl;
  else if (same(array,array2,N))  fout<<"6"<<endl;
  else  fout<<"7"<<endl;
  
  cout<<ref(array,array2,N)<<endl;
  //fout << a+b << endl;
  return 0;
}
