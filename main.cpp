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
//#include "structures/BinaryTree.h"
#include "structures/Table.h"

using namespace std;



int main()
{
    //Pair<string> * arrayQ = generateQ();

    ofstream md("markdown.md",std::ios_base::app);
    md << "---" << endl;
    md.close();

    Table ut;
    //auto t1 = std::async(buildStrc<Table>,ut); 
    ut = buildStrc(ut);
    //BinaryTree st;
    //auto t2 = std::async(buildStrc<BinaryTree>,bt); 
    
    
    //st = buildStrc(st);
    //bt = t2.get();
    //ut.print();
    //bt.print();
    
    return 0;
}
