#include <algorithm>
#include <cstdint>
#include <iostream>

// one solution is brute force count overlapping intervals
// other solution is two pointer and sorting

int main() {
  std::cout << "Hello, World!" << std::endl;
  int arr[] = {900, 945, 955, 1100, 1500, 1800};
  int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
  // we have to arrival and departure time
  int n = sizeof(arr) / sizeof(arr[0]);
  std::cout << "size of arr is " << n << std::endl;
  int result = 1;
  for (int i = 0; i < n; i++) {
    int count = 1;
    for (int j = i + 1; j < n; j++) {
      // in the arrival
      // if the element appears after the current arrival
      // check if it is less than that current departure
      //
      // if the element appears before the current arrival
      // check the departure of that element is greater than current arrival

      if ((arr[j] >= arr[i] && arr[j] <= dep[i]) ||
          (arr[j] <= arr[i] && arr[i] <= dep[j])) {
        count++;
      }
    }
    result = std::max(result, count);
  }
  std::cout << "the result is " << result << std::endl;
  return 0;
}
