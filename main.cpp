#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

#include "helpers/Pair.h"
#include "helpers/ConstructData.h"

#include "structures/BinaryTree.h"
#include "structures/UnsortedTable.h"

using namespace std;

int main()
{
    UnsortedTable ut = UnsortedTable();
    ut = ConstructData(ut);
    ut.print();
    
    BinaryTree bt = BinaryTree();
    bt = ConstructData(bt);
    bt.print();

    return 0;
}