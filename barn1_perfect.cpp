/*
ID: tausiq11
PROG: barn1
LANG: C++
*/
 
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main ()
{
    freopen ("barn1.in", "r", stdin);
    freopen ("barn1.out", "w", stdout);
 
    int m;
    int s;
    int c;
    int stalls [205];
 
    scanf ("%d %d %d", &m, &s, &c);
 
    for ( int i = 0; i < c; i++ )
        scanf ("%d", &stalls [i] );
 
    sort (stalls, stalls + c);
 
    int diff [205];
    int index = 0;
 
    for ( int i = 1; i < c; i++ )
        diff [index++] = (stalls [i] - stalls [i - 1]) - 1;
 
    sort (diff, diff + index);
 
    int minimize = 0;
    //cout<<"hi"<<endl;
    if ( index <= m - 1 ) {
        for ( int i = 0; i < index; i++ )
	  {
	    // cout<<diff[i]<<endl;
	    minimize += (diff [i]);

	  }
    }
 
    else {
        for ( int i = 0; i < m - 1; i++ )
	  {
	    
	    minimize += (diff [--index]);
	    cout<<diff[index]<<endl;
	  }
    }
    
    minimize = s - minimize;
    minimize -= stalls [0] - 1;
    minimize -= (s - stalls [c - 1]);
 
    printf ("%d\n", minimize);
    return 0;
}
