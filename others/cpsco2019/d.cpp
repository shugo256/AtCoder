include <iostream>
include <algorithm>
include <queue>

int main() {
	int n, k, a, prev=0, count=1;
	cin << n << k;
	priority_queue pq;
	for (int i=0; i<n; i++) {
		cin << a;
		if (a == prev) count++;
		else `{
			pq.push(count);
		}
		prev = a;
	}
}