#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/
// understand backtracking problems
int main() {
    bool visited[26]{};
    memset(visited, false, sizeof(visited));
    string str="GACCBGDDBAEE";
    vector<int>waiting;
    int M=3;
    int count =0;
    // this solution does not worked let's try another approach
    // int count=0;
    // int compNum=1;
    // int result=0;
    // for(int i=0;i<str.length();i++){
    //     // alloting the computer
    //     if (count>=compNum && !arr[str[i]-'A']) {
    //         std::cout<<str[i]<<" ";
    //         arr[str[i]-'A']=true;
    //         result++;
    //     }else if (arr[str[i]-'A']) {
    //         arr[str[i]-'A']=false;
    //         count--;
    //     }else if (!arr[str[i]-'A'] && count<compNum) {
    //         arr[str[i]-'A']=true;
    //         count++;
    //     }
    // }

    for(int i=0;i<str.length();i++){ // this is a working solution we can optimize it we talk about that later
        if (!visited[str[i]-'A'] && count <M ) {
            count++;
            visited[str[i]-'A']=!visited[str[i]-'A'];
        }else if (!visited[str[i]-'A']) {
            visited[str[i]-'A']=true;
            std::cout<<str[i]<<" ";
            waiting.push_back(str[i]);
        }else if (find(waiting.begin(),waiting.end(),str[i])!=waiting.end()) {
            visited[str[i]-'A']=false;
            waiting.erase(find(waiting.begin(),waiting.end(),str[i]));
        }else if (visited[str[i]-'A']&& count >0) {
            visited[str[i]-'A']=false;
            count--;
        }
         
    }

    return 0;
}


