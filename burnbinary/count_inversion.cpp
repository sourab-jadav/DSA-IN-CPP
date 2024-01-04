#include <algorithm>
#include <iostream>
#include <vector>

// using namespace std;
// we are using 

int getNumOfInversions(std::vector<int> A)
{
    int N = A.size();
    if (N <= 1)
    {
        return 0;
    }
    std::vector<std::pair<int, int>> sortList;
    int result = 0;
    // Heapsort, O(N*log(N))
    for (int i = 0; i < N; i++)
    {
        sortList.emplace_back(A[i], i);
        push_heap(sortList.begin(), sortList.end());
    }
    // Create a sorted list of indexes
    std::vector<int> x;
    while (!sortList.empty())
    {
        // O(log(N))
        std::pair<int, int> v = sortList.front();
        std::cout<<v.first<<" "<<v.second<<std::endl;
        pop_heap(sortList.begin(), sortList.end());
        sortList.pop_back();
        // Find the current minimum's index
        // the index y can represent how many minimums on the left
        int y = lower_bound(x.begin(), x.end(), v.second) - x.begin();
        // i can represent how many elements on the left
        // i - y can find how many bigger nums on the left
        result += v.second - y;
        x.insert(lower_bound(x.begin(), x.end(), v.second), v.second);
    }
    return result;
}

int main()
{
    std::vector<int> A = {1, 20, 6, 4, 5};
    int result = getNumOfInversions(A);
    std::cout << "Number of inversions are " << result << std::endl;
    return 0;
}
