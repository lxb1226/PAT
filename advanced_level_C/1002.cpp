#include<cstdio>
using namespace std;

const int MAXN = 1010;
double nums[MAXN] = {0};

int main(){
	int K, n, count = 0;
	double coeff;
	for(int j = 0; j < 2; j++){
		scanf("%d", &K);
		for(int i = 0; i < K; i++){
			scanf("%d %lf", &n, &coeff);
			nums[n] += coeff;
		}
	}
	for(int i = 0; i < MAXN; i++){
		if(nums[i] != 0) count++;
	}
	printf("%d", count);
	for(int i = MAXN - 1; i >= 0; i--){
		if(nums[i] != 0) printf(" %d %.1f", i, nums[i]);
		
	}
	
	
}
