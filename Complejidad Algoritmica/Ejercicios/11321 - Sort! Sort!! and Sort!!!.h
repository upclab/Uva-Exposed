#include<bits/stdc++.h>
using namespace std;

int  mod;
int N,d;

bool orden(int a, int b){

    if(a%mod != b%mod)
       return a%mod < b%mod;
    else{
        if(a%2 == 0 && b%2 == 0)
          return a<b;
        else if(a%2 != 0 && b%2 != 0)
                return a>b;
        else if(a%2 != 0)
                return true;
        else
            return false;
    }
}

int ejecutar(){

    while(cin>>N>>mod){
        cout<<N<<" "<<mod<<endl;
        if(!N && !mod)
           break;
        vector<int> vec;
        for(int x=1; x<=N; x++){
            cin>>d;
            vec.push_back(d);
        }
        sort(vec.begin(),vec.end(),orden);
        for(int y=0; y<vec.size(); y++)
            cout<< vec[y]<<endl;
    }
    return 0;
}
