#include <iostream>
#include "OldTractor.h"
#include "Piglet.h"

inline void displayAnError(const char * message) {
    std::cerr << message << std::endl;
}

int main()
{
    try {
        Piglet Peter;
        OldTractor oldTractor;
        Peter.RememberTractor(oldTractor);
        Peter.Escape();
    }
    catch (Piglet::stillInRussia) {
        displayAnError("I can't across the border.");
    }
    catch (Piglet::noRemembedTractor) {
        displayAnError("Wtf? Where is it tractor?");
    }
    catch (Piglet::noStoleTractor) {
        displayAnError("I got the police.");
    }
    return 0;
}

