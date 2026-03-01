#include <iostream>
using namespace std;
int ceil(int arr[], int n, int value) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value && mid + 1 <= n - 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
int floor(int arr[], int n, int value) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value && mid - 1 >= 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int binary_search(int arr[], int n, int value) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[]{10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value;
    std::cout << "enter the value" << std::endl;
    cin >> value;
    int ceil_value = ceil(arr, n, value);
    int floor_value = floor(arr, n, value);
    std::cout << "ceil value of the " << value << " is " << arr[ceil_value] << std::endl;
    std::cout << "floor value of the " << value << " is " << arr[floor_value] << std::endl;
    int index=binary_search(arr, n, value);
    std::cout<<"value found at index "<<index<<std::endl;
    return 0;
}
