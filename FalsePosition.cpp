//False position method

#include<bits/stdc++.h>
using namespace std;
//1x^2-1x^1-2

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

double f(double x){
   // cout<<b<<" "<<c<<endl;
    return a*x*x + b*x + c;
}


double fun(double x1,double x2){
    return ((x1*f(x2)-x2*f(x1))/(f(x2)-f(x1)));
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

    double x1 = 1,x2=3;
    int cnt=0;
    double x0=0;
    while(cnt<10){
        cnt++;

        x0 = fun(x1,x2);
        cout<<cnt<<"The value of x0 : "<<x0<<endl;
        double temp = f(x0)*f(x1);

        if(temp<0.0){
            x2 = x0;
        }
        else{
            x1 = x0;

        }
    }
    cout<<endl;
    cout<<"Final value of x0 : "<<x0<<endl;
    return 0;
}
