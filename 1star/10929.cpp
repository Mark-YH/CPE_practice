//
// Created by Mark Hsu on 2019-09-14.
//
#include <iostream>

using namespace std;

int main() {
    char c[1001];
    int odd[500], even[500];
    int oddLength = 0, evenLength = 0, digits = 0;

    while (cin >> c) {
        if (c[digits] == '0' && c[digits + 1] == '\0')
            return 0;

        for (int i = 0; i < 1001; i++) {
            if (c[digits] == '\0') {
                int sumOdd = 0, sumEven = 0;

                for (int j = 0; j < oddLength; j++) {
                    sumOdd += odd[j];
                }

                for (int j = 0; j < evenLength; j++) {
                    sumEven += even[j];
                }

                evenLength = 0;
                oddLength = 0;

                for (int j = 0; j < digits; j++) {
                    if (j % 2 == 0) {
                        cout << even[evenLength];
                        evenLength++;
                    } else {
                        cout << odd[oddLength];
                        oddLength++;
                    }
                }

                if ((sumEven - sumOdd) % 11 == 0) {
                    cout << " is a multiple of 11." << endl;
                } else {
                    cout << " is not a multiple of 11." << endl;
                }

                oddLength = 0;
                evenLength = 0;
                digits = 0;
                break;
            } else if (digits % 2 == 0) {
                even[evenLength] = (int) c[digits] - 48;
                evenLength++;
                digits++;
            } else {
                odd[oddLength] = (int) c[digits] - 48;
                oddLength++;
                digits++;
            }
        }
    }
}