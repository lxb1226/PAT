#include<cstdio>

const int MAXN = 1001;
struct{
	long long id;
	int pre;
	int actual;
}stu[MAXN];

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld %d %d",&stu[i].id, &stu[i].pre,&stu[i].actual);
	}
	int m, pre;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &pre);
		for(int j = 0; j < N; j++){
			if(stu[j].pre == pre) printf("%lld %d\n", stu[j].id, stu[j].actual);
		}
	}
	
	return 0;
} 
