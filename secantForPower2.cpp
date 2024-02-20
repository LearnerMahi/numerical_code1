//Secant Method

#include<bits/stdc++.h>
using namespace std;
//1x^2-4x^1-10

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

double findVlaueAt(double x){
    return a*x*x + b*x + c;
}
double findX3(double x1,double x2){
    return (x1*findVlaueAt(x2) - x2*findVlaueAt(x1))/(findVlaueAt(x2)-findVlaueAt(x1));
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
    double x1,x2,x3;
    cout<<"Enter x1 & x2 : ";
    cin>>x1>>x2;  //x1 = 4 && x2 = 2
    x3 = findX3(x1,x2);

    while(abs(x3-x2) >= 0.000001){
        x1 = x2;
        x2 = x3;
        x3 = findX3(x1,x2);
    }
    cout<<"Final Root : "<<x3<<endl;
    
    return 0;
}