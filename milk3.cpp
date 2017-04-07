/*
ID: svasude2
PROG: milk3
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int Visited[9261]={0};
int Ca,Cb,Cc;
int A=0;
int B=0;
int C=0;
int Result[21]={0};

int is_visited(int A,int B,int C)
{
  int temp=Visited[A*(Cb+1)*(Cc+1) + B*(Cc+1) + C];
  Visited[A*(Cb+1)*(Cc+1) + B*(Cc+1) + C]=1;
  return temp;
}
void clear_visited(int A,int B,int C)
{
  
  Visited[A*(Cb+1)*(Cc+1) + B*(Cc+1) + C]=0;
  
}

ofstream fout ("milk3.out");
  ifstream fin ("milk3.in");

int perform(int action)
{
  /* Action 1: A->B
     Action 2: B->A
     Action 3: A->C
     Action 4: C->A
     Action 5: B->C
     Action 6: C->A
  */
  int remaining,temp_A,temp_B,temp_C;
  switch(action)
    {
    case 1:
      //if the buckets are full, Don't do anything
      temp_A=A;
      temp_B=B;
      if ((B==Cb)||(A==0)) return 0;
      else
	{
	  remaining=(Cb-temp_B);
	  if (A<=remaining)
	    {
	      temp_A=0;
	      temp_B+=A;
	    }
	  else
	    {
	      temp_A=temp_A-remaining;
	      temp_B=Cb;
	    }
	  //------------------------------------//
	  if (is_visited(temp_A,temp_B,C)) return 0;
	  else
	    {
	      A=temp_A;
	      B=temp_B;
	      return 1;
	    }
	}
	  
    case 2:
      temp_A=A;
      temp_B=B;
      if ((A==Ca)||(B==0)) return 0;
      else
	{
	  remaining=(Ca-temp_A);
	  if (B<=remaining)
	    {
	      temp_B=0;
	      temp_A+=B;
	    }
	  else
	    {
	      temp_B=temp_B-remaining;
	      temp_A=Ca;
	    }
	  //------------------------------------//
	  if (is_visited(temp_A,temp_B,C)) return 0;
	  else
	    {
	      A=temp_A;
	      B=temp_B;
	      return 1;
	    }
	}
      
    case 3://A->C
      temp_A=A;
      temp_C=C;
      if ((C==Cc)||(A==0)) return 0;
      else
	{
	  remaining=(Cc-temp_C);
	  if (A<=remaining)
	    {
	      temp_A=0;
	      temp_C+=A;
	    }
	  else
	    {
	      temp_A=temp_A-remaining;
	      temp_C=Cc;
	    }
	  //------------------------------------//
	  if (is_visited(temp_A,B,temp_C)) return 0;
	  else
	    {
	      A=temp_A;
	      C=temp_C;
	      return 1;
	    }
	}
    case 4://C->A
      temp_A=A;
      temp_C=C;
      if ((A==Ca)||(C==0)) return 0;
      else
	{
	  remaining=(Ca-temp_A);
	  if (C<=remaining)
	    {
	      temp_C=0;
	      temp_A+=C;
	    }
	  else
	    {
	      temp_C=temp_C-remaining;
	      temp_A=Ca;
	    }
	  //------------------------------------//
	  if (is_visited(temp_A,B,temp_C)) return 0;
	  else
	    {
	      A=temp_A;
	      C=temp_C;
	      return 1;
	    }
	}
    case 5://B->C
      temp_B=B;
      temp_C=C;
      if ((C==Cc)||(B==0)) return 0;
      else
	{
	  remaining=(Cc-temp_C);
	  if (B<=remaining)
	    {
	      temp_B=0;
	      temp_C+=B;
	    }
	  else
	    {
	      temp_B=temp_B-remaining;
	      temp_C=Cc;
	    }
	  //------------------------------------//
	  if (is_visited(A,temp_B,temp_C)) return 0;
	  else
	    {
	      B=temp_B;
	      C=temp_C;
	      return 1;
	    }
	}
      
    case 6://C->B
      temp_B=B;
      temp_C=C;
      if ((B==Cb)||(C==0)) return 0;
      else
	{
	  remaining=(Cb-temp_B);
	  if (C<=remaining)
	    {
	      temp_C=0;
	      temp_B+=C;
	    }
	  else
	    {
	      temp_C=temp_C-remaining;
	      temp_B=Cb;
	    }
	  //------------------------------------//
	  if (is_visited(A,temp_B,temp_C)) return 0;
	  else
	    {
	      B=temp_B;
	      C=temp_C;
	      return 1;
	    }
	}

      

    }
}
int level=0;
int print_state()
{
  fout<<A<<" "<<B<<" "<<C;
}
int insert_tabs()
{
  for (int i=0;i<level-1;i++)  fout<<"  ";
    
}
int reverse_action(int action)
{

  int remaining,temp_A,temp_B,temp_C;
  switch(action)
    {
            
    case 1:
      temp_A=A;
      temp_B=B;
      if ((A==Ca)||(B==0)) return 0;
      else
	{
	  remaining=(Ca-temp_A);
	  if (B<=remaining)
	    {
	      temp_B=0;
	      temp_A+=B;
	    }
	  else
	    {
	      temp_B=temp_B-remaining;
	      temp_A=Ca;
	    }
	  //------------------------------------//
	  
	  {
	      A=temp_A;
	      B=temp_B;
	      return 1;
	  }
	}
    case 2:
            //if the buckets are full, Don't do anything
      temp_A=A;
      temp_B=B;
      if ((B==Cb)||(A==0)) return 0;
      else
	{
	  remaining=(Cb-temp_B);
	  if (A<=remaining)
	    {
	      temp_A=0;
	      temp_B+=A;
	    }
	  else
	    {
	      temp_A=temp_A-remaining;
	      temp_B=Cb;
	    }
	  //------------------------------------//
	  
	    {
	      A=temp_A;
	      B=temp_B;
	      return 1;
	    }
	}

    case 3://A->C
      temp_A=A;
      temp_C=C;
      if ((A==Ca)||(C==0)) return 0;
      else
	{
	  remaining=(Ca-temp_A);
	  if (C<=remaining)
	    {
	      temp_C=0;
	      temp_A+=C;
	    }
	  else
	    {
	      temp_C=temp_C-remaining;
	      temp_A=Ca;
	    }
	  //------------------------------------//
	  
	  
	  A=temp_A;
	  C=temp_C;
	  return 1;
	  
	}

      
    case 4://C->A
      temp_A=A;
      temp_C=C;
      if ((C==Cc)||(A==0)) return 0;
      else
	{
	  remaining=(Cc-temp_C);
	  if (A<=remaining)
	    {
	      temp_A=0;
	      temp_C+=A;
	    }
	  else
	    {
	      temp_A=temp_A-remaining;
	      temp_C=Cc;
	    }
	  //------------------------------------//
	 
	 
	    {
	      A=temp_A;
	      C=temp_C;
	      return 1;
	    }
	}
    case 5://B->C
      temp_B=B;
      temp_C=C;
      if ((B==Cb)||(C==0)) return 0;
      else
	{
	  remaining=(Cb-temp_B);
	  if (C<=remaining)
	    {
	      temp_C=0;
	      temp_B+=C;
	    }
	  else
	    {
	      temp_C=temp_C-remaining;
	      temp_B=Cb;
	    }
	  //------------------------------------//

	    {
	      B=temp_B;
	      C=temp_C;
	      return 1;
	    }
	}


           
    case 6://C->B
      temp_B=B;
      temp_C=C;
      if ((C==Cc)||(B==0)) return 0;
      else
	{
	  remaining=(Cc-temp_C);
	  if (B<=remaining)
	    {
	      temp_B=0;
	      temp_C+=B;
	    }
	  else
	    {
	      temp_B=temp_B-remaining;
	      temp_C=Cc;
	    }
	  //------------------------------------//

	    {
	      B=temp_B;
	      C=temp_C;
	      return 1;
	    }
	}

      
      
    }
    

}
int search()
{
  level++;
  
  
  for (int action=1;action<=6;action++)
    {
      if(perform(action))
	{
	  //insert_tabs();
	  //fout<<level<<": ---->";
	  //print_state();
	  //fout<<"  Action:"<<action<<endl;
	  if (A==0) Result[C]=1; 
	  search();
	  clear_visited(A,B,C);
	  reverse_action(action);
	} 
    }
  level--;
}
int main()
{
    
  fin>>Ca>>Cb>>Cc;
   C=Cc;
  is_visited(A,B,C);
  
  search();
  A=0;
  B=0;
  
  int array[21]={0};
  Result[Cc]=1;
  int count=0;
  for (int i=0;i<21;i++)
    {
      if (Result[i]) array[count++]=i;
	  
    }
  for (int i=0;i<count;i++)
    {
      if (i==0) fout<<array[i];
      else fout<<" "<<array[i];
		  
	  
    }
  fout<<endl;
}
  
