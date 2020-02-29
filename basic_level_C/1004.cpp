#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;
const int MAXN = 10010;

struct Stu{
	string id;
	string name;
	int score;
}stu[MAXN];

bool cmp(Stu a, Stu b){
	return a.score > b.score;
}
int main(){
	int n;
	cin >> n;
//	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		cin >> stu[i].name >> stu[i].id >> stu[i].score;
//		scanf("%s %s %d", stu[i].name, stu[i].id, stu[i].score);
	}
	sort(stu, stu+n, cmp);
	cout << stu[0].name << " " << stu[0].id << "\n";
	cout << stu[n-1].name << " " << stu[n-1].id << "\n";
//	printf("%s %s\n", stu[0].name.c_str(), stu[0].id.c_str());
//	printf("%s %s\n", stu[n-1].name.c_str(), stu[n-1].id.c_str());
}
