#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

class Factorial
{
public:
    Factorial() : factorial_() {}

    int operator [] (int n) const
    {
        if(factorial_.size() <= n)
        {
            factorial_.push_back((n > 0) ? (n * (*this)[n - 1]) : 1);
        }
        return factorial_[n];
    }

    int getMaxLessOrEqual(int a) const
    {
        int result = 0;
        while((*this)[result] < a)
        {
            ++result;
        }
        return --result;
    }

private:
    mutable std::vector<int> factorial_;
};

bool isDivisible (int dividend, int divisor)
{
    return (dividend % divisor) == 0;
}

void print(int a, int b, int c)
{
    const int m = (a - b) / c;
    const int n = a - b / c;
    std::cout << (boost::format("(%1% - %2%) / %3% = %4%") % a % b % c % m) << std::endl;
    std::cout << (boost::format(" %1% - %2%  / %3% = %4%! = %5%") % a % b % c % m % n) << std::endl;
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <count>\n";
        return 0;
    }

    const int max = boost::lexical_cast<int>(argv[1]);

    Factorial factorial;

    for(int a = 20; a < max; ++a)
    {
        int n_max = factorial.getMaxLessOrEqual(a);

        for(int n = 1; n <= n_max; ++n)
        {
            int b1 = a - factorial[n];
            for(int c = 2; (b1 * c) < a; ++c)
            {
                const int b = b1 * c;
                if(isDivisible(a - b, c) && (((a - b) / c) == n))
                {
                    print(a, b, c);
                }
            }
        }
    }

    return 0;
}
