// x^3-x^2+x-10

#include <bits/stdc++.h>
using namespace std;

vector<double> v;

int stepsec, stepfp;

void parse(string s)
{
    int i = 0;
    int sign = 1;
    double num = 0;
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
        else if (s[i] == 'x')
        {
            if (num == 0)
                num = 1;
            if (i + 1 < s.length() && s[i + 1] == '^')
            {
                int j = i + 2;
                int exp = 0;
                while (j < s.length() && s[j] >= '0' && s[j] <= '9')
                {
                    exp = exp * 10 + (s[j] - '0');
                    j++;
                }
                v.push_back(sign * num * pow(1.0, exp));
                i = j - 1;
            }
            else
            {
                v.push_back(sign * num);
            }
            num = 0;
            sign = 1;
        }
        else if (s[i] == '-')
        {
            sign = -1;
        }
    }
    if (num != 0)
    {
        v.push_back(sign * num);
    }
}

double function_x(double x)
{
    return v[0] * x * x * x + v[1] * x * x + v[2] * x + v[3];
}

double derivative(double x)
{
    return 3 * v[0] * x * x + 2 * v[1] * x + v[2];
}

void secant()
{
    double x1, x2, x3;
    cout << "Enter initial Guess: ";
    cin >> x1 >> x2;
    int it = 0;
    while (it < 50)
    {
        x3 = ((function_x(x2) * x1) - (function_x(x1) * x2)) / (function_x(x2) - function_x(x1));
        cout << "Iteration: " << it << " Root = " << x3 << endl;

        if (fabs(x1 - x2) < 0.00001)
        {
            cout << "Converged to root after " << it << " iterations." << endl;
            return;
        }
        x1 = x2;
        x2 = x3;
        it++;
    }
    cout << "Did not converge within the maximum number of iterations." << endl;
    stepsec = it;
}

void false_position()
{
    double x1, x2, x3;
    cout << "Enter initial Guess: ";
    cin >> x1 >> x2;

    int it = 0;
    while (it < 50)
    {
        // x3 = ((function_x(x2) * x1) - (function_x(x1) * x2)) / (function_x(x2) - function_x(x1));
        x3 = x1 - ((function_x(x1) * (x2 - x1)) / (function_x(x2) - function_x(x1)));
        cout << "Iteration: " << it << " Root = " << x3 << endl;

        if (fabs(function_x(x3)) < 0.00001)
        {
            cout << "Converged to root after " << it << " iterations." << endl;
            return;
        }

        if ((function_x(x3) * function_x(x1)) < 0)
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

    stepfp = it;
}

void compare()
{
    secant();
    false_position();
    if (stepsec > stepfp)
        cout << "Flase Position Better" << endl;
    else
        cout << "Secant Better" << endl;
}

int main()
{
    char repeat;

    do
    {
        string equ;
        cout << "Enter your string: ";
        cin >> equ;
        parse(equ);
        for (double coeff : v)
        {
            cout << coeff << " ";
        }
        cout << endl;
        int ch;
        cout << "1. Secant\n2. False Position\nEnter choice:";
        cin >> ch;
        if (ch == 1)
        {
            secant();
        }
        else if (ch == 2)
        {
            false_position();
        }

        compare();

        cout << "Do you want to repeat?";
        cin >> repeat;

        // compare();

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
