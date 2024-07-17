#include <algorithm>
#include <climits>
#include <iostream>
// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays
using namespace std;
// this below code has passed all the test cases
int main() {
    // long long arr[]{10,4,5,7,6,10,6};
    long long arr[]{8, 6, 1, 6, 2, 10, 10, 8, 3, 6, 4, 4, 7};
    long long n = sizeof(arr) / sizeof(arr[0]);
    long long sum = 0;
    long long s, ss, si, ssi;
    // just start fresh and get the fucking answer
    if (arr[0] < arr[1]) {
        s = arr[0];
        si = 0;
        ss = arr[1];
        ssi = 1;
    } else {
        s = arr[1];
        si = 1;
        ss = arr[0];
        ssi = 0;
    }
    sum = s + ss;
    std::cout << "initially" << std::endl;
    std::cout << " s: " << s << " ss: " << ss << std::endl;

    for (int i = 2; i < n; i++) { // let's complicate it for fun
        std::cout << "for value " << arr[i] << std::endl;
        if (arr[i] == s || arr[i] == ss) {
            if (si > ssi) {
                ssi = i;
            } else {
                si = i;
            }
            s = arr[si];
            ss = arr[ssi];
            std::cout << " s: " << s << " ss: " << ss << std::endl;
        } else if (arr[i] > s && arr[i] > ss) {
            if (ssi > si) {
                si = ssi;
                ssi = i;
            } else {
                ssi = i;
            }
            s = arr[si];
            ss = arr[ssi];
            std::cout << " s: " << s << " ss: " << ss << std::endl;
        } else if (arr[i] > s && arr[i] < ss) {
            if (si > ssi) {
                ssi = i;
            } else {
                si = i;
            }
            s = arr[si];
            ss = arr[ssi];
            std::cout << " s: " << s << " ss: " << ss << std::endl;
        } else if (arr[i] < s) {
            if (si > ssi) {
                ssi = si;
                si = i;
            } else {
                si = i;
            }
            s = arr[si];
            ss = arr[ssi];
            std::cout << " s: " << s << " ss: " << ss << std::endl;
        }
        sum = max(sum, s + ss);
    }
    std::cout << sum << std::endl;
}
// the other way of solving the same solution is finding the max consecutive
// consecutive sum of two numbers
