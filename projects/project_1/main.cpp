#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h> 
#include "yamlparser.cpp"
using namespace std;

// application entry point
int main(int argc, char const* argv[]) {
    Yamlparser yaml("contacts.yaml");
    yaml.load();
    yaml.print();
    yaml.save();
    return 0;
}
