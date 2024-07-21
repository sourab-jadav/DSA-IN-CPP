#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> calculate()
{
    vector<int> arr{3, 1, 2, 5, 3};
    int sum = 0;
    for (int x : arr)
    {
        sum += x;
    }
    int act_sum = 0;
    for (int i = 1; i <= arr.size(); i++) {
        act_sum += i;
    }
    int low = 0;
    int high = arr.size();
    while (low < high)
    {
        int mid = (low + high) / 2;
        int count = 0;
        for (int x : arr)
        {
            if (x <= mid)
            {
                count++;
            }
        }
        if (count > mid)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    vector<int> result;
    result.push_back(high);
    result.push_back(act_sum - (sum - high));
    return result;
}
int main()
{
    vector<int>result=calculate();
    for (auto x : result) {
        std::cout<<x<<std::endl;
    }
    return 0;
}
