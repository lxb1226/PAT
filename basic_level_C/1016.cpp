/*
正整数 A 的“D
?A
?? （为 1 位整数）部分”定义为由 A 中所有 D
?A
??  组成的新整数 P
?A
?? 。例如：给定 A=3862767，D
?A
?? =6，则 A 的“6 部分”P
?A
??  是 66，因为 A 中有 2 个 6。

现给定 A、D
?A
?? 、B、D
?B
?? ，请编写程序计算 P
?A
?? +P
?B
?? 。

输入格式：
输入在一行中依次给出 A、D
?A
?? 、B、D
?B
?? ，中间以空格分隔，其中 0<A,B<10
?10
?? 。

输出格式：
在一行中输出 P
?A
?? +P
?B
??  的值。

输入样例 1：
3862767 6 13530293 3

      
    
输出样例 1：
399

      
    
输入样例 2：
3862767 1 13530293 8

      
    
输出样例 2：
0
*/

#include<cstdio>

using namespace std;

int D_part(long long A, int DA){
	long PA;
	for(PA = 0; A != 0; A /=10){
		if(A % 10 == DA){
			PA = PA*10 + DA;
		}
	}
	return PA;
}
int main(){
	long long A,B, PA, PB;
	int DA, DB;
	scanf("%lld %d %lld %d", &A, &DA, &B, &DB);
	PA = D_part(A, DA);
	PB = D_part(B, DB);
	long long result = PA + PB;
	printf("%lld", result);
	
	return 0;
}
