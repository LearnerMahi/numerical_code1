// Integrate y= log(x) in range of 4 to 5.2 in Simpson's One-third Method

//Equation: (h/3)* [(Y0 + Yn-1) + 4(Y1 + Y3 + Y5 + Y7 +...) + 2(Y2 + Y4 + Y6 + Y8 +...)]


#include<bits/stdc++.h>
using namespace std;

float a, b, h, n;       // a-> Lower bound,  b-> Upper bound,  h-> Interval,  n-> Number of steps

float y(float x){
    float z= log(x);   // put the function here and the rest will be same.
    return z;
}

float Simpsons_One_third(){

    float sum = y(a)+y(b);                          //Y0 + Y6

    for (int i = 1; i < n-1; i+=2)
        sum += (4*y(a+i*h));                       //4(Y1 + Y3 + Y5)

    for (int i = 2; i < n-1; i+=2)
        sum += (2*y(a+i*h));                     //2(Y2 + Y4)

    return (h/3)*sum;
}

int main(){

    ifstream inp("input.txt");
    inp>>a>>b;
    h= 0.1;
    n = ((b-a)*10)+1;

    printf("Value of integral is:  %6.8f\n", Simpsons_One_third());
    return 0;
}
