#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "helpers/Pair.h"
#include "structures/BinaryTree.h"
#include "structures/UnsortedTable.h"

using namespace std;

std::string removeNonAlphaNumeric(const std::string& input) {
    std::string result;
    bool previousSpace = false;

    for (char ch : input) {
        if (std::isalpha(ch) || std::isspace(ch)) {
            if (!(previousSpace && std::isspace(ch))) {
                result += std::tolower(ch);
            }
            previousSpace = std::isspace(ch);
        }
    }

    // Exclude the last space character, if present
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

void tokenizeString(const std::string& input, std::string tokens[], int& count) {
    std::stringstream ss(input);
    std::string token;

    count = 0;
    while (ss >> token) {
        tokens[count] = token;
        count++;
    }
}

template <typename T>
T ConstructData(T strc) {
    int z = 0;
    string myline;
    std::ifstream myfile;
    myfile.open("small-file.txt");
    if ( myfile.is_open() ) {
        while ( myfile && z < 1000) {
            getline (myfile, myline);
            string newl = removeNonAlphaNumeric(myline);
            std::string tokens[100];  // Assuming maximum of 100 tokens
            int tokenCount = 0;

            tokenizeString(newl, tokens, tokenCount);
            

            for (int i = 0; i < tokenCount-1; i++) {
                Pair<string> p(tokens[i],tokens[i+1]);
                strc.insert(p);
                z++;
            }
        }
    }
    myfile.close();
    return strc;
}


int main()
{
    BinaryTree bt = BinaryTree();
    UnsortedTable ut = UnsortedTable();
    ut = ConstructData(ut);
    ut.print();
    bt = ConstructData(bt);
    bt.printTree();

    
    return 0;
}