#ifndef PIGLET_H
#define PIGLET_H

#include <iostream>
#include "Tractor.h"

enum class Country {Russia, NoRussia};
const int goingDistance = 500;
const int distanceToEscapeFromRussia = 500;

class Piglet {
public:
    Piglet();
    Piglet(const Piglet & pig) {*this = pig;}
    Piglet(Piglet && pig) {*this = std::move(pig);}
    ~Piglet() {}
    Piglet & operator = (const Piglet & pig) {return *this = pig;}

    class stillInRussia {};
    class noRemembedTractor {};
    class noStoleTractor {};

    void Happiness();
    void Escape();
    void RememberTractor(Tractor &);
    void StealTractor();
protected:
    Country country;
    bool stoleTractor;
    Tractor * remembedTractor;
};

Piglet::Piglet():
    country(Country::Russia),
    stoleTractor(false),
    remembedTractor(nullptr) {}

void Piglet::Happiness() {
    std::cout << "Peter: Hooray! Hooray!" << std::endl;
}

void Piglet::Escape() {
    StealTractor();
    if (stoleTractor == false)
        throw noStoleTractor();
    remembedTractor->Go(distanceToEscapeFromRussia);
    if (remembedTractor->Mileage() < distanceToEscapeFromRussia)
        throw stillInRussia();
    Happiness();
}

void Piglet::StealTractor() {
    if (remembedTractor == nullptr) throw noRemembedTractor();
    stoleTractor = true;
}

void Piglet::RememberTractor(Tractor & tractor) {
    remembedTractor = &tractor;
}

#endif // PIGLET_H
