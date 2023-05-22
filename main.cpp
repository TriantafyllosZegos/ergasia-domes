#include <iostream>
#include <string>

using namespace std;

int main()
{
    pair<string,string> p = pair("hi","bye");

    cout << p.first << "," << p.second << endl;
    cout << "Thank you!\n";
    return 0;
}