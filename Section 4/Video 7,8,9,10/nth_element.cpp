#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
  vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};

  nth_element(v.begin(), v.begin() + v.size()/2, v.end());
  cout << "The median is " << v[v.size()/2] << '\n';

  for_each(begin(v), end(v), [](auto& i){cout << i << " ";});
  cout << endl;

  nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());
  cout << "The second largest element is " << v[1] << '\n';

  for_each(begin(v), end(v), [](auto& i){cout << i << " ";});
  cout << endl;

  partial_sort(begin(v), begin(v) + 4, end(v));

  for_each(begin(v), end(v), [](auto& i){cout << i << " ";});
  cout << endl;

  return 0;
}
