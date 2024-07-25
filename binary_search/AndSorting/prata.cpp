#include <iostream>
#include <string>
#include <vector>
using namespace std;
// https://www.spoj.com/problems/PRATA/
/*
    This problem uses binary search approach , as answer is monotonic function .
   ( of true and false on time ). By applying binary search on time , we get the
   answer.
*/
// for the ispossible function
// the idea is to calculate for a given time how many pratas can each cook
// contributes
//
// at any point if number of contributions are greater than or equal to p we return true
// else we return false;
bool ispossible(int arr[], int n, int time, int p) {

    // for the given time calculate how much prata's each cook can contribute

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // get the time taken for each cook
        int timeWeHave = time;
        int adder = arr[i];
        int count = 0;
        while (timeWeHave > 0) {
            timeWeHave = timeWeHave - adder;
            if (timeWeHave >= 0) {
                count++;
                adder += arr[i];
            }
        }
        cnt += count;
        if (cnt >= p) {
            return true;
        }
    }
    return false;
}

int main() {
  int arr[]{1, 2, 3, 4};
