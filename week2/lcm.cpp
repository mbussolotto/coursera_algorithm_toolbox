#include <iostream>
#include <vector>

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


long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

unsigned long lcm(unsigned long a, unsigned long b) {
  return a*b/gcd(a,b);

}

int main() {
  unsigned long a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
