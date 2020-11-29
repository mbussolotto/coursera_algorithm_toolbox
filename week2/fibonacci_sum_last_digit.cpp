#include <iostream>

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

unsigned long long pisano_period(unsigned long long m)
{
  unsigned long long prev = -1;
  unsigned long long curr = -1;
  if ( m == 2)
    return 3;
  for(unsigned long long  i = 2; i <= m*m; i++)
  {
    prev = curr;
    curr = fibonacci_fast_rest(i, m);

    if (prev == 0 && curr == 1)
    {
      return i - 1;
    }
  }
  return 0;
}

unsigned long long get_fibonacci_huge(unsigned long long n, unsigned long long m)
{
  unsigned long long period = pisano_period(m);
  return fibonacci_fast_rest(n % period , m);
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

unsigned long long fibonacci_sum(unsigned long long n) {
  unsigned long long period = pisano_period(10);
  if (n < period)
    return fibonacci_sum_naive(n);
  unsigned long long remainder = n % period;
  return fibonacci_sum_naive(remainder);
}

int main() {
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
