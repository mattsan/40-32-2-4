#include <iostream>
#include <string>
#include <boost/format.hpp>

void print(double a, double b, double c)
{
    const double m = (a - b) / c;
    const double n = a - b / c;
    std::cout << (boost::format("(%1% - %2%) / %3% = %4%") % a % b % c % m) << std::endl;
    std::cout << (boost::format(" %1% - %2%  / %3% = %4%! = %5%") % a % b % c % m % n) << std::endl;
    std::cout << std::endl;
}

double factorial(double n)
{
    return (n > 0) ? (n * factorial(n - 1)) : 1;
}

int main(int, char* [])
{
    for(double a = 1; a < 1000; ++a)
    {
        for(double b = 1; b < 1000; ++b)
        {
            for(double c = 2; c < 100; ++c)
            {
                if((a > b) && ((a - (b / c)) == factorial((a - b) / c)))
                {
                    print(a, b, c);
                }
            }
        }
    }

    return 0;
}
