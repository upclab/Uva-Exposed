#include<iostream>
#include<vector>
#include<algorithm>

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
/*
LINK: https://uva.onlinejudge.org/external/104/10469.pdf
INPUT
15 3
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
0 0OUTPUT
15 3
15
9
3
6
12
13
7
1
4
10
11
5
2
8
14
0 0
*/
