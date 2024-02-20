#include <bits/stdc++.h>
using namespace std;

map<int, int> pw;

void string_to_coefficient(string s) {
    int i = 0;
    while (i < s.length()) {
        int coeff = atoi(s.c_str() + i);
        i += log10(abs(coeff) + 1);
        int power = 0;
        if (i < s.length() && s[i] == '^') {
            power = atoi(s.c_str() + i + 1);
            i += log10(power) + 2;
        } else {
            power = 1; // Default power is 1 if not specified
        }
        pw[power] += coeff;
    }
}

double Func(double x) {
    double result = 0;
    for (auto it : pw) {
        result += it.second * pow(x, it.first);
    }
    return result;
}

double DeriveFunc(double x) {
    double result = 0;
    for (auto it : pw) {
        if (it.first > 1) {
            result += it.second * it.first * pow(x, it.first - 1);
        }
    }
    return result;
}

int main() {
    cout << "Enter Equation: ";
    string s;
    cin >> s;
    string_to_coefficient(s);

    double xn, xn1, h;
    cout << "Enter initial value: ";
    cin >> xn;

    int iterations = 0;
    do {
        h = Func(xn) / DeriveFunc(xn);
        xn1 = xn - h;
        xn = xn1;
        iterations++;
    } while (abs(h) >= 0.000001);

    cout << "Root: " << xn << endl;
    cout << "Iterations needed: " << iterations << endl;

    return 0;
}
