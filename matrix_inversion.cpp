 #include<bits/stdc++.h>
using namespace std;
#define SIZE 10

int main()
{
    float a[SIZE][SIZE], ratio;
    int i,j,k,n;


    cout<< setprecision(3)<< fixed;


    cout<<"Enter order of matrix: ";
    cin>>n;


    cout<<"Enter coefficients of Matrix: " << endl;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    }


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j)
            {
                a[i][j+n] = 1;
            }
            else
            {
                a[i][j+n] = 0;
            }
        }
    }


    for(i=1; i<=n; i++)
    {
        if(a[i][i] == 0.0)
        {
            cout<<"Mathematical Error!";
            exit(0);
        }
        for(j=1; j<=n; j++)
        {
            if(i!=j)
            {
                ratio = a[j][i]/a[i][i];
                for(k=1; k<=2*n; k++)
                {
                    a[j][k] = a[j][k] - ratio*a[i][k];
                }
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=n+1; j<=2*n; j++)
        {
            a[i][j] = a[i][j]/a[i][i];
        }
    }

    cout<< endl<<"Inverse Matrix is:"<< endl;
    for(i=1; i<=n; i++)
    {
        for(j=n+1; j<=2*n; j++)
        {
            cout<< a[i][j]<<"\t";
        }
        cout<< endl;
    }

}
