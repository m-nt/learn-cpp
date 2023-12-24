#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct contact {
    string uname;
    string name;
    string number;
};
enum contact_types {
    UNKNOWN = 0,
    UNAME = 1,
    VALUE_NAME = 2,
    VALUE_NUMBER = 3,
    VALUE = 4
};
struct lexer {
    size_t index;
    size_t value_start_index;
    string token;
};

class Yamlparser {
private:
    string _FILE_STORE;
public:
    vector<contact> contacts;
    Yamlparser(string path);
    Yamlparser();
    void save();
    void load();
    void print();
};
