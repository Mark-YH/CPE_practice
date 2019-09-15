//
// Created by Mark Hsu on 2019-09-15.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    short int n, counter[2000] = {0};
    char input[76];
    string inputs[2000], country[2000];

    cin >> n;
    cin.get(); // get the '\n' character

    for (int i = 0; i < n; i++) {
        short int startFlag = 0, startIndex = 0, endIndex = 0;

        cin.getline(input, 76); // get one line

        for (int j = 0; j < 76; j++) {
            if (input[j] == ' ') { // found space
                if (startFlag) {
                    break;
                } else { // not found alphabetical character yet
                    startIndex++;
                }
            } else { // found alphabetical character
                startFlag = 1;
                endIndex++;
            }
        }
        inputs[i] = inputs[i].assign(input, startIndex, endIndex);
    }

    sort(inputs, inputs + n);

    country[0] = inputs[0];
    counter[0]++;

    int iCountries = 1;

    for (int i = 1; i < n; i++) {
        int flag = 1; // not found.

        for (int j = 0; j < iCountries; j++) {
            if (country[j] == inputs[i]) {
                counter[j]++;
                flag = 0; // found.
                break;
            }
        }
        if (flag) {
            country[iCountries] = inputs[i];
            counter[iCountries] = 1;
            iCountries++;
        }
    }

    for (int i = 0; i < iCountries; i++) {
        cout << country[i] << ' ' << counter[i] << endl;
    }
}