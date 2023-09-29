#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// global implementations
std::string _FILE_STORE = "contacts.yaml";

std::vector<std::string, int32_t> _CONTACTS;

// common operations
std::string load_file() {
    std::fstream _file;
    std::string line;
    std::string output;
    _file.open(_FILE_STORE);
    if (_file.is_open()) {
        while (getline(_file, line)) {
            output += line;
        }
    }
    return output;
}

// application entry point
int main(int argc, char const* argv[]) {
    std::cout << "hello world!\n";
    std::string str = load_file();
    std::cout << str << '\n';
    return 0;
}
