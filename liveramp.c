#include <stdio.h>
#include <stdlib.h>
int digits[4]={0};
int visited_pos[4]={0};
short cur=0;
int Max=0;
int valid_hour(int number)
{
  if ((number/100)<24) return 1;
  else return 0;


}
int valid_min(int number)
{
  if (number%100<60) return 1;
  else return 0;

}

void dfs(int digit,int pos)
{
  
  if (pos==1)
    { cur+=1000*digit;printf("%d %d %d\n",digit,pos,cur);
      for (int i=0;i<4;i++) printf("%d ",visited_pos[i]);
      printf("\n");
    }
  else if (pos==2)
    {
      cur+=100*digit;
      printf("%d %d %d\n",digit,pos,cur);
    
      for (int i=0;i<4;i++) printf("%d ",visited_pos[i]);
      printf("\n");
      if (!valid_hour(cur)) return ;
    }
  else if (pos==3)
    {
      cur+=10*digit;
      printf("%d %d %d\n",digit,pos,cur);
     
      for (int i=0;i<4;i++) printf("%d ",visited_pos[i]);
      printf("\n");
    }
  else if (pos==4)
    {
      cur+=digit;
      printf("%d %d %d\n",digit,pos,cur);
      for (int i=0;i<4;i++) printf("%d ",visited_pos[i]);
       printf("\n");
      if (!valid_min(cur)) return;
      if (cur>Max) Max=cur;
      // cur-=digit;
      //printf("ur %d \n",cur);
      return;
    }
  
 
  for (int i=0;i<4;i++)
    {
      if (!visited_pos[i]){
	visited_pos[i]=1;
	dfs(digits[i],pos+1);
	visited_pos[i]=0;

	if (pos+1==1) cur-=1000*digits[i];
	else if (pos+1==2) cur-=100*digits[i];
	else if (pos+1==3) cur-=10*digits[i];
	else if (pos+1==4) cur-=digits[i];
      }
    }

}



int main(void)
{

  FILE *fin  = fopen ("liveramp.in", "r");
  FILE *fout = fopen ("liveramp.out", "w");
  for (int i=0;i<4;i++)  fscanf (fin, "%d", &digits[i]);
  //visited_pos[0]=1;
  dfs(0,0);
  printf("%d \n",Max);







}
