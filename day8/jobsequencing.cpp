#include <algorithm>
#include <iostream>
#include <vector>

// being as greedy as possible
// given id ,deadline until which job can be performed,and profit you get when
// you perform that job the question is which jobs to select so that maximum
// profit can be achieved we start the timer from t=1 sec and start adding the
// maximum profit possible if the job is feasable at that time

struct job {
    int id;
    int deadline;
    int profit;
};
// there is another type called job scheduling
bool comparator(struct job j1, struct job j2) { return j1.profit >= j2.profit; }

int main() {
    std::cout << "being as greedy as possible" << std::endl;
    std::vector<struct job> jobs{{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    std::sort(jobs.begin(), jobs.end(), comparator);
    for (auto &x : jobs) {
        std::cout << x.id << " " << x.deadline << " " << x.profit << std::endl;
    }
    int t = 1;
    int profit = 0;
    for (auto &x : jobs) {
        if (x.deadline >= t) {
            profit += x.profit;
            t++;
        }
    }
    std::cout << "total profit earned is " << profit << std::endl;
}
