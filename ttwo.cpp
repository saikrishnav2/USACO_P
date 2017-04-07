/*
ID:svasude2
PROG:ttwo
LANG:C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#define NORTH 0
#define EAST 1
#define SOUTH  2
#define WEST  3



using namespace std;
char Grid [11][11];
char Visited [11][11][11][11][4][4];



struct State
{
  char row,col,dir;
};

void Calculate_Pos(State& state)
{
  int row=0;
  int col=0;
  if (state.dir==NORTH)
    {
      row=state.row-1;
      col=state.col;
    }
  else if (state.dir==SOUTH)
    {
      row=state.row+1;
      col=state.col;
    }
  else if (state.dir==WEST)
    {
      row=state.row;
      col=state.col-1;
    }
  else if (state.dir==EAST)
    {
      row=state.row;
      col=state.col+1;
    }
  //check if row or collumn are out of bounds
  if (row<1||row>10||col<1||col>10)
    {
      //rotate ninety degrees
      state.dir=(state.dir+1)%4;
    }
  else if (Grid[row][col]=='*')
    {
      state.dir=(state.dir+1)%4;
    }
  else
    {
      state.row=row;
      state.col=col;
    }
  
}
int main()
{

  ifstream fin("ttwo.in");
  ofstream fout("ttwo.out");
  State Farmer,Cow;
  //initalize visited to 0

  for (int i=0;i<=10;i++)
    {
      for (int j=0;j<=10;j++)
	{
	  for (int k=0;j<=10;j++)
	    {
	      for (int l=0;j<=10;j++)
		{
		  for(int m=0;m<=3;m++)
		    {
		      for (int n=0;n<=3;n++)
			{
			  Visited[i][j][k][l][m][n]=0;
			}
		    }
		}
	    }
	}


    }

  
  for (int i=1;i<=10;i++)
    {
      for (int j=1;j<=10;j++)
	{
	  fin>>Grid[i][j];
	  if (Grid[i][j]=='F')
	    {
	      Farmer.row=i;
	      Farmer.col=j;
	      Farmer.dir=NORTH;
	    }
	  else if (Grid[i][j]=='C')
	    {
	      Cow.row=i;
	      Cow.col=j;
	      Cow.dir=NORTH;
	    }
	  cout<<Grid[i][j]<<" ";
	}
      cout<<endl;
    }
  /*Algorithm
    while (True)
    {
    Calculate positions for both Farmer and Cow in the next minute   
    Check if they are going to be in the same spot in the next minute
       if they are break and output minutes
    
    else
       Check for cycle:
       if yes, output impossible
       else move farmers and cows positions and update visited array  
       
    }     
  */
 
  int minutes=0;
  //int pp=15;
  while(1)
    {
      //   cout<<"Farmer: "<<(int) Farmer.row<<" "<<(int) Farmer.col<<" "<<(int) Farmer.dir<<endl;
      //cout<<"Cow: "<<(int) Cow.row<<" "<<(int) Cow.col<<" " <<(int)Cow.dir<<endl;
      minutes++;
      Calculate_Pos(Farmer);
      Calculate_Pos(Cow);
      if ((Farmer.row==Cow.row)&&(Farmer.col==Cow.col))
	{
	  fout<<minutes<<endl;
	  break;
	}
      //check if already visited
      if (Visited[Farmer.row][Farmer.col][Cow.row][Cow.col][Farmer.dir][Cow.dir])
	{
	  
	  fout<<0<<endl;
	  break;
	}
      else Visited[Farmer.row][Farmer.col][Cow.row][Cow.col][Farmer.dir][Cow.dir]=1;
      
      

    }
 
}
