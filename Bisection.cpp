#include <bits/stdc++.h>
#include <cmath>
using namespace std;

vector<double> v;

void parse(string s)
{
    // ax^2+bx+c
    int i = 0;
    int sign = 1;
    int num = 0;
    int var = 0;
    if (s[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    for (; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + (s[i] - '0');
        }
        else
        {
            if (num == 0)
                num = 1;
            v.push_back(sign * num);
            num = 0;
            sign = 1;
            if (var == 0)
            {
                var = 1;
                i += 3;
            }
            else
            {
                i++;
            }
            if (s[i] == '-')
            {
                sign = -1;
            }
        }
    }
    v.push_back(sign * num);
}

double function_x(double x)
{
    return v[0] * x * x + v[1] * x + v[2];
}

double x1, x2;
double b;
void initial_value()
{
    b = ((v[1] / v[0]) * (v[1] / v[0])) - (2 * (v[2] / v[0]));
    b = sqrt(b);
}

void bisection()
{
    for (int i = -1 * b; i < b; i++)
    {
        for (int j = (-1 * b) + 1; j <= b; j++)
        {
            if (function_x(i) * function_x(j) < 0)
            {
                x1 = i;
                x2 = j;
            }
        }
    }
    cout << x1 << " " << x2 << endl;


    int it = 0;
    double x3;
    while (it < 100)
    {
        x3 = (x1 + x2) / 2.0;
        cout << "Iterations= " << it << " Roots= " << x3 << endl;
        if (fabs(function_x(x3)) < 0.00001)
        {
            cout << "Converged to root after " << it << " iterations." << endl;
            return;
        }
        else if ((function_x(x3) * function_x(x1)) < 0)
        {
            x2 = x3;
        }
        else
        {
            x1 = x3;
        }
        it++;
    }
    cout << "Did not converge within the maximum number of iterations." << endl;
}

int main()
{
    string equ;
    cout << "f(x)=";
    cin >> equ;
    parse(equ);
    cout << v[0] << " " << v[1] << " " << v[2] << endl;

    initial_value();

    bisection();

    return 0;
}
