#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

// global implementations
string _FILE_STORE = "contacts.yaml";

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


int main() {
    // timing the proccess
    clock_t start, end;
    start = clock();
    ios_base::sync_with_stdio(false);

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
        vector<lexer> tokens;
        // itterate through all characters of the _file from memory
        for (size_t i = 0; i < size; i++) {
            lexer token;
            // check for contracts name
            string contact(memblock + i, 8);
            if (contact == "contacts") {
                // cout << "found! a index:" << i << " is contact" << '\n';
                token.index = i;
                token.token = contact;
                tokens.push_back(token);
            }
            if (memblock[i] == ':') {
                // string index_name(memblock + i, )
                token.index = i;
                token.token = memblock[i];
                tokens.push_back(token);
            }
            // check for '-'
            if (memblock[i] == '-') {
                token.index = i;
                token.token = memblock[i];
                tokens.push_back(token);
            }
            // check for double space
            if (memblock[i] == ' ') {
                token.index = i;
                token.token = memblock[i];
                tokens.push_back(token);
            }
            // check for \n
            if (memblock[i] == '\n') {
                token.index = i;
                token.token = memblock[i];
                tokens.push_back(token);
            }
        }
        contact the_contact;
        contact_types _contact_type = UNKNOWN;
        for (size_t i = 0; i < tokens.size(); i++) {
            // cout << "token: " << tokens[i].token << " - index: " << tokens[i].index << '\n';
            if (tokens[i].token == "contacts") {
                the_contact = contact();
            }
            if (tokens[i].token == "\n") {
                int space_counter = 0, inner_index = tokens[i].index + 1;
                while (true) {
                    if (memblock[inner_index] == ' ') {
                        space_counter++;
                    }
                    else {
                        break;
                    }
                    inner_index++;
                }
                if (space_counter == 2) {
                    _contact_type = UNAME;
                }
                else if (space_counter == 4) {
                    _contact_type = VALUE_NAME;
                }
            }
            if (tokens[i].token == "-") {
                int inner_index = tokens[i].index + 1, inner_start_index = tokens[i].index + 2;
                while (true) {
                    if (memblock[inner_index] == ':') {
                        string _value(memblock + inner_start_index, inner_index - inner_start_index);
                        switch (_contact_type) {
                        case UNAME:
                            the_contact.uname = _value;
                            break;
                        case VALUE_NAME: {
                            // the_contact.name = _value;
                            int this_while_counter = 0;
                            inner_start_index += inner_index - inner_start_index + 2;
                            while (true) {
                                if (memblock[inner_index] == '\n') {
                                    string _inner_value(memblock + inner_start_index, inner_index - inner_start_index);
                                    if (_value == "name") {
                                        the_contact.name = _inner_value;
                                    }
                                    else if (_value == "number") {
                                        the_contact.number = _inner_value;
                                        contacts.push_back(the_contact);
                                    }
                                    break;
                                }
                                if (memblock[inner_index] == ' ' && this_while_counter == 0) {
                                    continue;
                                }
                                inner_index++;
                                this_while_counter++;
                                if (this_while_counter > 265) {
                                    break;
                                }
                            }
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    if (memblock[inner_index] == '\n') {
                        break;
                    }
                    inner_index++;
                }
            }
        }
        cout << contacts.size() << " contact is loaded" << '\n';
        for (size_t i = 0; i < contacts.size(); i++) {
            cout << "[#" << i + 1 << "]-name: " << contacts[i].name << " -number: " << contacts[i].number << '\n';
        }

        // parse the tokens to create a tree

        delete[] memblock;

        // timing the process
        end = clock();
        // Calculating total time taken by the program.
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << fixed
            << time_taken << setprecision(5);
        cout << " sec " << endl;
    }
    else cout << "Unable to open _file";
    return 0;
}