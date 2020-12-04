#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::max;
using std::min;


int compute_min_refills(int dist, int tank, std::deque<int> & stops) {
  int numRefills = 0;
  int currentRefill = 0;
  stops.push_front(0);
  stops.push_back(dist);
  while(currentRefill < stops.size())
  {
    //cout << "currentRefill " << currentRefill << endl;
    int lastRefill = currentRefill;
    //cout << "lastRefill " << currentRefill << endl;
    //cout << "stops[currentRefill+1] " << stops[currentRefill+1] << endl;
    //cout << "stops[currentRefill] " << stops[currentRefill] << endl;
    //cout << "stops[lastRefill] " << stops[lastRefill] << endl;

    while (currentRefill < stops.size() && stops[currentRefill+1] - stops[lastRefill] <= tank)
    {
      currentRefill++;
      //cout << "new currentRefill " << currentRefill << endl;
      //cout << "stops[currentRefill+1] " << stops[currentRefill+1] << endl;
      //cout << "stops[currentRefill] " << stops[currentRefill] << endl;
    }
    //cout << "GAS at " << currentRefill << endl;

    if(currentRefill == lastRefill)
      return -1;
    if(currentRefill < stops.size())
    {
      numRefills++;
      //cout << "new numRefills " << numRefills << endl;
    }
  }
  //cout << "numRefills " << numRefills << endl;

  return numRefills;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    std::deque<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
