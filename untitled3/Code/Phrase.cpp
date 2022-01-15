
#include "Poverb.h"
#include "Puzzle.h"
#include "Aphorism.h"
#include "Phrase.h"

Random Phrase::rnd(1, 20);

Phrase* Phrase::StaticIn(ifstream& ifst) {
    int k;
    ifst >> k;
    Phrase* ph = nullptr;
    switch (k) {
        case 1:
            ph = new Aphorism();
            break;
        case 2:
            ph = new Poverb();
            break;
        case 3:
            ph = new Puzzle();
            break;
    }
    ph->In(ifst);
    return ph;
}

Phrase* Phrase::StaticInRnd() {
    auto k = Phrase::rnd.GetRandomInt() % 3 + 1;
    Phrase* sp = nullptr;
    switch (k) {
        case 1:
            sp = new Aphorism;
            break;
        case 2:
            sp = new Puzzle;
            break;
        case 3:
            sp = new Poverb;
            break;
    }
    sp->InRnd();
    return sp;
}