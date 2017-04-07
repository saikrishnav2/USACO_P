/*
ID: svasude2
PROG:castle
LANG: C++
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
  int Number;
  int Visited,North,South,West,East;
 
};
Node Matrix[50][50];
ofstream fout ("castle.out");
ifstream fin ("castle.in");
int Row,Col;
void read_input(void)
{
  fin>>Col>>Row;
  for (int i=0;i<Row;i++)
    {
      for (int j=0;j<Col;j++)
	{
	  fin>>Matrix[i][j].Number;
	}
    }


}
int array_east[]={4,5,6,12,7,14,13,15};
int array_west[]={1,3,5,9,7,13,11,15};
int array_south[]={8,9,10,12,14,11,13,15};
int array_north[]={2,3,6,10,7,14,11,15};
int array_directions[]={1,2,4,8};
int is_open(int number,int direction)
{
  int* array_search;
  switch(direction)
    {
    
    case(1):
      array_search=array_west;
      break;
    case(2):
      array_search=array_north;
      break;
    case(4):
      array_search=array_east;
      break;
    case(8):
      array_search=array_south;
      break;
    }
  if (number==0) return 1;
  for (int i=0;i<8;i++)
    {
      if (number==array_search[i]) return 0;

    }
  
  return 1;
  
}

int check_for_border(int Row_Start,int Col_Start)
{
  int result=0;
  //check for up
  if (Row_Start==0) result+=2;
  if (Row_Start==Row-1) result+=8;
  if (Col_Start==0) result+=1;
  if (Col_Start==Col-1) result+=4; 
  return result;

}
int is_wall(int number,int direction,int Row_Start,int Col_Start)
{
  
  
  int* array_search;
  switch(direction)
    {
    case(1):
      array_search=array_west;
      break;
    case(2):
      array_search=array_north;
      break;
    case(4):
      array_search=array_east;
      break;
    case(8):
      array_search=array_south;
      break;
    }
  //check if it is a border up,down, left or right
  int Wall_to_the_border=check_for_border(Row_Start,Col_Start);
  if (is_open(Wall_to_the_border,direction)) 
    {
      for (int i=0;i<8;i++)
	{
	  if ((number==array_search[i])) return 1;
	  
	}
    }
  
  return 0;
  
}
int Row_direction(int Row,int direction)
{
  /*
  - 1: wall to the west
  - 2: wall to the north
  - 4: wall to the east
  - 8: wall to the south
  */
  if ((direction==1)||(direction==4)) return Row;
  else if (direction==2) return Row-1;
  else return Row+1;
  
}
int Col_direction(int Col,int direction)
{
  /*
  - 1: wall to the west
  - 2: wall to the north
  - 4: wall to the east
  - 8: wall to the south
  */
  if ((direction==2)||(direction==8)) return Col;
  else if (direction==1) return Col-1;
  else return Col+1;
  
}

int find_longest_room(int Row_Start,int Col_Start)
{
  
  int queue[4]={0};
  int queue_count=0;
  int modules_found=1;
  if (Matrix[Row_Start][Col_Start].Visited) return 0;


  
  //Can go to west,east,south,North?
  for (int i=0;i<4;i++)
    {
      if (is_open(Matrix[Row_Start][Col_Start].Number,array_directions[i]))
	{
	  queue[queue_count]=array_directions[i];
	  queue_count++;
	}
    }
  //cout<<"Module Position: "<<Row_Start<<" "<<Col_Start<< " Queue Count" <<queue_count<<" Number: "<<Matrix[Row_Start][Col_Start].Number<<endl;
  // for each direction that the room could take
  //print queue_count;
  //cout<<"Queue Count: "<<queue_count<<endl;


  
  for (int i=0;i<queue_count;i++)
    {
      //Mark this room as visited
      Matrix[Row_Start][Col_Start].Visited=1;
      //Recurse on the next module to the open direction
      int New_Row=Row_direction(Row_Start,queue[i]);
      int New_Col=Col_direction(Col_Start,queue[i]);
      modules_found=modules_found+find_longest_room(New_Row,New_Col);
      //Matrix[Row_Start][Col_Start].Visited=0;
    }
  return modules_found;
  
}
void clear_visited()
{
  
  for (int i=0;i<Row;i++)
    {
      for (int j=0;j<Col;j++)
	{
	  Matrix[i][j].Visited=0;
	  Matrix[i][j].North=0;
	  Matrix[i][j].South=0;
	  Matrix[i][j].West=0;
	  Matrix[i][j].East=0;  
	}
    }

}
void Mark_Wall(int Row_Start,int Col_Start,int direction)
{
  /*
    - 1: wall to the west
    - 2: wall to the north
    - 4: wall to the east
    - 8: wall to the south
  */
  
  
  switch(direction)
    {
    case(1):
      Matrix[Row_Start][Col_Start].West=1;
      break;
    case(2):
      Matrix[Row_Start][Col_Start].North=1;
      break;
    case(4):
      Matrix[Row_Start][Col_Start].East=1;
      break;
    case(8):
      Matrix[Row_Start][Col_Start].South=1;
      break;
    }


}
void Unmark_Wall(int Row_Start,int Col_Start,int direction)
{
  /*
    - 1: wall to the west
    - 2: wall to the north
    - 4: wall to the east
    - 8: wall to the south
  */
  
  
  switch(direction)
    {
    case(1):
      Matrix[Row_Start][Col_Start].West=1;
      break;
    case(2):
      Matrix[Row_Start][Col_Start].North=1;
      break;
    case(4):
      Matrix[Row_Start][Col_Start].East=1;
      break;
    case(8):
      Matrix[Row_Start][Col_Start].South=1;
      break;
    }


}
int opposite(int direction)
{
  switch(direction)
    {
    case(1):
      return 4;
    case(2):
      return 8;
    case(4):
      return 1;
    case(8):
      return 2;
    }

}
int is_wall_visited(int Row_Start,int Col_Start,int direction)
{
   switch(direction)
    {
    case(1):
      return Matrix[Row_Start][Col_Start].West;
    case(2):
      return Matrix[Row_Start][Col_Start].North;
    case(4):
      return Matrix[Row_Start][Col_Start].East;
    case(8):
      return Matrix[Row_Start][Col_Start].South;
    }



}

int find_wall_to_be_removed()
{

  int queue[4]={0};
  int queue_count=0;
  int largest=0;
  int Largest_Row=0;
  int Largest_Col=0;
  int Largest_Direction=0;
  //Can go to west,east,south,North?
  for (int Row_Start=0;Row_Start<Row;Row_Start++)
    {
      for (int Col_Start=0;Col_Start<Col;Col_Start++)
	{
	  int queue_count=0;

	  //	  cout<<"New Starting Module: "<<Row_Start<<":"<<Col_Start<<endl; 


	  for (int i=0;i<4;i++)
	    {
	      if (is_wall(Matrix[Row_Start][Col_Start].Number,array_directions[i],Row_Start,Col_Start))
		{
		  queue[queue_count]=array_directions[i];
		  queue_count++;
		}
	    }
	  for (int i=0;i<queue_count;i++)
	    {
	      //if wall is not already visited
	      //	      cout<<"New Wall Removing..."<<endl;
	      if (!is_wall_visited(Row_Start,Col_Start,queue[i]))
		{
		  int modules_found=0;
		  //Mark the Wall as removed for both the current and adjacent modules.
		  Mark_Wall(Row_Start,Col_Start,queue[i]);
		  Matrix[Row_Start][Col_Start].Number-=queue[i];
		  // Remove the wall from the adjacent module too
		  int New_Row=Row_direction(Row_Start,queue[i]);
		  int New_Col=Col_direction(Col_Start,queue[i]);
		  Mark_Wall(New_Row,New_Col,opposite(queue[i]));
		  Matrix[New_Row][New_Col].Number-=opposite(queue[i]);
		  
		  //Recurse on the next module to the open direction
		  modules_found=modules_found+find_longest_room(Row_Start,Col_Start);
		  clear_visited();
		  //Add the wall back
		  Matrix[Row_Start][Col_Start].Number+=queue[i];
		  Matrix[New_Row][New_Col].Number+=opposite(queue[i]);
		  
		  //update largest
		  if (modules_found>largest)
		    {
		      largest=modules_found;
		      Largest_Row=Row_Start;
		      Largest_Col=Col_Start;
		      Largest_Direction=queue[i];
		      //  cout<<"Largest Room: "<< largest<<" "<<Row_Start<<" "<<Col_Start<<queue[i]<<endl;
		    }
		  else if (largest==modules_found)
		    {
		      if (Col_Start<=Largest_Col)
			{
			  if (Largest_Col==Col_Start)
			    {
			      if (Largest_Row<Row_Start)
				{
				  largest=modules_found;
				  Largest_Row=Row_Start;
				  Largest_Col=Col_Start;
				  Largest_Direction=queue[i];
				  //  cout<<"Largest Room: "<< largest<<" "<<Row_Start<<" "<<Col_Start<<queue[i]<<endl;
	
		      

				}
			    }
			  else
			    {
			      largest=modules_found;
			      Largest_Row=Row_Start;
			      Largest_Col=Col_Start;
			      Largest_Direction=queue[i];
			      
			      //			    cout<<"Largest Room: "<< largest<<" "<<Row_Start<<" "<<Col_Start<<queue[i]<<endl;
			      
			      
			    }

			}
			


		    }

		}
     	
	    }
	}
    }
  if (Largest_Direction==1) {
    int Result_Row=Row_direction(Largest_Row,Largest_Direction);
    Largest_Direction=opposite(Largest_Direction);
   
  }
  else if (Largest_Direction==8) {
    int Result_Col=Col_direction(Largest_Col,Largest_Direction);
    Largest_Direction=opposite(Largest_Direction);
      
  }
  char D=' ';
  if (Largest_Direction==4) D='E'; 
  else D='N';
  fout<<largest<<endl;
  fout<<Largest_Row+1<<" "<<Largest_Col+1<<" "<<D<<endl;
  
  
}
int Visit_Modules(int Row_Start,int Col_Start)
{

  int queue[4]={0};
  int queue_count=0;
  int modules_found=1;
  if (Matrix[Row_Start][Col_Start].Visited) return 0;
  //Can go to west,east,south,North?
  for (int i=0;i<4;i++)
    {
      if (is_open(Matrix[Row_Start][Col_Start].Number,array_directions[i]))
	{
	  queue[queue_count]=array_directions[i];
	  queue_count++;
	}
    }
  
  for (int i=0;i<queue_count;i++)
    {
      //Mark this room as visited
      Matrix[Row_Start][Col_Start].Visited=1;
      //Recurse on the next module to the open direction
      int New_Row=Row_direction(Row_Start,queue[i]);
      int New_Col=Col_direction(Col_Start,queue[i]);
      modules_found=modules_found+Visit_Modules(New_Row,New_Col);
      //Matrix[Row_Start][Col_Start].Visited=0;
    }

  return modules_found;

}
int find_number_of_rooms()
{
  int room=0;
  for (int Row_Start=0;Row_Start<Row;Row_Start++)
    {
      for (int Col_Start=0;Col_Start<Col;Col_Start++)
	{
	  //cout<<"Module Position: "<<Row_Start<<" "<<Col_Start<< " Queue Count" <<queue_count<<" Number: "<<Matrix[Row_Start][Col_Start].Number<<endl;
	  // for each direction that the room could take
	  //print queue_count;
	  //cout<<"Queue Count: "<<queue_count<<endl;
	  if (Matrix[Row_Start][Col_Start].Visited) continue;
	  else
	    {
	      room++;
	      Visit_Modules(Row_Start,Col_Start);
	    }
	  
      
	}
    }
  return room;
  
}
      

int main()
{
  /*
- 1: wall to the west
- 2: wall to the north
- 4: wall to the east
- 8: wall to the south
   */
  read_input();
  clear_visited();
  int longest=0;
  int result=0;
  for (int i=0;i<Row;i++)
    {
      for (int j=0;j<Col;j++)
	{
	  result=find_longest_room(i,j);
	  clear_visited();
	  if (result>longest) longest=result;
	}
    }
  fout<<find_number_of_rooms()<<endl;
  clear_visited();
  fout<<longest<<endl;
  find_wall_to_be_removed();

  
}
