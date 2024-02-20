#include <bits/stdc++.h>
using namespace std;
float a[3][3];
float b[3];
int p=0;

void Coefficients(string s){
        string str ;
        int c=0, q=0, i;

        for( i=0; i<s.size(); i++){

            if(s[i]>='a' && s[i]<='z'){

                str.clear();
                for(int j=c; j<i; j++) str+=s[j];               // separated number in string form

                int n= 0;                                              // converted string to int
                stringstream num(str);
                num >> n;
                if(n==0)n=1;


                if(q==0)a[p][q]=n;                                  //storing co-efficients in a[][]
                else if(q>0){
                    if(s[c-1]=='+')a[p][q]=n;
                    else if(s[c-1]=='-')a[p][q]=((-1)*n);
                }
                q++;
                c=i+2;
            }
        }

        str.clear();                                                    //storing values in b[]
        for(int j=c; j<i; j++)str+=s[j];

        int n= 0;
        stringstream num(str);
        num >> n;
        b[p]=n;
        p++;
    }




float x, y=0, z=0;

void Iteration(){

    for(int i=1;i<20;i++){
        cout<<"Iteration Number: "<<i<<endl;

        x= (1/a[0][0]) *(b[0]-(a[0][1]*y)-(a[0][2]*z));                     // Equations
        y= (1/a[1][1]) *(b[1]-(a[1][0]*x)-(a[1][2]*z));
        z= (1/a[2][2]) *(b[2]-(a[2][0]*x)-(a[2][1]*z));

        cout<<"X: "<<x<<endl;
        cout<<"Y: "<<y<<endl;
        cout<<"Z: "<<z<<endl<<endl;

    }

}



int main() {

    string s1, s2, s3;

    ifstream inp("gaussinput.txt");
    inp>>s1>>s2>>s3;

    Coefficients(s1);
    Coefficients(s2);
    Coefficients(s3);

    for(int i=0; i<3;i++){
            for(int j=0;j<3;j++)cout<<a[i][j]<<"      ";
            cout<<b[i];
            cout<<endl;
    }

    Iteration();

}



