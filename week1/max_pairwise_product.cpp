#include <iostream>
#include <vector>

using namespace std;

unsigned long max_pair_prod(vector<unsigned int> in)
{
  int max_idx = 0;
  for(int i = 0; i < in.size(); i++ )
  {
    if (in[i] > in[max_idx])
      max_idx = i;
  }

  int sec_max_idx = 0;

  for(int i = 0; i < in.size() ; i++ )
  {
    if (i == max_idx)
    {
      continue;
    }
    if (in[i] > in[sec_max_idx] )
      sec_max_idx = i;
  }
  return ((unsigned long) in[max_idx] )* in[sec_max_idx];
}


int main()
{
  long unsigned int n = 1;
  cin >> n;
  vector<unsigned int> values;
  for(unsigned int i = 0; i < n; i++)
  {
    unsigned int value = 0;
    cin >> value;
    values.push_back(value);
  }

  cout << max_pair_prod(values) << endl;
}
