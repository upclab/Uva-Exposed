#include <iostream>

using namespace std;

int ejecutar(){
    int a , b;
    while(cin>>a>>b)
        cout<<( a ^ b )<<endl;

    return 0;
}
/*
LINK: https://uva.onlinejudge.org/external/104/10469.pdf
INPUT
4 6
6 9OUTPUT
2
15
*/
