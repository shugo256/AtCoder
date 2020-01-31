#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef struct divide_boredom {
	int c, d;
} db;

bool operator< (const db& left, const db& right) {
    return left.c / left.d < right.c / right.d;
}

typedef pair<int, int> P;

int main() {
	int n, k, a, prev=0, count=1;
	cin >> n >> k;
	priority_queue<db> pq;
	for (int i=0; i<n; i++) {
		cin >> a;
		if (a == prev) count++;
		else {
			pq.push(db({count,1}));
			count = 1;
		}
		prev = a;
	}
	pq.push(db({count,1}));
	db max;
	for (int i=0; i<k; i++) {
		max = pq.top();
		if (max.c == max.d) break;
		pq.pop();
		pq.push({max.c, max.d+1});
	}
	printf("%d\n", pq.top().c/pq.top().d);
	return 0;
}