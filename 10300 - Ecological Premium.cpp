#include <iostream>
using namespace std;

int nc,ng,e,an,amistad,suma;

int main(){

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
