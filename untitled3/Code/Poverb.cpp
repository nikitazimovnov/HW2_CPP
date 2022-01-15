#include "Poverb.h"
#include "Random.h"

void Poverb::In(ifstream& ifst) {
    ifst >> special_length >> text_length >> signs_count;
}

void Poverb::InRnd() {
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

void Poverb::Out(ofstream& ofst) {
    ofst << "It is Poverb \n"
         << "Country length: " << special_length << "\n"
         << "Text length: " << text_length << "\n" << "signs count:" << signs_count << "\n"
         << "main_func = " << MainFunc() << "\n" << "\n";
}

void Poverb::Generate(ofstream& ofst) {
    ofst << 2 << " " << special_length << " " << text_length << " " << signs_count;
}

double Poverb::MainFunc() {
    return ((double)signs_count) / (text_length);
}
