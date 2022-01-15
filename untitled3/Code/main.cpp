#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "Container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01\n"
            "  Or:\n"
            "     command -n number outfile01\n"
            "  Or:\n"
            "     command -g number outfile01\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01\n"
            "  Or:\n"
            "     command -n number outfile01\n"
            "  Or:\n"
            "     command -g number outfile01\n";
}

int main(int argc, char* argv[]) {
    unsigned int start_time = clock();
    if (argc != 4) {
        errMessage1();
        return 1;
    }

    cout << "Start" << endl;
    Container c;
    if (!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        c.In(ifst);
    }
    else if ((!strcmp(argv[1], "-n"))  || (!strcmp(argv[1], "-g"))) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            cout << "incorrect numer of languages = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        c.InRnd(size);
    }
    if (!strcmp(argv[1], "-g")) {
        ofstream ofstGen(argv[3]);
        c.Generate(ofstGen);
        std::cout << "Generated!";
        return 0;
    }
    else if (!(strcmp(argv[1], "-g") || strcmp(argv[1], "-f") || strcmp(argv[1], "-n"))) {
        errMessage2();
        return 2;
    }

    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.Out(ofst1);

    ofst1 << "\n \n \n" << "Shake-Sorted container: \n";
    c.ShakeSort();
    c.Out(ofst1);

    cout << "Stop" << endl;
    unsigned int end_time = clock();
    std::cout << "working time: " << end_time - start_time << " ms\n";
    return 0;
}
