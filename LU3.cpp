//LU factorization
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

/*

2x+3y+z=9
1x+2y+3z=6
3x+y+2z=8

*/

double A[4][4] , L[4][4] , U[4][4] , X[4] , Y[4];

void string_to_coefficient(string s , int i){
    int num = 0 ;
    int sign = 1 ;
    int idx = 0 ;
    if(s[0] == '-'){
        sign = -1 ;
        idx = 1 ;
    }
    for(int j = idx ; j < s.length() ; j++){
        if(s[j] <= '9' && s[j] >= '0'){
            num = num*10 + (s[j] - '0') ;
        }
        else if(s[j] == 'x'){
            if(num == 0) num = 1 ;
            A[i][1] = sign*num ;
            num = 0 ; sign = 1 ;
        }
        else if(s[j] == 'y'){
            if(num == 0) num = 1 ;
            A[i][2] = sign*num ;
            num = 0 ; sign = 1 ;
        }
        else if(s[j] == 'z'){
            if(num == 0) num = 1 ;
            A[i][3] = sign*num ;
            num = 0 ; sign = 1 ;
        }
        else if(s[j] == 'w'){
            if(num == 0) num = 1 ;
            A[i][4] = sign*num ;
            num = 0 ; sign = 1 ;
        }
        if(s[j] == '-') sign = -1 ;
        else if(s[j] == '+') sign = 1 ;
    }
    X[i] = sign*num ;
}


int main() {
string s1 , s2 , s3 , s4;
    cin >> s1 >> s2 >> s3 ;
    string_to_coefficient(s1 , 1) ;
    string_to_coefficient(s2 , 2) ;
    string_to_coefficient(s3 , 3) ;


    cout << "\nCoefficient : \n" ;
    for(int i = 1 ; i <= 3 ; i++){
        for(int j = 1 ; j <= 3 ; j++){
            cout << A[i][j] << " " ;
        }
        cout << "\t" << X[i] << endl ;
    }

    int n = 3 ;
    for (int i = 1; i <= n; i++){
        for (int k = i; k <= n; k++){
            float sum = 0;
            for (int j = 1; j < i; j++) sum += (L[i][j] * U[j][k]);

            U[i][k] = A[i][k] - sum;
        }

        for (int k = i; k <= n; k++){
            if (i == k) L[i][i] = 1;
            else{
                float sum = 0;
                for (int j = 0; j < i; j++) sum += (L[k][j] * U[j][i]);

                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    cout << "\nLower Matrix : \n" ;
    for(int i = 1 ; i <= 3 ; i++){
        for(int j = 1 ; j <= 3 ; j++){
            cout << setw(10) << L[i][j] << " ";
        }
        cout << endl ;
    }
    cout << "\nUpper Matrix : \n" ;

    for(int i = 1 ; i <= 3 ; i++){
        for(int j = 1 ; j <= 3 ; j++){
            cout << setw(10) <<U[i][j] << " ";
        }
        cout << endl ;
    }

    for(int i = 1 ; i <= n ; i++){
        float sum = 0 ;
        for(int j = 1 ; j < i ; j++) sum += L[i][j]*Y[j] ;
        Y[i] = (X[i] - sum)/L[i][i];
    }

    cout << "\nY Matrix : \n" ;
    for(int i = 1 ; i <= 3 ; i++){
        cout << Y[i] << endl ;
    }

    for(int i = n ; i >= 1 ; i--){
        float sum = 0 ;
        for(int j = n ; j > i ; j--) sum += U[i][j]*X[j] ;
        X[i] = (Y[i] - sum)/U[i][i];
    }

    cout << "\nSolutions : \n" ;
    for(int i = 1 ; i <= n ; i++){
        cout << "x[" << i << "] = " << X[i] << endl ;
    }
}

