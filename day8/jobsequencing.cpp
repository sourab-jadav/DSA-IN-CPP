#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <vector>

// doing job sequencing my way
// we have job's it's id deadline and profile
struct job{
    int id;
    int deadline;
    int profit;
};
bool comparator(struct job j1,struct job j2){
    return j1.profit>=j2.profit;
}
int main() {
    std::cout<<"being as greedy as possible"<<std::endl;
    std::vector<struct job>jobs{
        {1,4,20},{2,1,10},{3,1,40},{4,1,30}
    };
    std::sort(jobs.begin(),jobs.end(),comparator);
    for (auto &x : jobs) {
        std::cout<<x.id<<" "<<x.deadline<<" "<<x.profit<<std::endl;
    }
    int t=1;
    int profit=0;
    for (auto &x : jobs) {
        if (x.deadline>=t) {
           profit+=x.profit; 
           t++;
        }
    }
    std::cout<<"total profit earned is "<<profit<<std::endl;

}


