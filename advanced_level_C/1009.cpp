#include<cstdio>

struct Poly{
	int exp;
	double cof;
}Poly[1001];

double ans[2001];
int main(){
	int n, m, number = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d %lf", &Poly[i].exp, &Poly[i].cof);
	}
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		int exp;
		double cof;
		scanf("%d %lf", &exp, &cof);
		for(int j = 0; j < n; j++){
			ans[exp + Poly[j].exp] += (cof*Poly[j].cof);
		}
	}
	for(int i = 0; i <= 2000; i++){
		if(ans[i] != 0.0) number++;
	}
	printf("%d", number);
	
	for(int i = 2000; i >= 0; i--){
		if(ans[i] != 0.0) printf(" %d %.1f", i, ans[i]);
	}
	
	return 0;
	
	
}