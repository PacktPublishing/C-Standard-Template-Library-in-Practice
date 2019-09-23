#include <set>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream in("illiad.txt");
  set<string> words;
  string word = ""; 
  unsigned long long totalCount = 0;

  while(!in.eof()) {
    in >> word; 
    totalCount++;
    words.insert(word);
  }

  cout << "Text contains " << words.size() << " unqiue words out of "
    << totalCount << endl;
  in.close();
  return 0;
}
