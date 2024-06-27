#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    // to check if a string is anagram // this is working
    //
    // string str1="abcde";
    // string str2="cabde";
    // std::cout<<"checking if one string is anagram of  another"<<std::endl;
    // unordered_set<char>st(str1.begin(),str1.end());
    // bool flag=true;
    // for (auto c  : str2) {
    //     if (st.find(c)==st.end()) {
    //         std::cout<<"no they are not anagram"<<std::endl;
    //         flag=false;
    //         break;
    //     }
    // }
    // if (flag) {
    //     std::cout<<"they are anagram"<<std::endl;
    // }

    vector<string> vec{"act", "god", "cat", "dog", "tac"};
    // this approach is failed
    // int n=vec.size();
    // vector<string>r1;
    // vector<vector<string>>result;
    // r1.push_back(vec[0]);
    // result.push_back(r1);
    //
    // for(int i=1;i<n;i++){
    //     string temp=vec[i];
    //     unordered_set<char>ust(temp.begin(),temp.end());
    //     bool flag=true;
    //     for (auto group : result) {
    //         string temp2=group[0];
    //         for (auto c : temp2) {
    //             if (ust.find(c)==ust.end()) {
    //                 flag=false;
    //                 break;
    //             }
    //         }
    //         // here if flag is true this means that the matching group is found
    //         if (flag) {
    //             group.push_back(temp);
    //             continue;
    //         }
    //     }
    //     // traversing through all the groups and the group is not found means
    //     flag is false if (!flag) {
    //          // we create a new group and push the temp into it
    //         result.push_back(vector<string>{temp});
    //     }
    // }
    //

    // let's try another apporach which is using o of n2 time coplexity // making it into groups this is working as well
    vector<vector<string>> result;
    vector<bool> visited(vec.size(), false);
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        // printing all the possible anagrams
        if (!visited[i]) {
            visited[i] = true;
            vector<string> r;
            r.push_back(vec[i]);
            unordered_set<char> st(vec[i].begin(), vec[i].end());
            for (int j = i + 1; j < n; j++) {
                if (!visited[j]) {
                    bool flag = true;
                    for (auto c : vec[j]) {
                        if (st.find(c) == st.end()) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        visited[j] = true;
                        r.push_back(vec[j]);
                    }
                }
            }
            result.push_back(r);
            r.clear();
        }
    }
    std::cout << "the groups are as follows:" << std::endl;

    for (auto group : result) {
        std::cout << "[ " << " ";
        for (auto x : group) {
            std::cout << x << " ";
        }
        std::cout << " ]" << std::endl;
    }

    return 0;
}
