#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

int main() {
  istream_iterator<double> end;
  istream_iterator<double> din(cin);

  vector<double> doubles;
  back_insert_iterator<vector<double>> bins(doubles);

  while(din != end) {
    *bins++ = *din++;
  }
  
  partial_sum(doubles.begin(), doubles.end(), ostream_iterator<double>(cout, " "));

  cout << endl;
  return 0;
}
