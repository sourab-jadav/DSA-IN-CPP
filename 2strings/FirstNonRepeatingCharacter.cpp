#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
string FirstNonRepeating(string str){
    string result="";
    vector<char>v;
    unordered_map<char, int>mp;

    for(auto c:str){
        // the idea is we check if it is not present in the map 
        // if it not present then we include it and add it to the result
        if (mp.find(c)==mp.end()) {
            v.push_back(c);
            mp[c]=1;
        }else {
             // we come here when there is element in the map
             // it is possible that we have added this element to the vector as part of 
             // first occurence since at this i it is no longer a first occurence so we 
             // remove it from the vector

             // get the index 
            int index=find(v.begin(),v.end(),c)-v.begin();
            if (index<v.size()) {
                v.erase(v.begin()+index);
            }
        }
        result+=(v.empty()?'#':v.front());
    }
    return result;
}
int main()
{
    string A = "geeksforgeeksandgeeksquizfor";
    string ans = FirstNonRepeating(A);
    cout << ans << endl;
}
