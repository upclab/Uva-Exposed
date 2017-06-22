#include<iostream>

using namespace std;


int ejecutar(){
    int n;

	while(cin>>n){
		if(n==0) break;
		cout<<( ( n*(n+1) * (2*n+1) ) / 6) <<endl;
	}

	return 0;
}
/*
LINK: https://uva.onlinejudge.org/external/121/12149.pdf
INPUT
2
1
8
0OUTPUT
5
1
204
*/
