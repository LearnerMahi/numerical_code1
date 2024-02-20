
#include <bits/stdc++.h>

using namespace std;
#define inf 1000.0
double xx(vector<int> v[], double y, double z)
{

    return (v[0][3] - v[0][1] * y - v[0][2] * z) / v[0][0];
}
double yy(vector<int> v[], double x, double z)
{

    return (v[1][3] - v[1][0] * x - v[1][2] * z) / v[1][1];
}
double zz(vector<int> v[], double x, double y)
{

    return (v[2][3] - v[2][1] * y - v[2][0] * x) / v[2][2];
}
int main()
{
    vector<int> v[3];
    string str;
    for (int i = 0; i < 3; i++)
    {
  getline(cin,str);//don't use cin>>

    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    string temp;
    int found;
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
    v[i].push_back(found);

    }
    cout<<endl;
    }




    double x, y, z, dx = inf, dy = inf, dz = inf;

    y = 0, z = 0;
    x = xx(v, y, z);
    y = yy(v, x, z);
    z = zz(v, x, y);

    int step = 1;
    while (dx >= .0001 || dy >= .0001 || dz >= .0001)
    {
        dx = x - xx(v, y, z);
        x = xx(v, y, z);
        dy = y - yy(v, x, z);
        y = yy(v, x, z);
        dz = z - zz(v, x, y);
        z = zz(v, x, y);
        step++;
    }
    cout << x << " " << y << ' ' << z << endl;
    cout << "s: " << step << endl;
    return 0;
}
/*
27x +6y -1z= 85 //digiter pore touch kore letter likleo ok
6 x + 15 y + 2 z= 72//digit separate kore dileo ok
1x +1y +54z = 110//digiter age +- aigula touch kore lagano o ok
*/
// 1 x + 1 y + 54 z =110 illegal  cz 110 ar age touch kore = likso
// 1 x+1 y + 54 z = 110 illegal  cz 1 ar age touch kore x+ likso
