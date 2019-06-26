#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    b--;
    char grid[80][50] = {{0}};
    for (int i=0; i<80; i++) {
        for (int j=0; j<49; j++) {
            if (i < 40) {
                if(i%2 || j%2 || b == 0)
                    grid[i][j] = '.';
                else {
                    grid[i][j] = '#';
                    b--;
                }
            } else {
                if(!(i%2) || j%2 || a == 0)
                    grid[i][j] = '#';
                else {
                    grid[i][j] = '.';
                    a--;
                }
            }
        }
    }
    grid[38][48] = grid[39][48] = '#';
    grid[40][0] = '.';
    cout << "80 49" << '\n';
    for (auto g:grid)
        cout << g << '\n';
    return 0;
}