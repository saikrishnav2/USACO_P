/*
ID: svasude42
PROG: namenum
LANG: C++    
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <sstream>
using namespace std;

string convertInt(int number){
  stringstream ss;//create a stringstream
  ss << number;//add number to the stream
  return ss.str();//return a string with the contents of the stream
}

string to_num(string str){
  string to_num = "";

  vector<string> a(8);
  a[0] = "ABC";
  a[1] = "DEF";
  a[2] = "GHI";
  a[3] = "JKL";
  a[4] = "MNO";
  a[5] = "PRS";
  a[6] = "TUV";
  a[7] = "WXY";

  for(int i = 0; i < str.length(); i++){
    for(int j = 0; j < 8; j++){
      for(int k = 0; k < 3; k++){
	if(str[i] == a[j][k]){
	  to_num += convertInt(j + 2);
	  break;
	}
      }
    }
  }
  return to_num;
}

int main(){
  ifstream in("namenum.in");
  ifstream dict("dict.txt");
  ofstream out("namenum.out");

  string num;
  in >> num;

  bool atlone = false;
  for(int g = 0; g < 5000; g++){ //this many names
    string curr_name;
    dict >> curr_name;
    if(curr_name == ""){
      break;
    }
    if(to_num(curr_name) == num){
      out << curr_name << endl;
      atlone = true;
    }
  }
  if(!atlone){
    out << "NONE" << endl;
  }
}


