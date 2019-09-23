#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

int main() {
  vector<int> vecNum = {1, 2, 3, 4, 5};
  list<int> listNum = {10, 20, 30, 40, 50};

  vector<int>::iterator vit = vecNum.begin();
  list<int>::iterator lit = listNum.begin();

  cout << vit[3] << "\n";
  cout << *(vit + 1) << "\n";

  //Wont work
  //cout << lit[3] << "\n";
  //cout << *(lit + 1) << "\n";
  
  //Need to do this instead
  std::advance(lit, 3);
  cout << *lit << "\n";

  return 0;
}
