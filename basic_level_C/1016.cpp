/*
������ A �ġ�D
?A
?? ��Ϊ 1 λ���������֡�����Ϊ�� A ������ D
?A
??  ��ɵ������� P
?A
?? �����磺���� A=3862767��D
?A
?? =6���� A �ġ�6 ���֡�P
?A
??  �� 66����Ϊ A ���� 2 �� 6��

�ָ��� A��D
?A
?? ��B��D
?B
?? �����д������� P
?A
?? +P
?B
?? ��

�����ʽ��
������һ�������θ��� A��D
?A
?? ��B��D
?B
?? ���м��Կո�ָ������� 0<A,B<10
?10
?? ��

�����ʽ��
��һ������� P
?A
?? +P
?B
??  ��ֵ��

�������� 1��
3862767 6 13530293 3

      
    
������� 1��
399

      
    
�������� 2��
3862767 1 13530293 8

      
    
������� 2��
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
