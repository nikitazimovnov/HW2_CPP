#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Random {
public:
    Random(int f, int l) {
        if (f <= l) {
            first = f;
            last = l;
        }
        else {
            first = l;
            last = f;
        }

        srand(static_cast<unsigned int>(time(0)));
    }

    int GetRandomInt() {
        return rand() % (last - first + 1) + first;
    }

    double GetRandomDouble() {
        double min = 0;
        double max = 100;
        double f = (double)rand() / RAND_MAX;
        return min + f * (max - min);
    }

    string Random_special(){
        int length = rand() % 10 + 5;
        string  special = "";

        for (int i = 0; i < length; ++i) {
            special += (rand() % ('a' - 'z' + 1)) + 'a';
        }

        return special;
    }

    string Random_text() {
        int length = rand() % 100 + 10;
        string text = "";
        int flag;
        for (int i = 0; i < length; ++i) {
            flag = rand();
            text += (rand() % ('a' - 'z' + 1)) + 'a';
            if (flag % 20 == 1) {
                text += '.';
            }
            else if (flag % 20 == 2){
                text += ',';
            }
            else if (flag % 20 == 3){
                text += '-';
            }
        }
        return text;
    }

private:
    int first;
    int last;
};

#endif //__rnd__
