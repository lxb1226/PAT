#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10001;
int main(){
	int n;
	int nums[maxn] = {0};
	int dp[maxn] = {0}, s[maxn];
	bool flag = false;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", nums+i);
		if(nums[i] >= 0) flag = true;
	}
	if(flag == false){
		printf("0 %d %d", nums[0], nums[n-1]);
		return 0;
	}
	dp[0] = nums[0];
	for(int i = 1; i <= n; i++){
		if(dp[i-1] + nums[i] > nums[i]){
			dp[i] = dp[i-1] + nums[i];
			s[i] = s[i-1];
		}else{
			dp[i] = nums[i];
			s[i] = i;
		}
		
	}
	int k = 0;
	for(int i = 1; i < n; i++){
		if(dp[i] > dp[k]){
			k = i;
		}
	}
	printf("%d %d %d\n", dp[k], nums[s[k]], nums[k]);
	return 0;	
} 
