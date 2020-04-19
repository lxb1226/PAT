#include<iostream>
#include<string>

using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int stoi(string s, int k){
    int res = 0;
    for(int i = 0; i < k; i++)
        res = res * 10 + s[i] - '0';
    return res;
}

int main(){
    int l, k;
    string s;
    cin >> l >> k >> s;
    for(int i = 0; i <= l - k; i++){
        string t = s.substr(i, k);
        int num = stoi(t, k);
        if(isPrime(num)){
            cout << t;
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}
