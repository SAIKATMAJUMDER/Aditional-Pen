#include <iostream>

#include <bits/stdc++.h>
using namespace std;

int mincoins(int C[], int N, int V)
{
    if (V == 0)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < N; i++) {
        int sub;
        if (V >= C[i]) {
            sub = 1 + mincoins(C, N, V - C[i]);
            res = min(res, sub);
        }
    }
    return res;
}

int main()
{
    cout << "Enter number of test cases: ";
    int t;
    cin >> t;

    while (t--) {
        int N, V;

        cout << "Enter the size of Coins array: ";
        cin >> N;

        int C[N];
        cout << "Enter the coins: ";
        for (int i = 0; i < N; i++)
            cin >> C[i];

        cout << "Enter V (Required sum): ";
        cin >> V;

        int res = INT_MAX;
        res = mincoins(C, N, V);
        if (res == INT_MAX or res < 0) {
            cout << "NOT POSSIBLE: ";
            cout << 0;
        }
        else {
            cout << "Required coins: ";
            cout << res << "\n";
        }
    }
    return 0;
}
