//Newton and Raphson method
// 1x^2-5x^1+4
//1x^2-3x^1+2
#include<bits/stdc++.h>
using namespace std;

map<int , int> pw ;
int a,b,c;
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

double Func(double x){
    return a*x*x + b*x + c;
}

double DeriveFunc(double x){
    return a*2*x + b;
}

int main(){
    cout<<"Enter Equation:" ;
    string s;
    cin>>s;
    string_to_coefficient(s);
    stack<int>st;
    for(auto it : pw){
        cout<<it.second<<" ";
        st.push(it.second);
    }
    a = st.top();
    st.pop();
    b = st.top();
    st.pop();
    c = st.top();
    st.pop();
    cout<<endl;
    double xn,xn1,h;
    cout<<"Enter intial value : ";
    cin>>xn;   // For newton rephson initial value  = 0
   
    h = Func(xn)/DeriveFunc(xn);
    xn1 = xn-h;
    while (abs(xn1-xn)>=0.000001)
    {
        xn = xn1;
        h = Func(xn)/DeriveFunc(xn);
        xn1 = xn-h;   
    }
    cout<<"Root :"<<xn<<endl;
    
    return 0;
}