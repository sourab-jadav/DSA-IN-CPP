#include<bits/stdc++.h>

using namespace std;
void printpermutation(string &str,int i=0){
    if(i==str.length()-1){
        cout<<str<<" ";
        return;
    }
    for(int j=i;i<str.length();j++){
        swap(str[i],str[j]);
        printpermutation(str,i+1);
        swap(str[i],str[j]);
    }
    
}

int main(){
    string str="abcd";
    
    printpermutation(str,0);
    return 0;
}

