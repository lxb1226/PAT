/*
��ƺ�����һԪ����ʽ�ĵ�������ע��x
?n
?? ��nΪ��������һ�׵���Ϊnx
?n?1
?? ����

�����ʽ:
��ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������ 1000 �������������ּ��Կո�ָ���

�����ʽ:
����������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�ע�⡰�����ʽ����ָ����ϵ������ 0�����Ǳ�ʾΪ 0 0��

��������:
3 4 -5 2 6 1 -2 0

      
    
�������:
12 3 -10 1 6 0

*/

#include<cstdio>

int main(){
	int a[1000] = {0};
	int k, e, count = 0;
	while((scanf("%d %d", &k, &e)) != EOF){
		a[e] = k;
	}
	a[0] = 0;
	for(int i = 1; i<=1000; i++){
		a[i-1] = a[i] * i;
		a[i] = 0;
		if(a[i-1] != 0) count++;
	}
	if(count == 0) printf("0 0");
	else{
		for(int i = 1000; i >= 0; i--){
			if(a[i] != 0){
				printf("%d %d", a[i], i);
				count--;
				if(count != 0) printf(" ");
			}
		}
	}
	
	return 0;
}