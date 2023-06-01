#ifndef IOHANDLER_h
#define IOHANDLER_H

#include <string>
#include "Pair.h"

template <typename STRC>
STRC buildPairs(STRC strc);

template <typename STRC>
STRC buildCPairs(STRC strc);

Pair<string>* generateQ();

#endif