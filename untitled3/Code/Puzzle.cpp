#include "Puzzle.h"
#include "Random.h"

void Puzzle::In(ifstream& ifst) {
    ifst >> special_length >> text_length >> signs_count;
}

void Puzzle::InRnd() {
    string text = Phrase::rnd.Random_text();
    text_length = text.length();
    special_length = Phrase::rnd.Random_special().length();
    int count = 0;
    for (char sym : text){
        if (sym == '.' || sym == ',' || sym == '-')
            count++;
    }
    signs_count = count;
}

void Puzzle::Out(ofstream& ofst) {
    ofst << "It is Puzzle \n"
         << "Answer length: " << special_length << "\n"
         << "Text length: " << text_length << "\n" << "signs count:" << signs_count << "\n"
         << "main_func = " << MainFunc() << "\n" << "\n";
}

void Puzzle::Generate(ofstream& ofst) {
    ofst << 3 << " " << special_length << " " << text_length << " " << signs_count;
}

double Puzzle::MainFunc() {
    return ((double)signs_count) / (text_length);
}