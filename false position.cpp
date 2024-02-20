#include <bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000

double func(double x, vector<double> coefficients) {
    double result = 0.0;
    int degree = coefficients.size() - 1;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

void regulaFalsi(vector<double> coefficients, double a, double b) {
    if (func(a, coefficients) * func(b, coefficients) >= 0) {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;

    for (int i = 0; i < MAX_ITER; i++) {
        c = (a * func(b, coefficients) - b * func(a, coefficients)) / (func(b, coefficients) - func(a, coefficients));

        if (func(c, coefficients) == 0)
            break;

        else if (func(c, coefficients) * func(a, coefficients) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}

int main() {
    double a, b;
    int degree;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coefficients(degree + 1);
    cout << "Enter the coefficients of the polynomial (from highest degree to lowest):\n";
    for (int i = degree; i >= 0; i--) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    regulaFalsi(coefficients, a, b);
    return 0;
}

