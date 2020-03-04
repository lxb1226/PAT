#include<cstdio>
#include<algorithm>

using namespace std;

struct mooncake{
	double price;
	double sell;
	double store;
}cakes[1010];

bool cmp(mooncake a, mooncake b){
	return a.price > b.price;
}
int main(void){
	int n;
	double D, ans = 0;
	scanf("%d %lf", &n,&D);
	for(int i = 0; i < n; i++)
		scanf("%lf", &cakes[i].store);
	for(int i = 0; i < n; i++){
		scanf("%lf", &cakes[i].sell);
		cakes[i].price = cakes[i].sell / cakes[i].store;
	}
	sort(cakes,cakes+n,cmp);
	for(int i = 0; i<n; i++){
		if(cakes[i].store < D){
			ans += cakes[i].sell;
			D -= cakes[i].store;
		}else{
			ans += cakes[i].price * D;
			break;
		}
	}
	printf("%.2f\n", ans);
	
	
	
	return 0;
}
