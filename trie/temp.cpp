#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// createing an array of size 3*2 and initializing with 0 value using memset 

int main() {
    vector<vector<int>>vec;
    vector<int>temp;
    temp.push_back(1);
    temp.push_back(2);
    vec.push_back(temp);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

}

