#include<bits/stdc++.h> 
#define n 26    // gia su thuc hien ma hoa tren bo chu cai tieng anh n = 26
using namespace std;

int mod = n;

// thuat toan ucln
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

// thuat toan Euclid mo rong
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

// ham ma hoa
string mahoa(string banro, int a, int b){
    string plainMassage = "";
    for(int i = 0; i<banro.length(); i++){
        if(islower(banro[i])){
            plainMassage += (char) (((a * (banro[i] - 'a') + b) % 26) + 'a');
        }else if(banro[i] == ' '){
            plainMassage += ' ';
        }else{
            plainMassage += (char) (((a * (banro[i] - 'A') + b) % 26) + 'A');
        }
    }

    return plainMassage;
}

// ham giai ma
string giaima(string banma, int a, int b){
    string cipherMessage = "";
    int inv_a = expEuclid(mod, a);
    for(int i=0; i<banma.length(); i++){
        if(islower(banma[i])){
            cipherMessage += (char) (((inv_a * (banma[i] - 'a' - b + mod)) % 26) + 'a');
        }else if(banma[i] == ' '){
            cipherMessage += ' ';
        }else{
            cipherMessage += (char) (((inv_a * (banma[i] - 'A' - b + mod)) % 26) + 'A');
        }
    }

    return cipherMessage;
}


int main(){
    // khai bao khoa k=(a,b)
    int a, b;

    string banro;
    do{
        cout << "Nhap a hop le = "; cin >> a;
    }while(gcd(mod, a) != 1);
    cout << "Nhap b = "; cin >> b;
    cin.ignore();
    cout << "Nhap xau ky tu = ";
    fflush(stdin);
    getline(cin, banro);
    
    string banmaTxt = mahoa(banro, a, b);
    cout << "Ban ma: " << banmaTxt << endl;
    cout << "Ban ro: " << giaima(banmaTxt, a, b);
}