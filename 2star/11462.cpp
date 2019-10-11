//
// Created by Mark Hsu on 2019-10-09.
//

#include <iostream>

using namespace std;

int main() {
    int n, arr[100], input;
    cin >> n;
    while (n) {
        for (int i = 0; i < 100; i++) {
            arr[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            arr[input]++;
        }


        for (int i = 0; i < 100; i++) {
            if (arr[i] == 0)
                continue;
            for (int j = 0; j < arr[i]; j++)
                cout << i << ' ';
        }
        cout << endl;
        cin >> n;
    }
}