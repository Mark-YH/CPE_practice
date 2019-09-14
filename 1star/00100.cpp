//
// Created by Mark Hsu on 2019-09-14.
//

#include <iostream>

using namespace std;


int algorithm(int n) {
    int result = 0;
    result++;
    if (n == 1) {
        return result;
    } else if (n % 2 == 0) {
        n = n / 2;
        return algorithm(n) + result;
    } else {
        n = 3 * n + 1;
        return algorithm(n) + result;
    }
}

int main() {
    int lowerBound, upperBound, flag = 0;
    while (cin >> lowerBound >> upperBound) {
        if (lowerBound > upperBound) {
            int temp = lowerBound;
            lowerBound = upperBound;
            upperBound = temp;
            flag = 1;
        }

        int cycleLength = 0;

        for (int i = lowerBound; i <= upperBound; i++) {
            int tmp = algorithm(i);
            if (tmp > cycleLength)
                cycleLength = tmp;
        }
        if (flag) {
            cout << upperBound << ' ' << lowerBound << ' ' << cycleLength << endl;
            flag = 0;
        } else
            cout << lowerBound << ' ' << upperBound << ' ' << cycleLength << endl;
    }
}