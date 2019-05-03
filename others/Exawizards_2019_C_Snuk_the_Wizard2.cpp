#include <iostream>
#include <string>
#include <algorithm>

#define MAX (int)2e5
	
//にぶたんver  未完成

using namespace std;
typedef pair<char,int> P;

int n, q;
string s;
P spels[MAX+1];

int journey(int k) {
	for (int i=0; i<q; i++) {
		if (s[(size_t)k] != spels[i].first) continue;
		k += spels[i].second;
		if (k == n) return 1;
		else if (k == -1) return -1;
	}
	return 0;
}

int main() {
	cin >> n >> q >> s;
	for (int i=0; i<q; i++) {
		char t, d;
		cin >> t >> d;
		spels[i] = P(t, d == 'R' ? 1 : -1);
	}

	int a1 = 0, a2 = 0, b1 = n-1, b2 = n-1, j1, j2;
	while (true) {
		j1 = journey((a1 + b1)/2);
		j2 = journey((a2 + b2 + 1)/2);
		if (b1 - a1 <= 1 && b2 - a2 <= 1) break;
		if (j1 == -1) a1 = (a1 + b1)/2;
		else b1 = (a1 + b1)/2;
		if (j2 == 1) b2 = (a2 + b2 + 1)/2;
		else a2 = (a2 + b2 + 1)/2;
	}
	cout << b2 - a1 + (int)(j1==0) + (int)(j2==0) - 1 << '\n';
	return 0;
}//わーい