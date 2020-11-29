#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

unsigned long long fibonacci_fast_rest(unsigned long n, unsigned long long m) {

    if (n <= 1)
      return n;

    unsigned long long previous = 0;
    unsigned long long current = 1;
    for(unsigned long long i = 2; i <=n; i++)
    {
      int tmp_previous = previous;
      previous = current;
      current = tmp_previous + current;
      current %=m;
    }
    return current ;
}

unsigned int fibonacci_sum_squares(long long n) {
  if( n == 0 )
  {
    return 0;
  }
  unsigned int w = fibonacci_fast_rest(n % 60 , 10);
  unsigned int h = fibonacci_fast_rest( (n-1) % 60 , 10);
  return ((w + h) * w ) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
