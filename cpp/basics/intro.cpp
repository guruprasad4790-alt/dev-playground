#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string name;
    int age;
    std::string quote;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter age: ";
    std::cin >> age; // after age the \n is not read by cin 
    std::cin.ignore(); // needs to be explicitly ignored for the next getline to work

    std::cout << "Enter fav quote: ";
    std::getline(std::cin, quote);

    // still using C++ 17 so no format yet
    std::stringstream message;
    message  <<"Hi, I am " << name 
        << ", I am " << age 
        << " years old and I am learning C++." << std::endl
        << "My fav quote : " << quote;

    std::cout<< message.str() << std::endl;

    return 0;
}