#include<cstdio>

using namespace std;
const int MAXN = 110;

void Reverse(int left, int right, int nums[]){
	int temp = 0;
	for(int i = left; i <= (left + right)/2; i++){
		temp = nums[i];
		nums[i] = nums[right + left - i];
		nums[right + left - i] = temp;
	}
}

int main(){
	int n, m;
	int nums[MAXN] = {0};
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", nums+i);
	}
	m = m %n;
	Reverse(0, n-m-1,nums);
	Reverse(n-m, n-1,nums);
	Reverse(0, n-1,nums);
	for(int i = 0; i < n; i++){
		printf("%d", nums[i]);
		if(i != n - 1) printf(" ");
		
	}
	
	
	return 0;
}
