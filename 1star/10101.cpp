//
// Created by Mark Hsu on 2019-09-14.
//
/**
 *
 * kuti: 千萬
 * lakh: 十萬
 * hajar: 千
 * shata: 百
 *
 * k l hs  k l hs
 * 4000000 00000000
 *    6000 00000000
 *          4000000
 *            90000
 * ----------------
 * 4006110 04090000
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

void calculate(unsigned long long int input, int flag, int rightPart) {
    string units[4] = {"kuti", "lakh", "hajar", "shata"};
    if (flag) {
        calculate(input / 10000000, 0, 0);
    }

    if (rightPart && input > 100000) {
        if (input / 100000 % 100 != 0)
            cout << ' ' << (input / 100000) % 100 << ' ' << units[0];
        else
            cout << ' ' << units[0];
    } else {
        if (input / 100000 % 100 != 0)
            cout << ' ' << (input / 100000) % 100 << ' ' << units[0];
    }
    if (input / 1000 % 100 != 0)
        cout << ' ' << (input / 1000) % 100 << ' ' << units[1];
    if (input / 10 % 100 != 0)
        cout << ' ' << (input / 10) % 100 << ' ' << units[2];
    if (input % 10 != 0)
        cout << ' ' << input % 10 << ' ' << units[3];
}

int main() {
    unsigned long long int input;
    int count = 1;

    while (cin >> input) {
        cout << setw(4) << count << ".";
        count++;

        if (input == 0) {
            cout << ' ' << 0 << endl;
            continue;
        }

        if (input > 1000000000)
            calculate(input / 100, 1, 1);
        else
            calculate(input / 100, 0, 1);

        if (input % 100 != 0) {
            cout << ' ' << input % 100;
        }
        cout << endl;
    }
}