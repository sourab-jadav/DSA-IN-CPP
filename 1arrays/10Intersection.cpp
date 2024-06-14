#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 5, 10, 20, 40, 80};
    int b[] = {6, 7, 20, 80, 100};
    int c[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int n3 = sizeof(c) / sizeof(c[0]);
    while (i<n1 && j<n2 && k<n3) {
        if (a[i]<b[j]) {
            i++;
        }else if (b[j]<a[i]) {
            j++;
        }else if(b[j]<c[k]){
            j++;
        }else if (c[k]<b[j]) {
            k++;
        }else if (a[i]<c[k]) {
            i++;
        }else if (c[k]<a[i]) {
            k++;
        }else if (a[i]==b[j]&& a[i]==c[k]) {
            std::cout<<a[i]<<std::endl;
            i++;
            j++;
            k++;
        }
    }
    return 0;
}
