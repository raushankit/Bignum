#include "bignum.h"

bignum::bignum()
{
    sign = true;
    v.clear();
}

bignum::bignum(const long long int n)
{
    sign = n >= 0;
    long long int m = sign ? n : -n;
    while (m)
    {
        v.push_back(m % MOD);
        m /= MOD;
    }
}

bignum::bignum(const std::string s)
{
    sign = !(s[0] == '-');
    int m = (s.length() - !sign) / 9;
    for (int i = s.length() - 1; m > 0; i -= 9)
    {
        m--;
        int temp = 0;
        for (int j = i - 8; j <= i; j++)
            temp = temp * 10 + (s[j] - '0');
        v.push_back(temp);
    }
    m = 0;
    for (unsigned int i = !sign; i < s.length() % 9; i++)
        m = m * 10 + (s[i] - '0');
    if (m > 0)
        v.push_back(m);
    if (v.size() == 1 && v[0] == 0)
        sign = true;
}

std::ostream &operator<<(std::ostream &out, const bignum &n)
{
    if (!n.sign)
        out << '-';
    for (int i = (int)n.v.size() - 1; i >= 0; i--)
        out << n.v[i];
    return out;
}