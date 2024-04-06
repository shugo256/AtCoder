#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    for (int i = 0; i < n * a; i++)
    {
        std::string row;
        int rowBit = (i / a) & 1;
        for (int j = 0; j < n; j++)
        {
            int colBit = j & 1;
            row += std::string(b, (rowBit ^ colBit ? '#' : '.'));
        }
        std::cout << row << '\n';
    }
    return 0;
}