#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    streampos size;
    char* memblock;

    ifstream file("contacts.yaml", ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
        // load file and set sizes
        size = file.tellg();
        memblock = new char[size];
        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();

        // itterate through all characters of the file from memory
        for (size_t i = 0; i < size; i++) {
            cout << memblock[i] << '\n';
        }

        delete[] memblock;
    }
    else cout << "Unable to open file";
    return 0;
}