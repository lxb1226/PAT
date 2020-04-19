#include<cstdio>
#include<iostream>
#include<map>
#include<cctype>

using namespace std;

int main(){
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for(int i = 0; i < s.length(); i++){
        if(isalnum(s[i])){
            s[i] = tolower(s[i]);
            t += s[i];
        }
        if(!isalnum(s[i]) || i == s.length() - 1){
            if(t.length() != 0) m[t]++;
            t = "";
        }
    }
    int maxn = 0;
    cout << m.size();
    for(map<string,int>::iterator it = m.begin(); it != m.begin(); it++){
        //cout << it->first << " " << it->second << "\n";
        if(it->second > maxn){
            t = it->first;
            maxn = it->second;
        }
    }
    cout << t << " " << maxn;

    return 0;
}
