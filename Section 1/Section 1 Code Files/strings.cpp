#include <iostream>
#include <string>

using namespace std;

int main() {
 
  //Declaring strings
  string name = "James Slocum";
  string n2("James Slocum");
  string n3(name);
 
  string n4 {'J', 'a', 'm', 'e', 's'};
  string last(name, 6, 6);
  string line(20, '-');
  string reverse(name.rbegin(), name.rend());

  cout << name << '\n';
  cout << n2 << '\n';
  cout << n3 << '\n';
  cout << n4 << '\n';
  cout << last << '\n';
  cout << reverse << '\n';
  cout << line << '\n';


  //Finding strings
  std::size_t pos = name.find(n4);
  if (pos != std::string::npos) {
    cout << "Found first name at: " << pos << '\n';
  }

  cout << "Comma at: " << ("Hello, How are you?"s).find(",") << '\n';


  cout << line << '\n';

  //Append to string
  string about = "is a programmer";
  name.push_back(' ');
  for (char c : about) {
    name.push_back(c);
  }

  cout << name << '\n';

  //Insert into strings
  name.insert(0, "I have heard that ");
  cout << name << '\n';

  //Replace some string
  pos = name.find("programmer");
  name.replace(pos, ("programmer"s).length(), "snowboarder");

  pos = name.find("heard");
  name.erase(pos, ("heard"s).length());
  name.insert(pos, "read somewhere");
  cout << name << '\n';

  return 0;
}
