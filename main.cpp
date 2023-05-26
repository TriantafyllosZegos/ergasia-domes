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
    Pair<string> * arrayQ = generateQ();

    for (int i = 0;i< 10;i++){
        cout << arrayQ[i]<< endl; //show first 10 Qs
    }

    //UnsortedTable ut = UnsortedTable();
    //ut = ConstructData(ut);
    //ut.print();
    
    //BinaryTree bt = BinaryTree();
    //bt = ConstructData(bt);
    //bt.print();

    return 0;
}