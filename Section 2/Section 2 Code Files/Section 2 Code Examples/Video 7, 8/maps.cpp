#include <iostream>
#include <map>
#include <unordered_map>
#include <iterator>
#include <utility>

/**
int main(int argc, char* argv[]) {
  //Create a map
  std::map<std::string, std::string> stringMap;

  stringMap.insert({"Hello", "World"});

  std::cout << stringMap["Hello"] << std::endl;
}
*/

struct SimpleObject {
  int x;
  int y; 
  std::string z;

  SimpleObject() : x(1), y(2), z("stuff") {
    
  }

  SimpleObject(int x, int y, const std::string& z) : 
    x(x), y(y), z(z) {

  }

};

using namespace std;

int main() {
  map <string, SimpleObject> objectMap;

  //Insert some elements
  objectMap.insert(pair<string, SimpleObject>("first", SimpleObject(4, 8, "Hello")));
  objectMap["second"] = SimpleObject();
  objectMap["second"] = SimpleObject(0, 0, "Overwritten");
  objectMap["third"] = SimpleObject(1, 6, "World");
  objectMap.insert({"fourth", SimpleObject(1, 1, "number 4")});

  //Insert will not allow insertions if the key already exists
  //Use structured bindings instead of std::pair object
  
  const auto [iterator, inserted] = objectMap.insert({"third", SimpleObject()});

  if (inserted) {
    cout << "Item inserted" << endl;
  }
  else {
    cout << "key \"third\" already exists, not inserted." << endl;
  }
    
  //Go through each element in the map
  for (auto& x : objectMap) {
    cout << x.first << " -> " << x.second.z << endl;
  }

  //Another way to go through each element in the map
  for (map<string, SimpleObject>::iterator it = objectMap.begin(); it != objectMap.end(); ++it){
    cout << it->first << " => " << it->second.z << endl;
  }

  //Erase some elements
  objectMap.erase("second");
  cout << "Erased second" << endl;
  auto ptr = objectMap.find("third");

  if (ptr == objectMap.end()) {
    cout << "Unable to find third" << endl;
  }
  else {
    objectMap.erase(ptr, objectMap.end());
    cout << "Erased from third to the end" << endl;
  }

  for (auto& x : objectMap) {
    cout << x.first << " -> " << x.second.z << endl;
  }

  objectMap.clear();
  cout << "objectMap length now: " << objectMap.size() << endl;

  return 0;
}
