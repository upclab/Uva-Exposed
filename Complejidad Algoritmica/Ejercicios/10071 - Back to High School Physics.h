#include <iostream>
using namespace std;

int v,t;

int ejecutar(){
    while(cin>>v>>t){

    if (v==0)
        cout<<"0"<<endl;
    else
        cout<<2*v*t<<endl;

    }
    return 0;
}
/*
LINK: https://uva.onlinejudge.org/external/100/10071.pdf
INPUT
0 0
5 12OUTPUT
0
120
*/
