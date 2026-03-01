#include<bits/stdc++.h>

using namespace std;

int main(){
    string str="ababc";
    int n=str.length();
    int result={};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(str[j]=str[i]){
                string proper_prefix=str.substr(i,j-i);
                string proper_suffix=str.substr(j,proper_prefix.length());
                if(proper_prefix==proper_suffix){
                    result=max(result,(int)proper_prefix.length());
                }
            }
        }
    }
    cout<<result<<endl;
    
    return 0;
}