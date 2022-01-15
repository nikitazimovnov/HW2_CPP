#ifndef __phrase__
#define __phrase__

#include <fstream>
using namespace std;

#include "Random.h"

class Phrase {
protected:
    static Random rnd;
public:
    virtual ~Phrase() {};
    static Phrase* StaticIn(ifstream& ifdt);
    virtual void In(ifstream& ifdt) = 0;

    static Phrase* StaticInRnd();

    virtual void InRnd() = 0;

    virtual void Out(ofstream& ofst) = 0;

    virtual void Generate(ofstream& ofst) = 0;

    virtual double MainFunc() = 0;

    int special_length;
    int text_length;
    int signs_count;
};

#endif