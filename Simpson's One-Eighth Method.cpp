// Integrate y= log(x) in range of 4 to 5.2 in Simpson's One-Eighth Method

//Equation:  (3h/8)* [(Y0 + Yn-1) + 3(Y1 + Y2 + Y4 + Y5 + Y7 + Y8 + ...) + 2(Y3 + Y6 + Y9 + ...)]


#include<bits/stdc++.h>
using namespace std;

float a, b, h, n;       // a-> Lower bound,  b-> Upper bound,  h-> Interval,  n-> Number of steps

float y(float x){
    float z= log(x);   // put the function here and the rest will be the same.
    return z;
}

float Simpsons_One_Eighth(){

    float sum = y(a)+y(b);                              // Y0 + Y6

    for (int i = 1; i < n-1; i++){
        if(i%3!=0) sum += (3*y(a+i*h));             // 3(Y1 + Y2 + Y4 + Y5)
        else sum += (2*y(a+i*h));                    // 2(Y3)
    }

    return ((3*h)/8)*sum;
}

int main(){

    ifstream inp("input.txt");
    inp>>a>>b;
    h= 0.1;
    n = ((b-a)*10)+1;

    printf("Value of integral is:  %6.8f\n", Simpsons_One_Eighth());
    return 0;
}
