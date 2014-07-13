#ifndef OLDTRACTOR_H
#define OLDTRACTOR_H

#include <algorithm>
#include "Tractor.h"

using std::for_each;

class OldTractor : public Tractor {
public:
    OldTractor() {
        for_each(begin(wheels), end(wheels), [](Wheel & i){i.Rotate(12);});
    }
};

#endif // OLDTRACTOR_H
