#include <iostream>
#include "structures/Avl.h"

using namespace std;

int main() {
    Avl *s = new Avl(123,123);
    cout << s->getMaxKM() << endl;
    return 0;
}
