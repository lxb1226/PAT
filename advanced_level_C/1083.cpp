#include<cstdio>
#include<algorithm>
using namespace std;

struct Stu{
	char id[11];
	char name[11];
	int grade;
}stu[10010];

bool cmp(Stu a, Stu b){
	return a.grade > b.grade;
}

int main(){
	int n, grade1, grade2;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %s %d", &stu[i].name,&stu[i].id, &stu[i].grade );
	}
	scanf("%d %d", &grade1, &grade2);
	sort(stu,  stu + n, cmp);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(stu[i].grade >= grade1 && stu[i].grade <= grade2){
			printf("%s %s\n", stu[i].name, stu[i].id);
			cnt++;
		}		
	}
	if(cnt == 0) printf("NONE");
	return 0;
	
}
