#include <stdio.h>
#define MAXN 200000
void main () {
  FILE *in, *out;
  long num[MAXN], bestrun[MAXN];
  long n, i, j,k,highestrun = 0;
  in = fopen ("input.txt", "r");
  out = fopen ("output.txt", "w");
  fscanf(in, "%ld", &n);
  for (i = 0; i < n; i++) fscanf(in, "%ld", &num[i]);
  bestrun[0] = num[n-1];
  highestrun = 1;
  for (i = n-1-1; i >= 0; i--) {
    if (num[i] < bestrun[0]) {
      bestrun[0] = num[i];
      continue;
    }
    /*printf("1 \n");
    for (k=0;k<highestrun;k++)
      {
	printf("%ld ", bestrun[k]);
      }
    printf("\n");

    printf("2\n");*/

    for (j = highestrun - 1; j >= 0; j--) {
      if (num[i] > bestrun[j]) {
	if (j == highestrun - 1 || num[i] < bestrun[j+1]){
	  bestrun[++j] = num[i];
	  if (j == highestrun) highestrun++;
	  break;
	}
      }
    }
    for (k=0;k<highestrun;k++)
      {
	printf("%ld ", bestrun[k]);
      }
    printf("\n");
  }
  printf("best is %ld\n", highestrun);
  // exit(0);
}
