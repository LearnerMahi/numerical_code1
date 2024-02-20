//false position
#include<bits/stdc++.h>

using namespace std;



double err;
double f(double x)
{
    return  3*x-cos(x)-1;
}
void FB(double a, double  b,double err)
{
    if(f(a) * f(b)>=0)
    {
        cout<<"No Solution!"<<endl;
        return ;
    }

    double x0;
    double x1=a;
    double x2=b;
    int i=0;
    while(abs(f(x1))>err)
    {
        i++;
        x0=x1-f(x1)*((x2-x1)/(f(x2)-f(x1)));
        if(f(x0)*f(x1)<0)
        {
            x2=x0;
        }
        else
        {
            x1=x0;
        }

    }

    cout<<"Root:"<<x0<<"\n";

}
int main()
{
    double a,b;

    cout<<"Enter range"<<endl;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;

    cout<<"Enter Error Margin: ";
    cin >>err;
    FB(a,b,err);
    return 0;
}