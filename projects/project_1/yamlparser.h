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
struct yaml_object {
    string tag;
    string value;
    yaml_object child;
}
enum yaml_tokens {
    VERSION = "%YAML ",
    FILE_DIV = "---",
    TAG = ':',
    ARRAY = '-',
    TAB = "  ",
    LITRAL_STYLE = '|',
    FOLDED_STYLE = '>',
    ENUM_START = '[',
    ENUM_END = ']',
}
struct lexer {
    size_t index;
    size_t value_start_index;
    string token;
};
struct lexer_v2 {
    size_t tag_start_index;
    size_t tag_size;
    size_t value_start_index;
    size_t value_size;
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
    void load_v2();
    void print();
};
