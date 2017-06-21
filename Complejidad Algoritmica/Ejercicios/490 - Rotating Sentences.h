#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int m = 0;
string l;
vector<string> arr;

int ejecutar() {

    while(getline(cin, l)) {
    if(l == "x") break;
        arr.push_back(l);
        m = max(m, int(l.length()));
    }

    for(int i = 0; i < m; i++) {

        for(int j = arr.size() - 1; j >= 0; j--) {

        if(i < arr[j].length())
                cout<<arr[j][i];
        else
                cout<<" ";

        }
        cout<<endl;
    }

    return 0;
}
