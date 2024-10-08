#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
#define printxyz(arr, rows, cols)                                              \
  do {                                                                         \
    std::cout << std::endl;                                                    \
    for (int i = 0; i < rows; ++i) {                                           \
      for (int j = 0; j < cols; ++j) {                                         \
        std::cout << arr[i][j] << " ";                                         \
      }                                                                        \
      std::cout << std::endl;                                                  \
    }                                                                          \
    std::cout << std::endl;                                                    \
  } while (0)
#define printarray(arr, n)                                                     \
  std::cout << std::endl;                                                      \
  for (int i = 0; i < n; ++i) {                                                \
    std::cout << arr[i] << " ";                                                \
  }                                                                            \
  std::cout << std::endl;

// A job has start time, finish time and profit.
struct Job {
    int start, finish, profit;
};

int solve(Job arr[], int i, int low, int high, int n) {
    if (i == n) {
        return 0;
    }
    // the funda of including the current job and not including the current job
    // if you include the currrent job you add it's value
    //  - you will include only if it does not overlap with the interval of low
    //  and high
    // if you don't include the current job just do i+1
    int include = 0;
    int exclude = 0;
    if (low==-1) {
        include=solve(arr, i+1, arr[i].start, arr[i].finish, n)+arr[i].profit;
    }
    else if (arr[i].start >= high) {
        include = max(solve(arr, i + 1, min(arr[i].start, low), max(arr[i].finish, high), n) + arr[i].profit, solve(arr, i + 1, low, high, n));
    }
    exclude = solve(arr, i + 1, low, high, n);
    return max(include, exclude);
}
int findMaxProfit(Job arr[], int n) {
    return max(solve(arr, 1, arr[0].start, arr[0].finish, n) + arr[0].profit,
            solve(arr, 1, -1, -1, n));
}
bool jobComparator(Job j1, Job j2) { return j1.start <= j2.start; }
void printJobs(Job arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i].start << " " << arr[i].finish << " " << arr[i].profit
            << std::endl;
    }
}
int main() {
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, jobComparator);
    printJobs(arr, n);
    // sorting based on ascending order is needed here
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}
