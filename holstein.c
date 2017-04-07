/*
ID:svasude2 
LANG: C
TASK:holstein 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VITAMINS 25
#define MAX_FEEDS 15
#define INT_MAX 214748347 
int Vitamins[MAX_VITAMINS]={0};
int Feeds[MAX_FEEDS][MAX_VITAMINS];
int Num_Vitamins,types_of_feeds ;
int Visited_feeds[MAX_FEEDS]={0};
int Current_feeds[MAX_FEEDS]={-1};
int Result_feeds[MAX_FEEDS]={0};
int previous_feeds[MAX_FEEDS]={0};
int level=0;
int largest=INT_MAX;
int count=0;
int queue_pointer=0;;
int length_queue=0;;
struct State
{
  short level;
  bool Visited_feeds[MAX_FEEDS];
  short feed;
  short Vitamins[MAX_FEEDS];
}state;
//struct State state;
int pp=0;
int head=0;
int stop=0;
struct State queue[100000];

struct State pop(void)
{
  struct State bro =queue[0];
  for (int i=1;i<length_queue;i++)
    queue[i-1]=queue[i];
  return bro;
}
int dfs(int feed)
{
  int flag=1;
  //printf("Feed %d, level %d\n ",previous_feeds[level-1],level);
  if (level>=largest) return 0;
  for (int i=0;i<Num_Vitamins;i++)
    if (Vitamins[i]>0) flag=0;
  if (flag==1)
    {
      //  printf("hi\n");
      largest=level;
      for (int k=0;k<largest;k++)
	Result_feeds[k]=previous_feeds[k];
    }
  for (int i=feed+1;i<types_of_feeds;i++)
    {
      if (!Visited_feeds[i])
	{
	  for (int j=0;j<Num_Vitamins;j++)
	    Vitamins[j]-=Feeds[i][j];
	  previous_feeds[level]=i;
	  Visited_feeds[i]=1;
	  level++;
	  count++;
	  // printf("%d\n",count);
	  dfs(i);
	  level--;
	  Visited_feeds[i]=0;
	  for (int j=0;j<Num_Vitamins;j++)
	    Vitamins[j]+=Feeds[i][j];
	}
      
    }



}
void main (void)
{
  FILE *fin  = fopen ("holstein.in", "r");
  FILE *fout = fopen ("holstein.out", "w");
  
  fscanf (fin, "%d", &Num_Vitamins);/* the two input integers */
  for (int i=0;i<Num_Vitamins;i++) fscanf (fin, "%d", &Vitamins[i]);/* the two input integers */
  fscanf (fin, "%d", &types_of_feeds);
  for (int i=0;i<types_of_feeds;i++)
    {
      for (int j=0;j<Num_Vitamins;j++)
	{
	  fscanf (fin, "%d", &Feeds[i][j]);
	}
    }
  
  dfs(-1);
  fprintf (fout, "%d",largest);
  for (int i=0;i<largest;i++)
   fprintf (fout, " %d",Result_feeds[i]+1);
  
  
  
  
  fprintf (fout, "\n");
  exit (0);
}
