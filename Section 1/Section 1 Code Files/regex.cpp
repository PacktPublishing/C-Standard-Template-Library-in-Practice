#include <string>
#include <iostream>
#include <regex>

using namespace std;

int main() {

  string s("This is a large string containing some numbers like 408 and (382), it also contains some phone numbers like (921) 523-1101, 117-332-1019, and +13314560987. These should all match, but ignore our lone numbers like 433-0988 and (281)2121 since those are not phone numbers.");

  //define our matching object
  cmatch matcher;

  regex allPhoneNumbers(R"delim((\+\d{1,3})?[\.\-\)\(]*([0-9]{3})[\.\-\)\(\ ]*([0-9]{3})[\.\-\)\(\ ]*([0-9]{4}))delim");

  
  while(regex_search(s.c_str(), matcher, allPhoneNumbers, 
        regex_constants::match_default)){

    cout << "Matches: " << "\n";
    cout << "[" << matcher[0] << "]\n";

    s = matcher.suffix().str();
    
  }

  return 0;
}
