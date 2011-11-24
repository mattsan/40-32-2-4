#include <iostream>
#include <string>
#include <vector>
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

    for(int a = 1; a < max; ++a)
    {
        for(int b = 1; b < a; ++b)
        {
            const int c_max = a - b;
            for(int c = 2; c < c_max; ++c)
            {
                if(isDivisible (b, c) && isDivisible (a - b, c) && ((a - b / c) == factorial[(a - b) / c]))
                {
                    print(a, b, c);
                }
            }
        }
    }

    return 0;
}
