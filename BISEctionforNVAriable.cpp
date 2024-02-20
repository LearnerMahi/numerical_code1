#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> coefficients;

void string_to_coefficient(string s, int n) {
    vector<int> power(n, 0);
    int coeff = 0;
    int i = 0;

    while (i < s.length()) {
        if (s[i] == 'x') {
            i++; // skip 'x'
            for (int j = 0; j < n; j++) {
                if (i < s.length() && s[i] == '^') {
                    i++; // skip '^'
                    int power_j = 0;
                    while (i < s.length() && isdigit(s[i])) {
                        power_j = power_j * 10 + (s[i] - '0');
                        i++;
                    }
                    power[j] = power_j;
                }
            }
            if (i < s.length() && s[i] == '-' || s[i] == '+') {
                int sign = (s[i] == '-') ? -1 : 1;
                coefficients[power] += sign * coeff;
                i++;
            }
            coeff = 0;
        }
        else if (isdigit(s[i]) || s[i] == '-' || s[i] == '+') {
            int sign = 1;
            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            else if (s[i] == '+') {
                i++;
            }
            while (i < s.length() && isdigit(s[i])) {
                coeff = coeff * 10 + (s[i] - '0');
                i++;
            }
            coeff *= sign;
        }
        else {
            i++;
        }
    }
}

double f(vector<double> x, int n) {
    double result = 0;
    for (auto it : coefficients) {
        double term = it.second;
        for (int j = 0; j < n; j++) {
            term *= pow(x[j], it.first[j]);
        }
        result += term;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    coefficients.clear();

    cout << "Enter Equation: ";
    string s;
    cin >> s;
    string_to_coefficient(s, n);

    vector<double> lower_bounds(n);
    vector<double> upper_bounds(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter lower bound for x" << i + 1 << ": ";
        cin >> lower_bounds[i];
        cout << "Enter upper bound for x" << i + 1 << ": ";
        cin >> upper_bounds[i];
    }

    vector<double> x(n);

    for (int i = 0; i < n; i++) {
        x[i] = (lower_bounds[i] + upper_bounds[i]) / 2;
    }

    int max_iterations = 1000;
    double tolerance = 1e-6;

    for (int iteration = 0; iteration < max_iterations; iteration++) {
        double f_x = f(x, n);

        bool converged = true;
        for (int i = 0; i < n; i++) {
            double x_new = (lower_bounds[i] + upper_bounds[i]) / 2;
            x_new = max(lower_bounds[i], min(upper_bounds[i], x_new)); // Ensure x_new is within bounds
            if (fabs(x[i] - x_new) > tolerance) {
                x[i] = x_new;
                converged = false;
            }
        }

        if (converged || fabs(f(x, n)) < tolerance) {
            cout << "Converged to a root: ";
            for (int i = 0; i < n; i++) {
                cout << "x" << i + 1 << " = " << x[i] << " ";
            }
            cout << "f(x) = " << f(x, n) << endl;
            break;
        }
    }

    return 0;
}
