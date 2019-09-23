//
// Created by Mark Hsu on 2019-09-24.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string output[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    cin >> n;

    for (int i = 0; i < n; i++) {
        int count = 0, month, day;
        cin >> month >> day;

        switch (month) {
            case 12:
                count += 30;
            case 11:
                count += 31;
            case 10:
                count += 30;
            case 9:
                count += 31;
            case 8:
                count += 31;
            case 7:
                count += 30;
            case 6:
                count += 31;
            case 5:
                count += 30;
            case 4:
                count += 31;
            case 3:
                count += 28;
            case 2:
                count += 31;
        }

        count += day - 1;

        cout << output[count % 7] << endl;
    }
}