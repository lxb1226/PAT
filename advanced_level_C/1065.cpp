#include<cstdio>


int main(){
	long long A, B, C,res;
	int T;
	bool flag;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		scanf("%lld %lld %lld", &A, &B, &C);
		res = A + B;
		if(A>0 && B>0 && res<0) flag = true;
		else if(A<0 && B<0 && res>=0) flag = false;
		else if(res > C) flag = true;
		else flag = false;
		if(flag)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	return 0;
}
