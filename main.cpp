#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int to_int(string x) {
    int num = 0;
    for (int i = x.length(); i >= 1; i--) {
        num += ((int)x[i - 1] - 48) * pow(10, x.length() - i);
    }
    return num;
}

int where_tab(string str) {
    for (int j = 0; j < str.length(); j++) {
        if (str[j] == '\t')
            return j;
    }
}

int main() {

    fstream file;
    file.open("C:\\Users\\igora\\Desktop\\liczby.txt", ios::out);
    for (int i = 1; i < 20; i++) {
        file << i << '\t' << i * 10 << endl;
    }
    file.close();

    file.open("C:\\Users\\igora\\Desktop\\liczby.txt", ios::in);
    fstream file1;
    file1.open("C:\\Users\\igora\\Desktop\\liczby1.txt", ios::out);
    string line;
    int i = 0;
    while (getline(file, line)) {
        string first = "";
        string second = "";
        int tab = where_tab(line);
        for (int k = 0; k < tab; k++) {
            first += line[k];
        }
        for (int l = tab+1; l < line.length(); l++) {
            second += line[l];
        }
        file1 << to_int(first) + to_int(second) << endl;
        i++;
    }

    return 0;
}
