#include <iostream>
#include <vector>

unsigned long fibonacci_fast(int n) {
    if (n <= 1)
      return n;
    std::vector<unsigned long> fib;
    fib.push_back(0l);
    fib.push_back(1l);
    for(int i = 2; i <=n; i++)
      fib.push_back(fib[i-1] + fib[i-2]);
    return fib[n];
}

unsigned long gcd_naive(unsigned long a, unsigned long b) {
  unsigned long current_gcd = 1;
  for (unsigned long d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

unsigned long gcd(unsigned long a, unsigned long b) {
  int current_gcd = 1;
  unsigned long tmp = 0;
  int res = 1;
  if ( a < b)
  {
    tmp = a;
    a = b;
    b = tmp;
  }
  unsigned long fib = fibonacci_fast(2);
  for(int i = 2; fib < b ;i++)
  {
    fib = fibonacci_fast(i);
    if ( (a % fib == 0) && (b % fib == 0) )
    {
      a/= fib;
      b/= fib;
      res *= fib;
    }
  }
  tmp = a % b;
  while( tmp )
  {
    a = b;
    b = tmp;
    tmp = a % b;
  }
  return res*b;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
