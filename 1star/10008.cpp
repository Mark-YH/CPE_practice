//
// Created by Mark Hsu on 2019-09-22.
//

#include <iostream>
#include <cstring>

using namespace std;

void count(char c, int *freq) {
    int pos = (int) c - 65;
    freq[pos]++;
}

int main() {
    int frequency[26];
    char name[26];
    char input;

    for (int i = 0; i < 26; i++) {
        name[i] = 65 + i;
        frequency[i] = 0;
    }

    // A ~ Z: 65 ~ 90
    // a ~ z: 97 ~ 122
    do {
        input = cin.get();
        if (input >= 97 && input <= 122) {
            count(toupper(input), frequency);
        } else if (input >= 65 && input <= 90) {
            count(input, frequency);
        }
    } while (input != EOF);

    int max = 0;

    for (int i = 0; i < 26; i++) {
        if (frequency[i] > max) {
            max = frequency[i];
        }
    }

    int count = 0;
    while (count < 26) {
        if (max == 0)
            break;

        for (int i = 0; i < 26; i++) {
            if (frequency[i] == max) {
                cout << name[i] << ' ' << frequency[i] << endl;
                count++;
            }
        }

        max--;
    }
}