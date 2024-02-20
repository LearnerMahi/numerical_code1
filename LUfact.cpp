#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v[3];
    string str;
    for (int i = 0; i < 3; i++)
    {
        getline(cin, str);

        stringstream ss;
        ss << str;

        string temp;

        int found;
        while (!ss.eof()) {
            ss >> temp;

            if (stringstream(temp) >> found)
                v[i].push_back(found);
        }
    }

    float u11, u12, u13, u22, u23, u33, l21, l31, l32;
    u11 = v[0][0];
    u12 = v[0][1];
    u13 = v[0][2];
    l21 = v[1][0] / v[0][0];
    u22 = v[1][1] - (v[1][0] / v[0][0]) * v[0][1];
    u23 = v[1][2] - u13 * l21;
    l31 = v[2][0] / v[0][0];
    l32 = (v[2][1] - l31 * u12)/u22;
    u33 = v[2][2] - l31 * u13 - l32 * u23;

    cout << "  L matrix" << endl;

    cout << 1 << " " << 0 << " " << 0 << endl;
    cout << l21 << " " << 1 << " " << 0 << endl;
    cout << l31 << " " << l32 << " " << 1 << endl;

    cout << " U Matrix " << endl;

    cout << u11 << " " << u12 << " " << u13 << endl;
    cout << 0 << " " << u22 << " " << u23 << endl;
    cout << 0 << " " << 0 << " " << u33 << endl;

    float y1=v[0][3];
    float y2=v[1][3]-l21*y1;
    float y3=v[2][3]-l31*y1-l32*y2;
    float z= y3/u33;
    float y=(y2-u23*z)/u22;
    float x=(y1-u13*z-u12*y)/u11;

    cout<<"Now the value of x y x :"<<endl;

    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"z = "<<z<<endl;




    return 0;
}
