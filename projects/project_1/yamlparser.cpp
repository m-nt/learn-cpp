#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// global implementations
string _FILE_STORE = "contacts.yaml";
string _MAIN_NAME = "contacts";
string _INDEX_INDICATOR = "- ";


struct contact
{
    string uname;
    string name;
    string number;
};


int main() {
    ifstream _file("contacts.yaml", ios::in | ios::binary | ios::ate);
    vector<contact>* output;
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
            // cout << memblock[i] << '\n';
            // check for contracts name
            if (memblock[i] == 'c' || memblock[i + 1] == 'o' || memblock[i + 2] == 'n') {
                string maybe_contract(memblock + i, _MAIN_NAME.size());
                if (maybe_contract == _MAIN_NAME) {
                    cout << "found! " << maybe_contract << '\n';
                }
            }
        }
        delete[] memblock;
    }
    else cout << "Unable to open _file";
    return 0;
}