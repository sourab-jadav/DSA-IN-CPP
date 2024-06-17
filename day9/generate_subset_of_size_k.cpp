#include <iostream>
#include <vector>

using namespace std;

// Function to generate all subsets of size m
void generateSubsetsOfSizeM(const vector<int>& inputSet, int m, int start, vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
    if (currentSubset.size() == m) {
        allSubsets.push_back(currentSubset);
        return;
    }

    for (int i = start; i < inputSet.size(); ++i) {
        currentSubset.push_back(inputSet[i]);
        generateSubsetsOfSizeM(inputSet, m, i + 1, currentSubset, allSubsets);
        currentSubset.pop_back();
    }
}

// Helper function to start the generation process
vector<vector<int>> generateSubsetsOfSizeM(const vector<int>& inputSet, int m) {
    vector<vector<int>> allSubsets;
    vector<int> currentSubset;
    generateSubsetsOfSizeM(inputSet, m, 0, currentSubset, allSubsets);
    return allSubsets;
}

int main() {
    vector<int> inputSet = {1, 2, 3, 4};
    int m = 2;

    vector<vector<int>> subsets = generateSubsetsOfSizeM(inputSet, m);

    cout << "Subsets of size " << m << ":\n";
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}
