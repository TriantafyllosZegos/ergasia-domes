#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <chrono>

#include "helpers/Pair.h"
#include "helpers/ConstructData.h"

#include "structures/BinaryTree.h"
#include "structures/UnsortedTable.h"
using namespace std;

int main()
{
    ofstream out("output.txt",std::ios_base::ate);
    //Pair<string> * arrayQ = generateQ();

    chrono::system_clock::time_point start,end;
    double time;

    

    start = chrono::high_resolution_clock::now();
    
    UnsortedTable ut;
    ut = ConstructData(ut);
    ut.print();
    end = chrono::high_resolution_clock::now();

    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count() * 1e-9;
    out << "UnsortedTable construction time : " << time << " sec" << endl;


    

    start = chrono::high_resolution_clock::now();

    BinaryTree bt;
    bt = ConstructData(bt);
    bt.print();

    end = chrono::high_resolution_clock::now();
    time = chrono::duration_cast<chrono::nanoseconds>(end-start).count() * 1e-9;
    out << "BinaryTree construction time : " << time << " sec" << endl;


    out.close();
    return 0;
}
