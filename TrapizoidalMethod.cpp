
#include <bits/stdc++.h>
using namespace std;

double func(double x) {
    return log(x);
}

int main() {
    int n;
    cout << "Enter the number of steps:" << endl;
    cin >> n;
    double a, b, sum = 0, h;

    double x[n], y[n];
    cout << "Enter the initial value of the limit" << endl;
    cin >> a;
    cout << "Enter the final value of the limit" << endl;
    cin >> b;
    h = (b - a) / n;
    x[0] = a;
    y[0] = func(x[0]);

    for (int i = 1; i <= n; i++) {
        x[i] = x[0] + i * h;
        y[i] = func(x[i]);
    }

    for (int i = 1; i < n; i++) {
        sum += y[i];
    }

    double ans = h * (0.5 * (y[0] + y[n]) + sum);
    cout << "Now the answer is: " << ans << endl;

    return 0;
}
