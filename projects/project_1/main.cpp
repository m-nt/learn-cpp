#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// common operations


// application entry point
int main(int argc, char const* argv[]) {
    std::cout << "hello world!\n";
    std::string str = load_file();
    std::cout << str << '\n';
    return 0;
}
