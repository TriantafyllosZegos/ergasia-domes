#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

#include <thread>
#include <future>
#include <typeinfo>
#include "helpers/Pair.h"
#include "helpers/IOHandler.h"

#include "structures/BinaryTree.h"
#include "structures/UnsortedTable.h"
using namespace std;



int main()
{
    //Pair<string> * arrayQ = generateQ();

    ofstream md("markdown.md",std::ios_base::app);
    md << "---" << endl;
    md.close();

    UnsortedTable ut;
    auto t1 = std::async(buildStrc<UnsortedTable>,ut); 

    BinaryTree bt;
    auto t2 = std::async(buildStrc<BinaryTree>,bt); 
    
    ut = t1.get();
    bt = t2.get();
    
    //ut.print();
    //bt.print();
    
    cout << ut.getSize() << endl;
    return 0;
}
