#include <iostream>
#include <vector>
#include<algorithm>
#include <iomanip>

using std::vector;

class Storage {
  public:
    int values;
    int weights;
    double v_per_unit;
  Storage(int values, int weights, double v_per_unit)
  {
    this->values = values;
    this->weights = weights;
    this->v_per_unit = v_per_unit;

  }
};

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  vector<Storage> col;
  for (int i = 0; i < weights.size(); i++)
  {
    col.push_back(Storage(values[i],weights[i],values[i]/weights[i]));
  }
  sort(col.begin(), col.end(), [](const Storage& lhs, const Storage& rhs) {
     return lhs.v_per_unit > rhs.v_per_unit;
  });

  for(Storage i : col)
  {
    double rem = 1.0;
    if( capacity < i.weights)
    {
      rem = capacity / i.weights;
    }
    if ( capacity - rem*i.weights >= 0)
    {
      value+= rem*i.values;
      capacity -= rem*i.weights;
    }
    if (capacity == 0)
      return value;
  }


  return value;
}

int main() {
  double n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed;
  std::cout << std::setprecision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
