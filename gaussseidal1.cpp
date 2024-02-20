#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to perform Gauss-Seidel iteration
vector<double> gaussSeidel(const vector<vector<double>>& A, const vector<double>& b, double tol, int maxIter) {
    int n = A.size();
    vector<double> x(n, 0.0); // Initialize the solution vector with zeros

    for (int iter = 0; iter < maxIter; iter++) {
        vector<double> x_new = x; // Create a copy of the solution vector for updating

        for (int i = 0; i < n; i++) {
            double sum = 0.0;

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * x_new[j];
                }
            }

            x[i] = (b[i] - sum) / A[i][i]; // Gauss-Seidel update
        }

        // Check for convergence
        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += abs(x[i] - x_new[i]);
        }

        if (error < tol) {
            cout << "Converged after " << iter + 1 << " iterations." << endl;
            return x; // Return the solution if it converges
        }
    }

    cout << "Gauss-Seidel did not converge within " << maxIter << " iterations." << endl;
    return x; // Return the current solution even if it didn't converge
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter the matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the vector b:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    double tolerance;
    cout << "Enter the tolerance for convergence: ";
    cin >> tolerance;

    int maxIterations;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    vector<double> result = gaussSeidel(A, b, tolerance, maxIterations);

    // Output the solution
    cout << "Solution: ";
    for (int i = 0; i < result.size(); i++) {
        cout << "x[" << i << "] = " << result[i] << " ";
    }
    cout << endl;

    return 0;
}
