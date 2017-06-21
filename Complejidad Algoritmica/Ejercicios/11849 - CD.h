#include<iostream>
#include<map>

using namespace std;


int ejecutar(){

    long long m,n,cd,cnt;
    map<long, long>mp;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
        return 0;
        cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>cd;
            mp[cd]=1;
        }

        for(int i=0;i<m;i++)
        {
            cin>>cd;
            if(mp[cd]==1)
             cnt++;
        }

        mp.clear();
        cout<<cnt<<endl;
    }

return 0;
}
/*
LINK: https://uva.onlinejudge.org/external/118/11849.pdf
INPUT
3 3
1
2
3
1
2
4
0 0OUTPUT
2
*/
