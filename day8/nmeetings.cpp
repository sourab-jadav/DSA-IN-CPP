#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

// the idea is to sort based on the ascending order of the start time // wrong
// thought process

// understand the question:the question is maximum meeting should be conducted
// only one meeting can occur at a time
// think?maximum meetings can occur if the duration of each meeting is less
// i.e end-start of each meeting should be minimum ,as start will always be less
// than end ,end should be minimum so sort the arrays in the ascending order of
// ending time count all those intervals that do not overlap

struct meeting {
    int start;
    int end;
    int pos;
};

typedef struct meeting meeting;

bool comparator(meeting m1, meeting m2) { return m1.end < m2.end; }

void findingMaxMeetings(int s[], int e[], int n) {
    meeting meet[n];
    for (int i = 0; i < n; i++) {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
    }
    std::sort(meet, meet + n, comparator);
    // consider all those meetings that are non overlapping
    int limit = meet[0].end;
    std::vector<int> ans;
    ans.push_back(meet[0].pos);
    for (int i = 1; i < n; i++) {
        if (meet[i].start > limit) {
            ans.push_back(meet[i].pos);
            limit = meet[i].end;
        }
    }
    for (auto &x : ans) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    // std::cout << "Hello, World!" << std::endl;
    // // int arr1[]={0,1,3,5,5,8};
    // // int arr2[]={5,2,4,7,9,9};
    // int arr1[] = {8, 5, 3, 1, 5, 0};
    // int arr2[] = {9, 9, 4, 2, 7, 5};
    // // implementing selection sort on an array
    // int n = 6;
    // for (int i = 0; i < n; i++) {
    //   int min = i;
    //   for (int j = i + 1; j < n; j++) {
    //     if (arr1[j] < arr1[min]) {
    //       min = j;
    //     }
    //   }
    //   std::swap(arr1[i], arr1[min]);
    //   std::swap(arr2[i], arr2[min]);
    // }
    // for (int i = 0; i < 6; i++) {
    //   std::cout << arr1[i] << " ";
    // }
    // std::cout << std::endl;
    // for (int i = 0; i < 6; i++) {
    //   std::cout << arr2[i] << " ";
    // }
    // std::cout << std::endl;
    // int count = 1;
    // int maxCount = INTMAX_MIN;
    // std::cout<<INTMAX_MAX<<std::endl;
    // std::cout << maxCount << std::endl;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};

    findingMaxMeetings(start, end, n);
    return 0;
}
