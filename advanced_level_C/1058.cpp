#include<cstdio>

int main(){
	long long a, b, c, d, e, f;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
	long long result = (a + d) * 29 * 17 + (b+e) * 29 + c + f;
	printf("%lld.%lld.%lld", result / 29 / 17, result / 29 % 17, result % 29);
	return 0;
}
