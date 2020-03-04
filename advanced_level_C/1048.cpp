#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int n, money;
	int coins[100010] = {0};
	scanf("%d %d", &n, &money);
	for(int i = 0; i < n; i++){
		scanf("%d", coins+i);
	}
	sort(coins, coins + n);
	int left = 0, right = n - 1;
	while(left < right){
		if(coins[left] + coins[right] > money) right--;
		else if(coins[left] + coins[right] < money) left++;
		else break; 
	}
	if(left < right) printf("%d %d", coins[left], coins[right]);
	else printf("No Solution");
}
