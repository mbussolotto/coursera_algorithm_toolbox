#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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
  unsigned long long period = 60;
  if (n < period)
    return fibonacci_sum_naive(n);
  unsigned long long remainder = n % period;
  return fibonacci_sum_naive(remainder);
}

int main() {
    unsigned long long period = 60;
    long long from, to;
    std::cin >> from >> to;
    if (from == 0)
    {
      from = 1;
    }
    unsigned long long last = fibonacci_sum(to);
    unsigned long long first = fibonacci_sum(from - 1);
    if (last < first)
      last +=10;
    std::cout << last - first << '\n';
}
