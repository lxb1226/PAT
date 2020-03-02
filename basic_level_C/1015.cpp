#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN = 100001;
struct Stu{
	int id;
	int score_d;
	int score_c;
	int sum;
	int flag;
}stu[MAXN];

bool cmp(Stu a, Stu b){
	if(a.flag != b.flag) return a.flag < b.flag; // 类型小的在前 
	else if(a.sum != b.sum) return a.sum > b.sum;	// 类别相同时，总分大的在前面 
	else if(a.score_d != b.score_d) return a.score_d > b.score_d;	// 总分相同时,德分大的在前 
	else return a.id < b.id;	// 德分相同时，准考号小的在前 
}

int main(){
	int n, L, H;
	scanf("%d %d %d", &n, &L, &H);
	int m = n;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &stu[i].id, &stu[i].score_d, &stu[i].score_c);
		stu[i].sum = stu[i].score_d + stu[i].score_c;
		if(stu[i].score_d < L || stu[i].score_c < L){
			stu[i].flag = 5;
			m--;
		}
		else if(stu[i].score_d >= H && stu[i].score_c >= H) stu[i].flag = 1;
		else if(stu[i].score_d >= H && stu[i].score_c < H) stu[i].flag = 2;
		else if(stu[i].score_d >= stu[i].score_c) stu[i].flag = 3;
		else stu[i].flag = 4;
	}
	
	sort(stu, stu + n, cmp);
	printf("%d\n", m);
	for(int i = 0; i < m; i++){
		printf("%d %d %d\n", stu[i].id, stu[i].score_d, stu[i].score_c);
		
	}
	
	return 0;
	
	
} 
