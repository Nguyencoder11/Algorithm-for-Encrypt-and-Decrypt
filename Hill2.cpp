#include<bits/stdc++.h>
using namespace std;

// tim ucln cua 2 so
int gcd(int a, int b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

// tim nghich dao modulo 2 so bang Euclid mo rong
int inv_mod(int r0, int r1){
    if(gcd(r1, r0) != 1) return -1;

    int m0 = r0;
    int q[100], s[100], t[100];
    int r2 = -1, i = 0;

    while(r2 != 0){
        q[i+1] = r0 / r1;
        r2 = r0 % r1;

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
    s[i] = s[i-2] - q[i-1] * s[i-1];
    t[i] = t[i-2] - q[i-1] * t[i-1];

    if(t[i] > 0) return t[i];
    else return t[i] + m0;
}

void decryptMatrix(int keyMatrix[][2]){
    // tinh detk
    int det = abs(keyMatrix[1][1] * keyMatrix[0][0] - keyMatrix[1][0] * keyMatrix[0][1]);

    // tinh detk^-1
    int inv_k = inv_mod(26, det);

    if(inv_k == -1) {
        cout << "Khong ton tai nghich dao modulo cua k^-1 mod 26";
    }else{
        // tinh ma tran phu hop
        int tempMatrix[2][2];
        tempMatrix[0][0] = keyMatrix[1][1] % 26;
        tempMatrix[0][1] = (-keyMatrix[0][1]+26) % 26;
        tempMatrix[1][0] = (-keyMatrix[1][0]+26) % 26;
        tempMatrix[1][1] = keyMatrix[0][0] % 26;

        int decryptMatrix[2][2];
        for(int i=0; i<2; i++){
            for(int j = 0; j<2; j++){
                decryptMatrix[i][j] = (inv_k * tempMatrix[i][j]) % 26;
            }
        }

        for(int i=0; i<2; i++){
            for(int j = 0; j<2; j++){
                cout << decryptMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int keyMatrix[2][2];
    cout << "Nhap khoa k a, b, c, d theo thu tu: ";
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cin >> keyMatrix[i][j];
        }
    }

    cout << "Ma tran khoa la: " << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << keyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Ma tran khoa giai ma: " << endl;
    decryptMatrix(keyMatrix);
}