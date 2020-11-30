#include <iostream>

int get_change(int m) {
  int n = 0;
  int sum = 0;
  int input = 0;

  while ( m - 10 >= 0)
  {
    m-=10;
    n++;
  }
  while ( m - 5 >= 0)
  {
    m-=5;
    n++;
  }
  while ( m - 1 >= 0)
  {
    m--;
    n++;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
