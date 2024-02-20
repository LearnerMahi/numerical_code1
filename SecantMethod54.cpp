 #include <bits/stdc++.h>
using namespace std;

double func(double x)
{
    return (x * x - 4 * x - 10);
}

int main()
{
    double x1 = 6.00, x2 = 3.0;
    double x3 = (func(x2) * x1 - func(x1) * x2) / (func(x2) - func(x1));
    double dx = x3 - x2;
    int c = 1;
    double xh = x3, xl = x2;
    double y;
    while (dx>= 0.00000001)
    {
        y=xh;
        xh = (func(xh) * xl - func(xl) * xh) / (func(xh) - func(xl));

        dx = xh - y;
        c++;
        xl =y;

    }

    cout << "Approximate root: " << xh << endl;
    cout << "Number of iterations: " << c << endl;

    return 0;
}
