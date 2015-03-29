#include "proxy_ptr.hpp"
#include <iostream>

class MyClass {
public:
    MyClass(int a, int b) {
        std::cout << a << ", " << b << std::endl;
    }
    MyClass(const MyClass &) {
        std::cout << "Copy" << std::endl;
    }
    MyClass(MyClass &&) {
        std::cout << "Move" << std::endl;
    }
};

int main() {
    proxy_ptr<int> a = 1;
    proxy_ptr<int> b = a;
    proxy_ptr<int> c = std::move(b);
    a = c;
    c = std::move(a);
    proxy_ptr<MyClass> d(42, 31);
    proxy_ptr<MyClass> e = d;
    proxy_ptr<MyClass> f = std::move(e);
    return 0;
}
