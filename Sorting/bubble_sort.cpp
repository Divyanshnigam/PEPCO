#include<bits/stdc++.h>

using namespace std;

int main()
{
    //  code starts
    int i, n;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (1) {
        bool check = false;
        for (i = 0; i <= n - 2; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                check = true;
            }
        }
        if (check == false) {
            break;
        }
    }
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
