#include <bits/stdc++.h>
using namespace std;

vector<double> stringToCoefficient(string s) {
    vector<double> coefficient;
    regex r("(-?\\d*)x\\^(\\d+)");
    smatch m;
    while (regex_search(s, m, r)) {
        string coeff = m[1];
        string exp = m[2];

        if (coeff.empty()) coeff = "1";

        int cop = stoi(coeff);

        coefficient.push_back(cop);

        s = m.suffix();
    }
    return coefficient;
}

double f(double x, vector<double> coefficient) {
    int degree = coefficient.size() - 1;
    double result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coefficient[i] * pow(x, degree - i);
    }
    return result;
}

void secant(vector<double> coefficient, double x1, double x2) {
    double x0, n = 0, c, xm;
    if (f(x1, coefficient) * f(x2, coefficient) < 0) {
        do {
            x0 = (x1 * f(x2, coefficient) - x2 * f(x1, coefficient)) / (f(x2, coefficient) - f(x1, coefficient));

            c = f(x0, coefficient) * f(x1, coefficient);

            n++;

            x1 = x2;
            x2 = x0;

            if (c == 0)
                break;

            xm = (x1 * f(x2, coefficient) - x2 * f(x1, coefficient)) / (f(x2, coefficient) - f(x1, coefficient));
        } while (fabs(xm - x0) > 0.0001);
        cout << "Root : " << x0 << endl;
        cout << "Iteration : " << n << endl;
    } else {
        cout << "Could not find root in this range" << endl;
    }
}

int main() {
    string s = "4x^3+3x^2+4x^1+4x^0";
    vector<double> coefficient = stringToCoefficient(s);
    cout << "Enter the value of x1 and x2" << endl;
    double x1, x2;
    cin >> x1 >> x2;
    secant(coefficient, x1, x2);
    return 0;
}
