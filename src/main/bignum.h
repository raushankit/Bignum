#ifndef _BIGNUM_
#define _BIGNUM_

#include <iostream>
#include <vector>
#define MOD 1000000000

class bignum
{
public:
    bignum();
    bignum(const long long int);
    bignum(const std::string);

    friend std::ostream &operator<<(std::ostream &, const bignum &);

private:
    bool sign; // true for positive
    std::vector<int> v;
};

#endif