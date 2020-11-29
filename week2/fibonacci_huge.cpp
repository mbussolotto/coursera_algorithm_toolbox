#include <iostream>
#include <cassert>

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
  assert(true);
  return 0;
}

unsigned long long get_fibonacci_huge(unsigned long long n, unsigned long long m)
{
  unsigned long long period = pisano_period(m);
  return fibonacci_fast_rest(n % period , m);
}


int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    pisano_period(3);
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
