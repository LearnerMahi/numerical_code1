#include<bits/stdc++.h>
using namespace std;

void printMat(float a[][4], int ro, int col)
{
    for(int i = 1; i <= ro; i++){
        for(int j = 1; j <= col; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    //freopen("factoinput.txt", "r", stdin);
    ifstream inp("factoinput.txt");
    float a[4][4], b[4][4];
    char s[100];
    //string s;
    for(int i = 0; i < 3; i++){
        int j = 1;
        //cin >> s;
        inp>>s;
        float x, y, z, c;
        sscanf(s, "%fx+%fy+%fz=%f", &x, &y, &z, &c);
        a[i + 1][j++] = x;
        a[i + 1][j++] = y;
        a[i + 1][j++] = z;
        b[i + 1][1] = c;
    } inp.close(); //dorkar nai
    float low[4][4], u[4][4];
    printMat(a, 3, 3);

    for(int i = 1; i <= 3; i++) low[i][i] = 1;

    low[1][2] = low[1][3] = low[2][3] = u[2][1] = u[3][1] = u[3][2] = 0;

//    cout << endl << "    Coefficient matrix" << endl << endl;
//    print(a);


    low[2][1] = a[2][1]/a[1][1];
    low[3][1] = a[3][1]/a[1][1];
    low[3][2] = ( a[1][1]*a[3][2] - a[1][2]*a[3][1] ) / ( a[1][1]*a[2][2] - a[1][2]*a[2][1] );

    cout << endl << "    Lower triangular matrix  " << endl << endl;
    printMat(low, 3, 3);

    u[1][1] = a[1][1]; u[1][2] = a[1][2]; u[1][3] = a[1][3];

    u[2][2] = a[2][2] - ( (a[1][2]*a[2][1]) / a[1][1] );
    u[2][3] = a[2][3] - ( (a[2][1]*a[1][3]) / a[1][1] );
    u[3][3] = a[3][3] - ( low[3][1]*u[1][3] ) - (low[3][2]*u[2][3]);


    cout << endl << "    Higher triangular matrix  " << endl << endl;
    printMat(u, 3, 3);

    double y1 = b[1][1] / low[1][1];
    double y2 = (b[2][1] - low[2][1] * y1) / low[2][2];
    double y3 = (b[3][1] - low[3][1] * y1 - low[3][2] * y2) / low[3][3];
    // cout << y1 << ' ' << y2 << ' ' << y3 << '\n';

    double z = y3 / u[3][3];
    double y = (y2 - u[2][3] * z) / u[2][2];
    double x = (y1 - u[1][2] * y - u[1][3] * z ) / u[1][1];
    cout << x << ' ' << y << ' ' << z << '\n';
}
