#include<cstdio>

using namespace std;

int judge(int a, int b, int c, int  d){
	int sum = a + c;
	if(b == sum && d != sum) return 1;
	if(b != sum && d == sum) return -1;
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	int a, b, c, d;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d",&a,&b, &c,&d);
		if(judge(a,b,c,d) == 1) cnt2++;
		if(judge(a,b,c,d) == -1) cnt1++;
	}
	printf("%d %d",cnt1, cnt2);
	return 0;
	
}
