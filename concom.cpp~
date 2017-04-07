/*
USER: svasude2
PROG: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#define CODE_WORKS true
using namespace std;

ifstream in("concom.in");
ofstream out("concom.out");

int main(){
  int s[101][101], v[101][101];
  memset(s, 0, sizeof(s));
  memset(v, 0, sizeof(v));

  int i, j, k, a, b, p, N;
  in >> N;
  for(i = 0; i < N; i++){
    in >> a >> b >> p;
    s[a][b] = p;
  }

  for(i = 1; i < 101; i++){
    for(j = 1; j < 101; j++){
      if(i != j && !v[i][j] && s[i][j] > 50){
	v[i][j] = 1;
	for(k = 1; k < 101; k++){
	  s[i][k] += s[j][k];
	  if(v[j][k]) v[i][k] = 1;
	}
	j = 0;
      }
    }
  }

  for(i = 1; i < 101; i++){
    for(j = 1; j < 101; j++){
      if(i != j && v[i][j]) out << i << " " << j << endl;
    }
  }
}
