#include <bits/stdc++.h>

using namespace std;
int main() {
  string str = "ynyo";
  int n = str.length();
  vector<char> s;
  int result = 0;
  std::cout<<"hello world"<<std::endl;
  for (int i = 0; i < n; i++) {
    if (find(s.begin(), s.end(), str[i]) == s.end()) {
      s.push_back(str[i]);
      result = max(result, (int)s.size());
    } else {
      auto it = find(s.begin(), s.end(), str[i]);

      it++;
      s.erase(s.begin(), it);
      s.push_back(str[i]);
    }
  }
  cout << result;
  return 0;
}
