#include <bits/stdc++.h>
using namespace std;

double fun(double x, double y)
{
    double f = x+y;
    return f;
}

// 0 1 0.05 0.05

int main()
{
    int n,t=1;
    double h,test[100];
    double x0,y0,x1,x2,y1,y2,x,y,f0,f1,f2;
    cin >> x0 >> y0 >> h >> x ;

    x1 = x0 + h;
    f0 = fun(x0,y0);
    y1 = y0 + h*f0;
    test[0] = y1;

    f1 = fun(x1,y1);

    y1 = y0 + h*(f0+f1)/2;
    test[1] = y1;

    while (test[t]!=test[t-1])
    {
        t++;
        f1 = fun(x1,y1);
        y1 = y0 + h*(f0+f1)/2;
        test[t] = y1;
    }

    cout << "y1 = " << y1 << endl;

    t = 1;
    y2 = y0 + 2*h*fun(x1,y1);
    x2 = x1 + h;
    test[0] = y2;

    f2 = fun(x2,y2);

    y2 = y1 + h*(f1+f2)/2;
    test[1] = y1;

    while (test[t]!=test[t-1])
    {
        t++;
        f2 = fun(x2,y2);
        y2 = y1 + h*(f1+f2)/2;
        test[t] = y2;
    }

    cout << "y2 = " << y2 << endl;


}
