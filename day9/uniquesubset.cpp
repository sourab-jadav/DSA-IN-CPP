#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// now the other challenge is to consider only unique combinations
// one approach can be to use set data structure to store the elements
//
// set takes klogn time to store elements .
// need for optimization here!!!!!
//
// Lets  understand  with an example where arr = [1,2,2 ].
//
// Initially start with an empty data structure. In the first recursion, ca
// ll make a subset of size one, in the next recursion call a subset of siz
// e 2, and so on. But first, in order to make a subset of size one what op
// tions do we have?
//
// We can pick up elements from either the first index or the second index
// or the third index. However, if we have already picked up two from th
// e second index, picking up two from the third index will make another
// duplicate subset of size one. Since we are trying to avoid duplicate sub
// sets we can avoid picking up from the third index. This should give us a
// n intuition that whenever there are duplicate elements in the array we p
// ick up only the first occurrence.

std::vector<std::vector<int>>result;
void printunique(std::vector<int> &init, std::vector<int> &temp, int i) {
    result.push_back(temp);
    for(int j=i;j<init.size();j++){
        if (j!=i && init[j]==init[j-1]) {
            continue;
        }
        temp.push_back(init.at(j));
        printunique(init, temp, j+1);
        temp.pop_back();
    }
}

int main() {
  std::vector<int> vec{1, 2, 2};
  std::sort(vec.begin(), vec.end());
  std::vector<int> temp;
  printunique(vec, temp, 0);

  // printing the unique subsets
  //
  return 0;
}
