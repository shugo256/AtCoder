#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

#define amax(a, b) a = std::max(a, b)
#define amin(a, b) a = std::min(a, b)

using ll = long long;

const std::string ABCAB("ABCAB");

bool isShiftedAbc(std::string &s) {
    return s.size() == 3 && ABCAB.find(s) != std::string::npos;
}

std::string getShiftedAbc(char start) {
    return ABCAB.substr(start - 'A', 3);
}

class StringDeque {
    std::deque<char> dq;

    std::string rangeToString(std::deque<char>::iterator from, std::deque<char>::iterator to) {
        std::string ans(from, to);
        dq.erase(from, to);
        return ans;
    }

public:
    StringDeque() : dq() {}

    void push_back(char c) {
        dq.push_back(c);
    }

    void push_back(std::string str) {
        for (auto &c : str) {
            this->push_back(c);
        }
    }

    void push_front(char c) {
        dq.push_front(c);
    }

    void push_front(std::string str) {
        for (auto itr = str.rbegin(); itr != str.rend(); itr++) {
            this->push_front(*itr);
        }
    }

    std::string pop_back(int len = 1) {
        return rangeToString(dq.end() - len, dq.end());
    }

    std::string pop_front(int len = 1) {
        return rangeToString(dq.begin(), dq.begin() + len);
    }

    std::string toString() {
        return std::string(dq.begin(), dq.end());
    }

    size_t size() {
        return dq.size();
    }
};

int main() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;
    
    int curIdx = 0;
    StringDeque dq;

    for (int i = 0; i < n; i++) {
        dq.push_back(s[i]);

        if (dq.size() >= 3) {
            auto back = dq.pop_back(3);

            if (isShiftedAbc(back)) {
                dq.push_front(back);
            } else {
                dq.push_back(back);
            }
        }
        // std::cerr << dq.toString() << std::endl;

        while (dq.size() >= 3) {
            auto front = dq.pop_front(3);
            if (isShiftedAbc(front)) {
                front = getShiftedAbc(t[curIdx]);
            }

            if (front[0] != t[curIdx]) {
                dq.push_front(front);
                break;
            }

            for (int offset = 0; offset < 3; offset++, curIdx++) {
                if (front[offset] != t[curIdx]) {
                    dq.push_front(front.substr(offset));
                    break;
                }
            }
        }
        // std::cerr << curIdx << ' ' << dq.toString() << std::endl;
    }
    std::cout << (t.substr(curIdx) == dq.toString() ? "YES" : "NO") << '\n';
    return 0;
}