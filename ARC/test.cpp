#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int a[] = {1,9,9,8,1,0,2,6};
    deque<int> deq(a,a+8);
    printf("%ld\n",find(deq.begin(),deq.end(),6)-deq.begin());
}