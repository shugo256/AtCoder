#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>

using namespace std;

//200桁整数struct　数値の保持に配列を使ってるけど、vectorにすれば桁数制限なくせそう
struct giant {
    long val[25]; // 8桁ずつ格納
    void print() {
        bool zero = true;
        for (int i=24; i>=0; i--) {
            if (zero) {
                if (val[i] == 0) continue;
                zero = false;
                printf("%ld", val[i]);
            } else {
                long ex = (long)1e7;
                while ((ex/=10) > abs(val[i])) printf("0");
                printf("%ld", abs(val[i]));
            }
        }
        if (zero) printf("0");
        printf("\n");
    }
    int logg() {
        int i=24, j=0;
        long ex = (long) 1e7;
        while (val[i] == 0) i--;
        while ((ex/=10) > abs(val[i])) j++;
        return (i+1)*8 - j;
    }
    giant& operator = (const giant& g) {
        memcpy(val, g.val, sizeof val);
        return *this;
    }
    bool operator < (const giant& g) {
        for (int i=24; i>=0; i--) {
            if (val[i] < g.val[i]) return true;
            else if (val[i] > g.val[i]) return false;
        }
        return false;
    }
    bool operator > (const giant& g) {
        giant a = g;
        return a < *this;
    }
    bool operator == (const giant& g) {
        giant a = g;
        return !(*this < a) && !(*this > a);
    }
    bool operator != (const giant& g) {
        giant a = g;
        return !(*this == a);
    }
    bool operator <= (const giant& g) {
        giant a = g;
        return !(*this > a);
    }
    bool operator >= (const giant& g) {
        giant a = g;
        return !(*this < a);
    }
    giant operator - () {
        giant ans;
        for (int i=0; i<25; i++) ans.val[i] = -val[i];
        return ans;
    }
    giant operator + (const giant& g);
    giant operator += (const giant& g);
    giant operator - (const giant& g);
    giant operator * (const giant &g);
    giant operator *= (const giant& g);
    giant operator / (const giant &g);
    giant operator % (const giant &g);
};

// longをgiantに
giant ltog(long n) {
    giant g;
    for (int i=0; i<25; i++) {
        g.val[i] = n%(long)1e8;
        n /= (long)1e8;
    }
    return g;
}

// 一桁ずつ格納された数列dataをもとにgiantを生成
giant ginit(int data[200], int dig) {
    giant g = ltog(0);
    int itr = dig / 8;
    for (int i=0; i<=25; i++) {
        if (i > itr) continue;
        long ex = 1;
        for (int j=0; j<8 && dig > 0; j++) {
            dig--;
            g.val[i] += ex * data[dig];
            ex *= 10;
        }
    }
    return g;
}

// 入力からgiantを生成
giant getg() {
    int c, i=0, data[200];
    while((c = getchar()) >= '0' && c <= '9' && i < 200) {
        data[i] = c - '0';
        i++;
    }
    return ginit(data, i);
}


giant giant::operator + (const giant& g) {
    giant zero = ltog(0);
    giant a = g;
    if (*this < zero && a < zero) return -((-*this) + (-a));
    else if (*this < zero) return a - (-*this);
    else if (a < zero) return *this - (-a);
    giant ans;
    long next = 0;
    for (int i=0; i<25; i++) {
        long sum = val[i] + g.val[i] + next;
        ans.val[i] = sum % (long)1e8;
        next = sum / (long)1e8;
    }
    return ans;
}
giant giant::operator += (const giant& g) {
    *this = *this + g;
    return *this;
}
giant giant::operator - (const giant& g) {
    giant zero = ltog(0);
    giant a = g;
    if (*this < zero && a < zero) return -((-a) - (-*this));
    else if (*this < zero) return -(a + (-*this));
    else if (a < zero) return *this + (-a);
    else if (*this < a) return -(a - *this);
    giant ans;
    long next = 0;
    for (int i=0; i<25; i++) {
        long dif = val[i] - g.val[i] - next;
        if (dif < 0) {
            ans.val[i] = dif + (long)1e8;
            next = 1;
        } else {
            ans.val[i] = dif;
            next = 0;
        }
    }
    return ans;
}
giant giant::operator * (const giant& g) {
    giant ans = ltog(0), tmp;
    long next = 0;
    for (int i=0; i<25; i++) {
        tmp = ltog(0);
        for (int j=0; j<25-i; j++) {
            long sum = val[i] * g.val[j] + next;
            tmp.val[i+j] = sum % (long)1e8;
            next = sum / (long)1e8;
        }
        ans += tmp;
    }
    return ans;
}
giant giant::operator *= (const giant& g) {
    *this = *this * g;
    return *this;
}
giant giant::operator / (const giant& g) {
    giant a = g, zero = ltog(0);
    if (a < zero && *this < zero) return (-*this) / (-a);
    else if (a < zero) return -(*this / (-a));
    else if (*this < zero) return -((*this) / a);
    else if (*this < a) return zero;
    int i;
    giant ten = ltog(10), dig = ltog(1);
    while (*this >= a*dig*ten) dig *= ten;
    a *= dig;
    for (i=0; a*(ltog(i)) <= *this; i++);
    giant q = ltog(i-1);
    return q * dig + (*this - a * q) / g;
}
giant giant::operator % (const giant& g) {
    return *this - (*this / g) * g;
}

giant gcd(giant m, giant n) {
    giant zero = ltog(0);
    if (m < n) return gcd(n, m);
    else if (n == zero) return m;
    else return gcd(n, m%n);
}

struct giant_pair {
    giant g;
    int i;
};

bool gpcomp(giant_pair& left, giant_pair& right) {
    return left.g < right.g || (left.g == right.g && left.i < right.i);
}

int main() {
    int t;
    scanf("%d\n", &t);
    for (int i=0; i<t; i++) {
        int l;
        getg();
        scanf("%d\n", &l);
        giant code[l];
        giant_pair split[l+1];
        bool splited = false;
        for (int j=0; j<l+1; j++) {
            if (j < l) code[j] = getg();
            if (splited) {
                split[j] = {code[j-1] / split[j-1].g, j};
            } else if (j > 0 && code[j] != code[j-1]){
                split[j] = {gcd(code[j-1], code[j]), j};
                for (int k=j-1; k>=0; k--) {
                    split[k] = {code[k] / split[k+1].g, k};
                }
                splited = true;
            } 
        }
        sort(split, split+l+1, gpcomp);
        int count=0;
        giant prev = split[0].g;
        char ptxt[l+2]; ptxt[l+1] = '\0';
        for (int j=0; j<l+1; j++) {
            if (split[j].g != prev) {
                count++;
                prev = split[j].g;
            }
            ptxt[split[j].i] = (char)('A' + count);
        }
        printf("Case #%d: %s\n", i+1, ptxt);
    }
    return 0;
}