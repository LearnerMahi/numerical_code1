//Bisection Method for

#include<bits/stdc++.h>
using namespace std;
//1x^2-5x^1-4

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

double f(double x)
{
	return a*x*x + b*x + c;
}

int main()
{
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
	// Initial values assumed
	double x1 =-6, x2 = 6;

    double x0 ;
    int cnt=0;
    // cout<<"hi"<<endl;
    while(cnt<20){
        cnt++;
        //cout<<"hello"<<endl;
        x0 = (x1+x2)/2;
        if(f(x0)*f(x1) < 0){
            x2 = x0;
        }
        else{
            x1 = x0;
        }
    }
    cout<<x0<<endl;
	return 0;
}
