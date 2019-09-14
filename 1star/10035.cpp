//
// Created by Mark Hsu on 2019-09-12.
//

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int num1, num2;
    while (cin >> num1 >> num2 && (num1 != 0 || num2 != 0)) {
        int a[10], b[10], tmp1, tmp2, carryOperations = 0, flag = 0;

        a[0] = num1 % 10;
        b[0] = num2 % 10;

        for (int i = 1; i < 10; i++) {
            tmp1 = num1 / pow(10, i);
            tmp2 = num2 / pow(10, i);
            a[i] = tmp1 % 10;
            b[i] = tmp2 % 10;
        }

        for (int i = 0; i < 10; i++) {
            if (flag == 1) {
                a[i]++;
                flag = 0;
            }
            if (a[i] + b[i] > 9) {
                carryOperations++;
                flag = 1;
            }
        }

        if (carryOperations == 0) {
            cout << "No carry operation." << endl;
        } else if (carryOperations == 1) {
            cout << carryOperations << " carry operation." << endl;
        } else {
            cout << carryOperations << " carry operations." << endl;
        }
    }
}