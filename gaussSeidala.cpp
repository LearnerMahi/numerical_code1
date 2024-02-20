#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to parse a string equation into coefficients and constants
bool parseEquation(const string& equation, vector<double>& coefficients, double& constant) {
    istringstream iss(equation);
    coefficients.clear();
    constant = 0.0;

    double coefficient;
    while (iss >> coefficient) {
        coefficients.push_back(coefficient);
    }

    if (!coefficients.empty()) {
        constant = coefficients.back();
        coefficients.pop_back();
        return true;
    }

    return false;
}

// Function to perform Gauss-Seidel iteration
vector<double> gaussSeidel(const vector<vector<double>>& A, const vector<double>& b, double tol, int maxIter) {
    int n = A.size();
    vector<double> x(n, 0.0);

    for (int iter = 0; iter < maxIter; iter++) {
        vector<double> x_new = x;

        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x_new[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += abs(x[i] - x_new[i]);
        }

        if (error < tol) {
            cout << "Converged after " << iter + 1 << " iterations." << endl;
            return x;
        }
    }

    cout << "Gauss-Seidel did not converge within " << maxIter << " iterations." << endl;
    return x;
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter the equations in the form of 'a1 a2 ... an constant':" << endl;
    for (int i = 0; i < n; i++) {
        string equation;
        cin.ignore();
        getline(cin, equation);

        vector<double> coefficients;
        double constant;

        if (parseEquation(equation, coefficients, constant)) {
            A[i] = coefficients;
            b[i] = constant;
        } else {
            cerr << "Invalid equation format. Please provide equations in the specified format." << endl;
            return 1;
        }
    }

    double tolerance;
    cout << "Enter the tolerance for convergence: ";
    cin >> tolerance;

    int maxIterations;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    vector<double> result = gaussSeidel(A, b, tolerance, maxIterations);

    cout << "Solution: ";
    for (int i = 0; i < result.size(); i++) {
        cout << "x[" << i << "] = " << result[i] << " ";
    }
    cout << endl;

    return 0;
}

