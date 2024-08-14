#include <algorithm>
#include <iostream>
using namespace std;
// binary_search/3findFirstAndLast_v2.cpp
int binarySearch(int arr[], int low, int high, int x) { // simple and fast
    int mid = 0;
    while ( low <= high) { // <= is important here if you search for value 2 in range (1,5)
        mid = (low + high) / 2; // in zero based indexing bid aligns towards left part
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int get_pivot(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] > arr[low]) {
            low = mid + 1;
        } else if (arr[mid] <= arr[low] && arr[mid] < arr[mid - 1]) {
            return mid;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int pivot_binary_search(int arr[], int n, int x) {
    int p = get_pivot(arr, n);
    if (p == -1) {
        return binarySearch(arr, 0, n - 1, x);
    } else if (arr[p] == x) {
        return p;
    } else if (arr[0] < n) {
        return binarySearch(arr, 0, p - 1, x);
    } else {
        return binarySearch(arr, p + 1, n - 1, x);
    }
}

int main() {
    int arr[]{5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int result = pivot_binary_search(arr, n, x);
    std::cout << result << std::endl;
    return 0;
}
