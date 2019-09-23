#include <iostream>
#include <fstream>

/*
 * echo "This is some text" > input.txt
 */

using namespace std;

int main() {

  ifstream fs("input.txt");

  if (fs) {
    cout << "ifstream is in a good state\n";
    //keep reading while state is good
    int count = 0;
    while(fs.good()) {
      string line;
      fs >> line;
      if (line.size() > 0) {
        ++count;
      }
    }
    cout << "Read " << count << " words\n";
  }

  if (fs.bad()) {
    cout << "ifstream is in a bad state\n";
  }

  if (fs.fail()) {
    cout << "ifstream is in a fail state\n";
  }

  if (fs.eof()) {
    cout << "ifstream is in an EOF state\n";
  }

  cout << std::showbase << std::hex << (int)fs.rdstate() << "\n";

  fs.setstate(ios::eofbit);

  cout << std::showbase << std::hex << (int)fs.rdstate() << "\n";
  return 0;
}
