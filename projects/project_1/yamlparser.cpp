#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <bits/stdc++.h> 
#include "yamlparser.h"
#include <boost/stacktrace.hpp>

using namespace std;

Yamlparser::Yamlparser(string file_path) : _FILE_STORE{ file_path }{}
Yamlparser::Yamlparser() : _FILE_STORE{ "contacts.yaml" }{}

void Yamlparser::save() {
    cout << "saving the contacts" << "\n";
    fstream _file(_FILE_STORE, ios::out | ios::binary);
    _file.seekp(0);
    _file.write(['c', 'o', 'n', 't', 'a', 'c', 't', 's', '\n'], 10);
    for (size_t i = 0; i < contacts.size(); i++) {
        
    }
    
}
void Yamlparser::print() {
    cout << "[index]\t[name]\t\t\t[number]" << '\n';
    for (size_t i = 0; i < contacts.size(); i++) {
        cout << "" << i + 1 << "\t" << contacts[i].name << "\t\t" << contacts[i].number << '\n';
    }
}
void Yamlparser::load_v2() {
    ifstream _file(_FILE_STORE, ios::in | ios::binary | ios::ate);
    vector<contact> _contacts;
    streampos size;
    char* memblock;
    if (_file.is_open()) {
        // load _file and set sizes
        size = _file.tellg();
        memblock = new char[size];
        _file.seekg(0, ios::beg);
        _file.read(memblock, size);
        _file.close();
        vector<lexer_v2> tokens;

        for (size_t i = 0; i < size; i++) {
            
        }
    }
}
void Yamlparser::load() {
    ifstream _file(_FILE_STORE, ios::in | ios::binary | ios::ate);
    vector<contact> _contacts;
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
                                        _contacts.push_back(the_contact);
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

        // parse the tokens to create a tree
        delete[] memblock;
    }
    else cout << "Unable to open _file";
    contacts = _contacts;
}
