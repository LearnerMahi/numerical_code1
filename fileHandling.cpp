
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main(){

    fstream file1,file2;
    file1.open("input.txt",ios::in);
    file2.open("output.txt",ios::out|ios::app);


    if(file1.is_open()&&file2.is_open()){

    string x;
    while(getline(file1,x)){
        reverse(x.begin(),x.end());
        cout<<x<<endl;
    }

    }
    else{
        cout<<"Error openning file"<<endl;

    }
    file1.close();
    file2.close();

return 0;
}
