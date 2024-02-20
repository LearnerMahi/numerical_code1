//False position and RK

#include<bits/stdc++.h>
using namespace std;

// Equation format : 2x^2+3x^1+4
// Equation format : 4x^3+2x^2+3x^1+5
// Equation format : 1x^2-5x^1+4
// equation format : dy/dx = x+y

map<int , int> pw ;
void string_to_coefficient(string s){
    for(int i = 0 ; i < s.length() ; i++){
        int coeff = atol(s.substr(i).c_str());
        i+=log10(abs(coeff))+1;
        int power = 0 ;
        for(int j = i ; j < s.length() ; j++){
            if(s[j] == '^'){
                power = atol(s.substr(j+1).c_str());
                i=j+log10(power)+1 ;
                break;
            }
        }
        pw[power] += coeff;
    }
}

map<int , int> xp , yp ;
void string_to_coefficient2(string s){
    char last ;
    for(int i = 0 ; i < s.length() ; i++){
        int coeff = atol(s.substr(i).c_str());
        i+=log10(abs(coeff))+1;
        int power = 0 ;
        for(int j = i ; j < s.length() ; j++){
            if(s[j] == 'x') last = 'x' ;
            else if(s[j] == 'y') last = 'y' ;
            if(s[j] == '^'){
                power = atol(s.substr(j+1).c_str());
                i=j+log10(power)+1 ;
                break;
            }
        }
        if(last == 'x') xp[power] += coeff;
        else if(last == 'y') yp[power] += coeff ;
    }
}

float fxy(float x , float y){
    float ans = 0 ;
    for(auto it : xp) ans += it.second*pow(x*1.0,it.first);
    for(auto it : yp) ans += it.second*pow(y*1.0,it.first);
    return ans ;
}

float fx(float x){
    float ans = 0 ;
    for(auto it : pw) ans += it.second*pow(x*1.0,it.first);
    return ans ;
}

float dx(float x){
    float ans = 0 ;
    for(auto it : pw) ans += it.second*it.first*pow(x*1.0,it.first-1);
    return ans ;
}

float falsep(float x1 , float x2){
    return x1-((fx(x1)*(x2-x1)) / (fx(x2)-fx(x1))) ;
}


int main(){
    string s ;
    cout << "\n1. False Position Method \n2. R-K Method\nEnter : " ;
    int n ;
    cin >> n ;
    // False Position
    if(n == 1){
        cout << "Enter equation : " ;
        cin >> s ;
        string_to_coefficient(s);
        for(auto it : pw) cout << it.second << "x^" << it.first << "\t";
        cout << endl ;

        cout << "Enter range : " ;
        float x1 , x2 , x0 ;
        cin >> x1 >> x2 ;
        if(fx(x1)*fx(x2) >= 0){
            cout << "No Solution\n" ;
        }
        else{
            x0 = falsep(x1 , x2);
            while(abs(fx(x0)) < 0.00001){
                if(fx(x0)*fx(x2) < 0) x1 = x0 ;
                else x2 = x0 ;
                x0 = falsep(x1 , x2) ;
            }
            cout << "Ans : " << x0 << endl ;
        }
    }
    //R-K method
    else if(n==2){
        cout << "Enter equation : " ;
        cin >> s ;
        string_to_coefficient2(s);
        for(auto it : xp) cout << it.second << "x^" << it.first << "\t";
        for(auto it : yp) cout << it.second << "y^" << it.first << "\t";
        cout << endl ;

        float x , y , h , nn , x0 , y0 ;
        cout << "x0 = " ;
        cin >> x0 ;
        cout << "y0 = " ;
        cin >> y0 ;
        cout << "h = " ;
        cin >> h ;
        cout << "x = " ;
        cin >> x ;
        nn = (x-x0)/h ;
        y = y0 ;
        for(int i = 1 ; i <= nn ; i++){
            float k1 , k2 , k3 , k4 , k5 ;
            k1 = h*fxy(x0,y) ;
            k2 = h*fxy(x0 + 0.5*h, y + 0.5*k1);
            k3 = h*fxy(x0 + 0.5*h, y + 0.5*k2);
            k4 = h*fxy(x0 + h, y + k3);

            y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;
            x0 = x0 + h;
        }
        cout << "y("<<x<<") = " << y << endl ;
    }

}
