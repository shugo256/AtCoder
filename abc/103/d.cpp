#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

//解説一瞬読んでやったものの591ms...

struct war
{
    int a;
    int b;
};

bool cmp(const war& left, const war& right) {
    return left.b < right.b;
}

int main () {
    int N,M,a,b,sum=0;
    scanf("%d %d",&N,&M);
    war w;
    deque<war> wars;
    for (int i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        wars.push_back(war{a,b});
    }
    sort(wars.begin(),wars.begin()+M,cmp);
    while (wars.size() != 0) {
        w = wars.front(); wars.pop_front();
        for (size_t i=0; i<wars.size(); i++) {
            if(wars[i].a <= w.b-1) {
                wars.erase(wars.begin()+(int)i);
                i--;
            }
        }
        sum++;
    }
    printf("%d\n",sum);
    return 0;
}