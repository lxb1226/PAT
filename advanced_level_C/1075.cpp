#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int n, k, m;
int full[6];
struct Stu{
	int id;
	int scores[6];
	int totalscore;
	int solve;
	bool flag;
}stu[10010];

bool cmp(Stu a, Stu b){
	if(a.totalscore != b.totalscore) return a.totalscore > b.totalscore;
	else if(a.solve != b.solve) return a.solve > b.solve;
	else return a.id < b.id;
}

void init(){
	for(int i = 1; i <= n; i++){
		stu[i].id = i;
		stu[i].totalscore = 0;
		stu[i].solve = 0;
		stu[i].flag = false;
		memset(stu[i].scores, -1, sizeof(stu[i].scores));
	}
}

int main(){

	scanf("%d%d%d", &n, &k, &m);
	init();
	for(int i = 1; i <= k; i++){
		scanf("%d", full + i);
	}
	int u_id, p_id, score_obtained;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &u_id, &p_id, &score_obtained);
		if(score_obtained != -1) stu[u_id].flag = true;
		if(score_obtained == -1 && stu[u_id].scores[p_id] == -1) stu[u_id].scores[p_id] = 0;
		if(score_obtained == full[p_id] && stu[u_id].scores[p_id] < full[p_id]) stu[u_id].solve++;
		if(score_obtained > stu[u_id].scores[p_id]) stu[u_id].scores[p_id] = score_obtained;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(stu[i].scores[j] != -1){
				stu[i].totalscore += stu[i].scores[j];
			}
		}
	}
	sort(stu+1, stu + n + 1, cmp);
	int r = 1;
	for(int i = 1; i <= n && stu[i].flag == true; i++){
		if(i > 1 && stu[i].totalscore != stu[i-1].totalscore)
			r = i;
		printf("%d %05d %d", r, stu[i].id, stu[i].totalscore);
		for(int j = 1; j <= k; j++){
			if(stu[i].scores[j] == -1)	printf(" -");
			else	printf(" %d", stu[i].scores[j]);
		}
		printf("\n");
	}
	return 0;
	
	
}
