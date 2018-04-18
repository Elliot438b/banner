//
// Created by liuwenbin on 18-4-18.
//
#include <string>
#include <iostream>

using namespace std;

string name = "Tracy Mcgrady";

void m3() {
    string s = name.substr(6, 7);
    cout << s << "\n";
    cout << name << "\n";
    name.replace(0, 5, "Hashs");
    cout << name << "\n";
    name[0] = tolower(name[0]);
    cout << name << "\n";
};

int main() {
    m3();
}