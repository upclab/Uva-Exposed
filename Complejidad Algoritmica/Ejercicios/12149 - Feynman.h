#include <bits/stdc++.h>
using namespace std;

int ejecutar(){
    int n;
    while(cin>>n){
        if(n==0) break;
        cout<<( ( n*(n+1) * (2*n+1) ) / 6) <<endl;
    }
}
