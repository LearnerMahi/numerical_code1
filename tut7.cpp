//String to coefficient

#include<bits/stdc++.h>
using namespace std;

//2x^2+3x^1+5

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

int main(){
        string s;
        //cout << "Enter equation : " ;
        cin >> s ;
        string_to_coefficient(s);
        for(auto it : pw) cout << it.second <<" ";
        cout << endl ;
    
    return 0;
}