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

// function to generate key matrix from key string
void getKeyMatrix(string key, int keyMatrix[][3]){
    int k = 0;
    for(int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
    int x, i, j;

    for(int i = 0; i<3; i++){
        for(int j = 0; j<1; j++){
            cipherMatrix[i][j] = 0;

            for(int x=0; x<3; x++){
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

string HillCipher(string message, string key){
    // get key matrix from key string
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int messageVector[3][1];
    // generate vector for message
    for(int i=0; i<3; i++){
        messageVector[i][0] = (message[i]) % 65;
    }

    int cipherMatrix[3][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);
    string cipherText;
    for(int i=0; i<3; i++){
        cipherText += cipherMatrix[i][0] + 65;
    }

    return cipherText;
}

int main(){
    string plaintext = "ACT";
    string key = "GYBNQKURP";

    cout << HillCipher(plaintext, key);
}