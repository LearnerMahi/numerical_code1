#include <bits/stdc++.h>
#define f(x) x*x - 5
#define g(x) (x + 5/x) / 2
using namespace std;
int main() {
	 float x0, x1;
	 cin>>x0; // initial guess 1
	 for (int i = 0; i < 100; ++i) {
		  x1 = g(x0);
		  x0 = x1;
	 }
	 cout<<"Root is "<< x1 << endl;
	 return(0);
}
