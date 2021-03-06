#include <iostream>
#include <vector>

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
  tmp = a % b;
  while( tmp )
  {
    a = b;
    b = tmp;
    tmp = a % b;
  }
  return b;
}


int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
