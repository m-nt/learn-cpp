#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// global implementations
string _FILE_STORE = "contacts.yaml";

struct contact
{
    string uname;
    string name;
    string number;
};


int main() {
    ifstream _file("contacts.yaml", ios::in | ios::binary | ios::ate);
    vector<contact> contacts;
    vector<contact>* output = &contacts;
    streampos size;
    char* memblock;
    if (_file.is_open()) {
        // load _file and set sizes
        size = _file.tellg();
        memblock = new char[size];
        _file.seekg(0, ios::beg);
        _file.read(memblock, size);
        _file.close();

        // itterate through all characters of the _file from memory
        for (size_t i = 0; i < size; i++) {

            // check for contracts name
            string contract(memblock + i, 8);
            if (contract == "contacts") {
                cout << "found! a index:" << i << " is contact" << '\n';
            }
            if (memblock[i] == ':') {
                // string index_name(memblock + i, )
                cout << "found! a index:" << i << " is  :" << '\n';
            }
            // check for '-'
            if (memblock[i] == '-') {
                cout << "found! a index:" << i << " is  -" << '\n';
            }
            // check for double space
            if (memblock[i] == ' ') {
                cout << "found! a index:" << i << " is space" << '\n';
            }
            // check for \n
            if (memblock[i] == '\n') {
                cout << "found! a index:" << i << " is  \\n" << '\n';
            }
        }
        delete[] memblock;
    }
    else cout << "Unable to open _file";
    return 0;
}