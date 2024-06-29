// #include <iostream>
// #include <vector>
// #include <string>
// // https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/
// using namespace std;
// int main() {
//
//     return 0;
// }
//
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int transform(string A, string B)
{
	if (A.length() != B.length()) {
		return -1;
	}

	// create a map to store the frequency of characters in string A
	unordered_map<char, int> m;
	int n = A.length();
	for (int i = 0; i < n; i++) {
		if (m.count(A[i])) // if the character already exists in the map
			m[A[i]]++;	 // increment its frequency
		else
			m[A[i]] = 1; // add the character to the map with a frequency of 1
	}

	// subtract the frequency of characters in string B from the map
	for (int i = 0; i < n; i++) {
		if (m.count(B[i]))
			m[B[i]]--;
	}

	// check if all the frequencies in the map are 0, indicating equal frequency of characters in both strings
	for (auto it : m) {
		if (it.second != 0) // if frequency is not zero
			return -1;	 // strings cannot be transformed into each other, return -1
	}

	// calculate the minimum number of operations required to transform string A into string B
	int i = n - 1, j = n - 1;
	int res = 0;
	while (i >= 0 && j >= 0) {
		while (i >= 0 && A[i] != B[j]) {
			res++; // increment the number of operations required
			i--;	 // move the pointer i to the left // okay we are only doing i-- here
		}
		i--;
		j--;
	}
return res; // returning result
}

// Driver code
int main()
{
	string A = "EACBD";
	string B = "EABCD";
    unordered_map<char, int>map{{'A',3},{'A',4},{'X',5}};
    std::cout<<map.count('A')<<std::endl;
    for(auto x:map){
        std::cout<<x.first<<" "<<x.second<<std::endl;
    }

	// cout << "Minimum number of operations required is " << transform(A, B) << endl;
	return 0;
}

