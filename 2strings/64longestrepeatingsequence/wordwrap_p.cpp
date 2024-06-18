
#include <iostream>
#include <vector>
#include <climits>
// we have dp vector breaks vector
// k value 
// current currentIndex
// words vector
int solve(const std::vector<int>& words, int n, int maxWidth, int currentIndex, std::vector<int>& dp, std::vector<int>& breaks) {
    if (currentIndex == n) return 0;  // if we reach beyond n-1 then return 0;
    if (dp[currentIndex] != -1) return dp[currentIndex]; // if the value is present for the currentIndex then return value

    int currentLength = 0;
    int minCost = INT_MAX;

    for (int i = currentIndex; i < n; ++i) { // looping through all the elements from the current index
        currentLength += words[i]; // add the word to the current line
        if (i > currentIndex) currentLength += 1; // Add space between words
                                                  //
        if (currentLength > maxWidth) break; // if this occurs we cannot add this word so we break out

        int extraSpaces = maxWidth - currentLength; // we come here when there is extra space
        int cost = (i == n - 1) ? 0 : extraSpaces * extraSpaces; //  if it is last word then the cost is zero
                                                                 //  now that we know the cost for the current line
                                                                 //  we recursively calculate cost for the next line
        int totalCost = cost + solve(words, n, maxWidth, i + 1, dp, breaks); // from the recursive call we get the minimum cost
                                                                             // that can obtain from i+1

        if (totalCost < minCost) {
            minCost = totalCost;
            breaks[currentIndex] = i + 1;
        }
    }

    dp[currentIndex] = minCost;
    return dp[currentIndex];
}

void printSolution(const std::vector<int>& breaks, int n) {
    int current = 0; // in the breaks vector break value is defined for each line
    int line = 1;
    while (current < n) {
        std::cout << "Line number " << line << ": From word no. " << current + 1 << " to " << breaks[current] << std::endl;
        current = breaks[current];
        line++;
    }
}

void wordWrap(const std::vector<int>& words, int maxWidth) {
    int n = words.size();
    std::vector<int> dp(n, -1); // stores result until length i 
    std::vector<int> breaks(n, 0); // keeps a breaks vector

    solve(words, n, maxWidth, 0, dp, breaks); // solve give dp words,k value breaks vector to store the array
    printSolution(breaks, n); // we take the breaks and print the desired solution 
    int result=0;
}

int main() {
    std::vector<int> words = {3, 2, 2, 5}; // we have the word's and their length defined
    int maxWidth = 6; // max width of the line is defined
    wordWrap(words, maxWidth);
    return 0;
}
