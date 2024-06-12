#include<bits/stdc++.h>
using namespace std;

// ham thuat toan tim ucln
int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;

    while(b!=0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }

    return a;
}

int main(){
    int a = 6;
    int b = 4;
    cout << gcd(a, b);
}