#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        int flag = 0;
        int a = 0, b = 0, z = 0;
        for(int i = 0; i < s.size()/2; i++){
            a = a * 10 + s[i] - '0';
            z = z * 10 + s[i] - '0';
        }

        for(int i = s.size()/2; i < s.size(); i++){
            b = b * 10 + s[i] - '0';
            z = z * 10 + s[i] - '0';
        }
        if(b == 0)
            printf("No\n");
        else if(z % (a * b) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
