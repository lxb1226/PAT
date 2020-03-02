#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Stu{
	int id;
	char name[9];
	int score;
}stu[100001];

bool cmp_1(Stu a, Stu b){
	return a.id < b.id;
}

bool cmp_2(Stu a, Stu b){
	int s = strcmp(a.name, b.name);
	if(s != 0) return s < 0;
	else return a.id < b.id;
}

bool cmp_3(Stu a, Stu b){
	if(a.score != b.score) return a.score <= b.score;
	else{
		return a.id < b.id;
	}
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i = 0; i < n; i++){
		scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].score);
	}
	switch(c){
		case 1:
			sort(stu, stu+n, cmp_1);
			break;
		case 2:
			sort(stu, stu+n, cmp_2);
			break;
		case 3:
			sort(stu, stu+n, cmp_3);
			break;
	}
	
	for(int i = 0; i < n; i++){
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	}
	
	return 0;
}
