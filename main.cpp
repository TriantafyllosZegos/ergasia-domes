#include <iostream>
#include <string>
#include "structures/Avl.h"

using namespace std;

int main()
{
    Pair<int>  a(13,25);
    Pair <string> b;
    string s;

    a.setFirst(a.getFirst()-1);
    a.setSecond(a.getSecond()+1);
    a.swap();

    cin>>s;
    b.setFirst(s);
    cin>>s;
    b.setSecond(s);
    b.swap();

    std::cout<<a<<std::endl<<b<<std::endl;
    cout << "Thank you!\n";
    return 0;
}