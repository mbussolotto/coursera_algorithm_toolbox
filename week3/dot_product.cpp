#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using std::vector;
using std::cout;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result =0;
  sort(a.begin(), a.end(), [](const int lhs, int rhs) {
    return lhs > rhs;
  });
  //for(auto i : a)
  //{
  //  cout << i << " ";
  //}
  sort(b.begin(), b.end(), [](const int lhs, const int rhs) {
    return lhs > rhs;
  });

  //for(auto i : b)
  //{
  //  cout << i << " ";
  //}
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
