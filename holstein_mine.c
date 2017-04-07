/*
USER: jack.ne1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define CODE_WORKS false
using namespace std;

int V, G;
vector<int> vitamins;
vector<vector<int> > feeds;

string bestSolut = "";
int bestVal = 0;

bool fufill(string key){
  int quants[V];
  for(int i = 0; i < V; i++) quants[i] = 0;
  for(int i = 0; i < key.length(); i++){
    int feedNum = key[i] - '1';
    for(int j = 0; j < V; j++) quants[j] += feeds[feedNum][j];
  }
  for(int i = 0; i < V; i++){
    if(quants[i] < vitamins[i]) return false;
  }
  return true;
}

int val(string s){
  int result;
  for(int i = 0; i < s.length(); i++){
    result += s[i] - '0';
  }
  return result;
}

void combos(string key){
  if(fufill(key)){
    if(bestSolut == ""){
      bestSolut = key;
      bestVal = val(key);
    }
    else if((key.length() < bestSolut.length()) || (key.length() == bestSolut.length() && val(key) < bestVal)){
      bestSolut = key;
      bestVal = val(key);
    }
    return;
  }
  else{
    for(int i = 0; i < G; i++){
      if(i + '1' > key[key.length() - 1]){
	string add = "";
	add += (i + '1');
	combos(key + add);
      }
    }
  }
}

int main(){
  ifstream in("holstein.in");
  ofstream out("holstein.out");

  in >> V;

  vitamins.resize(V);
  for(int i = 0; i < V; i++) in >> vitamins[i];

  in >> G;

  feeds.resize(G);
  for(int i = 0; i < G; i++){
    feeds[i].resize(V);
    for(int j = 0; j < V; j++) in >> feeds[i][j];
  }

  combos("");

  vector<int> solut(bestSolut.length());
  for(int i = 0; i < bestSolut.length(); i++) solut[i] = bestSolut[i];
  sort(solut.begin(), solut.begin() + solut.size());
  out << solut.size() << " ";
  for(int i = 0; i < solut.size(); i++){
    out << solut[i] - '0';
    if(i != solut.size() - 1) out << " ";
  }
  out << endl;
}
