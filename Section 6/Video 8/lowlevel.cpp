#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

/*
 * echo "This is some text" > input.txt
 */
int main() {

  ifstream fs("input.txt");
  string text;

  if (fs) {
    char c = fs.peek();
    cout << "Peeked and saw a " << c << " as the first character\n";

    fs.seekg(0, ios_base::end);

    int size = fs.tellg();
    cout << size << " characters in stream\n";

    text.resize(size);

    fs.seekg(0, ios_base::beg);

    fs.read(text.data(), size);

    cout << "Read in: " << text;

    fs.close();
  }
  else {
    cerr << "Unable to open file for reading, exiting...\n";
    return 1;
  }

  ofstream out("output.txt");

  if (out) {
    for_each(begin(text), end(text), [&out](char c) {
          out.put(c);
        });

  }
  else {
    cerr << "Unable to open file for writting, exiting...\n";
    return 2;
  }

  out.close(); //important, as this will flush the buffers out
  return 0;
}
