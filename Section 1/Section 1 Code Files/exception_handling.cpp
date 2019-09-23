#include <iostream>
#include <exception>

class ResourceException : public std::exception {
  public : 
    ResourceException(const std::string& w) : w(w) {}
    const char* what() const noexcept {
      return w.c_str();
    }
  private :
    std::string w;
};

class SomethingImportant {
  public : 
    SomethingImportant() {
      //Open some resource
      //throw ResourceException("Unable to open resource");
      throw 1;
    }
};

int main() {
  try {
    SomethingImportant si;
  } catch(std::exception& except) {
    std::cout << except.what() << std::endl;
    return 1;
  } catch (int val) {
    std::cout << "Caught an int: " << val << std::endl;
    return 2;
  }

  return 0;
}
