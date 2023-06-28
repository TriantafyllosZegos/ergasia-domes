#ifndef IOHANDLER_h
#define IOHANDLER_H

#include <string>
#include "Pair.h"
#include "Structure.h"

void buildPairs(Structure * strc,const string FILE_PATH);

void runStructure(Structure * strc,const string FILE_PATH,const Pair<string> * Q,const int);

const Pair<string> * generateQ(const string FILE_PATH,const int NUMBER_OF_SEARCH);

#endif