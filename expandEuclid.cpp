#include<bits/stdc++.h>
using namespace std;

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

// ham thuat toan Euclid mo rong
int expEuclid(int r0, int r1){
    if(gcd(r0, r1) != 1) return -1;
    
    int q[100], s[100], t[100];
    int r2 = -1, i=0;
    int m0 = r0;

    while(r2 != 0){
        q[i+1] = r0/r1;
        r2 = r0 % r1;

        // xet buoc i
        switch(i){
            case 0:
                s[i]=1; 
                t[i]=0;
                break;
            case 1:
                s[i]=0;
                t[i]=1;
                break;
            default:
                s[i] = s[i-2] - s[i-1] * q[i-1];
                t[i] = t[i-2] - t[i-1] * q[i-1];
                break;
        }
        r0 = r1;
        r1 = r2;
        i++;
    }
    s[i] = s[i-2] - s[i-1] * q[i-1];
    t[i] = t[i-2] - t[i-1] * q[i-1];

    if(t[i] > 0){
        return t[i];
    }else{
        return t[i] + m0;
    }
}

int main(){
    // tim gia tri r1^-1 theo mod r0
    int r0 = 101, r1 = 25;
    int value = expEuclid(r0, r1);
    cout << value;
}