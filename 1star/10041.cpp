#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int r, s[500];
    cin >> r;

    for (int k = 0; k < r; k++) {
        int n, sum = 0, home;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        sort(s, s + n);

        home = s[n / 2];
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(s[j] - home);
        }

        cout << sum << endl;
    }
}
