#include <iostream>
#include <memory>

class Widget {
  public :
    Widget(int num) : num(num) { 
      std::cout << "Constructing Widget " << num << "\n"; 
    }

    ~Widget() { 
      std::cout << "Destroying Widget " << num << "\n"; 
    }
  
  private :
    int num;
};

int main() {
  Widget* w = new Widget(1);
  std::unique_ptr<Widget> uw = std::make_unique<Widget>(2);
}
