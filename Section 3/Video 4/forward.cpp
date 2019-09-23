#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<int> backInsertionVector = {1, 2, 3};
  vector<int> forwardVector = {1, 2, 3};

  back_insert_iterator<vector<int>> bins(backInsertionVector);
  vector<int>::iterator fit = forwardVector.begin();

  *fit = 20;
  *fit = 30;
  fit++;

  *bins = 20;
  *bins = 30;
  bins++;

  for (int i : backInsertionVector) {
    cout << i << " ";
  }

  cout << "\n";

  for (int i : forwardVector) {
    cout << i << " ";
  }

  cout << "\n";

  return 0;
}
