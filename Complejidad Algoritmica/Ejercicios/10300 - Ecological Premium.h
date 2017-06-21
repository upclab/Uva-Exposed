#include <iostream>
using namespace std;

int nc,ng,e,an,amistad,suma;

int ejecutar(){

    cin>>nc;

    while(nc--){
        suma = 0;
        cin>>ng;
        for(int i = 0 ; i<ng ; i++){
            cin>>e>>an>>amistad;
            suma+=(e*amistad);
        }
        cout<<suma<<endl;
    }


    return 0;
}
/*
LINK: https://uva.onlinejudge.org/external/103/10300.pdf
INPUT
3
5
1 1 1
2 2 2
3 3 3
2 3 4
8 9 2
3
9 1 8
6 12 1
8 1 1
3
10 30 40
9 8 5
100 1000 70OUTPUT
38
86
7445
*/
