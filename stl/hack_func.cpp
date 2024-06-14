#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Person {
    string name;
    int age;
    Person(string name, int age) : name(name), age(age) {}
};
// let's practice some handy stl functions and classes in c++ present in the algorithm library
// we will use the following functions and classes:
// 1. sort
// 2. max
// 3. min
// 4. swap
// 5. reverse
// 6. rotate
// 7. next_permutation
// 8. prev_permutation
// 9. accumulate
// 10. count
// 11. count_if
// 12. find
// 13. find_if
// 14. binary_search
// 15. lower_bound
// 16. upper_bound
// 17. equal_range
// 18. merge
// 19. set_union
// 20. set_intersection
// 21. set_difference
// 22. set_symmetric_difference
// 23. make_heap
// 24. push_heap
// 25. pop_heap
// 26. sort_heap
// 27. is_heap
// 28. is_heap_until
// 29. is_sorted
// 30. is_sorted_until
// 31. nth_element
// 32. partition
// 33. stable_partition
// 34. random_shuffle
// 35. shuffle
// 36. sample
// 37. unique
// 38. unique_copy
// 39. reverse_copy
// 40. rotate_copy
// 41. copy
// 42. copy_backward
// 43. move
// 44. move_backward
// 45. fill
// 46. fill_n
// 47. generate
// 48. generate_n
// 49. replace
// 50. replace_if
// 51. replace_copy
// 52. replace_copy_if
// 53. swap_ranges
// 54. iter_swap
// 55. transform
// 56. for_each
// 57. equal
// 58. mismatch
// 59. lexicographical_compare
// 60. is_permutation
// 61. search
// 62. search_n
// 63. min_element
// 64. max_element
// 65. minmax_element
//  
int main() {
    // sort function
    //  Let's start with the sort function
    // 1. sort
    // sort function is used to sort the elements of a container in ascending order
    // it takes two iterators as arguments, the first iterator points to the first element of the container and the second iterator points to the last element of the container
    // the sort function uses the quicksort algorithm to sort the elements
    // the time complexity of the sort function is O(nlogn)
    // the space complexity of the sort function is O(logn)
    // the sort function is present in the algorithm library
    // the sort function is a stable sort
    // the sort function is a comparison sort
    // the sort function is a non-adaptive sort
    // the sort function is a non-recursive sort
    // the sort function is a comparison sort
    // example:
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    vector<vector<int>>vec{{1,3},{2,5},{7,1}};
    sort(vec.begin(),vec.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
            });
    for (auto x : vec) {
        std::cout<<x[0]<<" "<<x[1]<<std::endl;
    }
    std::cout<<std::endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    // sort(arr, arr + n, greater<int>());
    sort(arr, arr + n);
        
    // sorting with the lambda function
    sort(arr, arr + n, [](int a, int b) {
       return a > b;
       });
    vector<Person> people {{ "John", 23 }, { "Paul", 25 }, { "Ringo", 22 }, { "George", 21 }};
    return 0;
}


