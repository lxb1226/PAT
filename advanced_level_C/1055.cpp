#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
struct People{
	char name[10];
	int age;
	int worth;
}P[100010];

bool cmp(People a, People b){
	if(a.worth != b.worth) return a.worth > b.worth;
	else if(a.age != b.age) return a.age <= b.age;
	else return strcmp(a.name,b.name) < 0;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%s %d %d", &P[i].name, &P[i].age, &P[i].worth);
	}
	sort(P, P + n, cmp);
	int m, Amin, Amax;
	
	for(int j = 1; j <= k; j++){
		scanf("%d%d%d", &m, &Amin, &Amax);
		printf("Case #%d:\n", j);
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(P[i].age >= Amin && P[i].age <= Amax){
				printf("%s %d %d\n", P[i].name, P[i].age, P[i].worth);
				cnt++;
				if(cnt == m) break;
			} 
		}
		if(cnt == 0)
			printf("None\n");
	}
	return 0;
}
