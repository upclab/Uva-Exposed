#include<bits/stdc++.h>
using namespace std;
vector<long long int> vec;
vector<int>valores;
int p,q;
int rep,pot2=1;

void alg(long long int x,int v){

    if(v==p){
        if(x%valores[q]==0) vec.push_back(x);
        return;
    }

    alg(x*10+1,v+1);
    alg(x*10+2,v+1);
}


int main(){

    for(int i=0;i<19;i++){
        valores.push_back(pot2);
        pot2*=2;
    }

    cin>>rep;
    for(int i=1;i<=rep;i++){
        cin>>p>>q;
        vec.clear();
        alg(0,0);

        if(vec.size()==0) cout<<"Case "<<i<<": impossible\n";
        else if(vec.size()==1) cout<<"Case "<<i<<": "<<vec[0]<<endl;
        else cout<<"Case "<<i<<": "<<vec[0]<<" "<<vec[vec.size() -1 ]<<endl;
    }
}
