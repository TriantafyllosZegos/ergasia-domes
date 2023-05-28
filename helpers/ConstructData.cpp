#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "Pair.h"
#include "ConstructData.h"
#include "../structures/BinaryTree.h"
#include "../structures/UnsortedTable.h"

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
};

void tokenizeString(const std::string& input, std::string tokens[], int& count) {
    std::stringstream ss(input);
    std::string token;

    count = 0;
    while (ss >> token) {
        tokens[count] = token;
        count++;
    }
};

template <typename STRC>
STRC ConstructData(STRC strc) {
    int z = 0;
    string myline;
    std::ifstream myfile;
    myfile.open("small-file.txt");
    if ( myfile.is_open() ) {
        while ( myfile && z < 300000) {
            getline (myfile, myline);
            string newl = removeNonAlphaNumeric(myline);
            if (newl == "") continue;
            std::string tokens[25];  
            int tokenCount = 0;

            tokenizeString(newl, tokens, tokenCount);

            for (int i = 0; i < tokenCount-1; i++) {
                Pair<string> p = Pair(tokens[i],tokens[i+1]);
                strc.insert(p);
                z++;
                if (z == 300001) break;
            }
            
        }
    }
    myfile.close();
    return strc;
};

template BinaryTree ConstructData<BinaryTree>(BinaryTree);
template UnsortedTable ConstructData<UnsortedTable>(UnsortedTable);


Pair<string>* generateQ() {
    int z = 0;
    Pair<string>* aQ = new(nothrow) Pair<string>[1004];
    if (aQ == NULL) cout << "aQ MEMORY ERROR" << endl;
    string myline;
    std::ifstream myfile;
    myfile.open("small-file.txt");
    if ( myfile.is_open() ) {
        while ( myfile && z < 1000) {
            getline (myfile, myline);
            string newl = removeNonAlphaNumeric(myline);
            std::string tokens[25];  // Assuming maximum of 100 tokens
            int tokenCount = 0;

            tokenizeString(newl, tokens, tokenCount);
            for (int i = 0; i < tokenCount-1; i++) {
                int random = rand() % 10;
                if (random == 7){
                    Pair<string> p(tokens[i],tokens[i+1]);
                    aQ[z] = p;
                    z++;
                    if (z == 1000) break;
                }
            }
        }
    }
    myfile.close();
    cout << "aQ size : " << z << endl;
    return aQ;
};
