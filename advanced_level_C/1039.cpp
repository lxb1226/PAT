#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k, index, m;
    string name;
    map<string, vector<int> > students;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d", &index, &m);
        for(int j = 0; j < m; j++){

            cin >> name;
            students[name].push_back(index);
        }
    }
    for(int i = 0; i < n; i++){
        cin >> name;
        vector<int> courses = students[name];
        sort(courses.begin(), courses.end(), less<int>());
        cout << name << " " << courses.size();
        for(int j = 0; j < courses.size(); j++)
            printf(" %d", courses[j]);
        printf("\n");
    }
    return 0;

}

