#include <iostream>//для std::cout, std::cin
#include <string>//для std::string пупупу

int main() {
    std::string name;
    std::cout << "Enter @name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
