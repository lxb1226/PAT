

/*
Ϊ������ʵ˵���ھ�����������ļ�ǿ��PAT ��֯��һ���ھ�����ܴ�������������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��

�����ʽ��
�����ڵ� 1 �и��������� 10^5�������� N����������������� N �У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ����������������ѧУ�ı�ţ��� 1 ��ʼ������ţ�����������ɼ����ٷ��ƣ����м��Կո�ָ���

�����ʽ��
��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ�����Ŀ��֤��Ψһ��û�в��С�

����������
6
3 65
2 80
1 100
2 70
3 40
3 0

���������
2 150
*/
#include<stdio.h>
int main(void){
	int N;
	int index, score;
	int max_index, max_score = 0;
	scanf("%d", &N);
	int scores[100010] = {0};
	for(int i = 0; i<N; i++){
		scanf("%d %d", &index, &score);
		scores[index] += score;

	}
	for(int j = 1; j<=N; j++){
		if(scores[j] > max_score){
			max_score = scores[j];
			max_index = j;
		}
	}
	printf("%d %d",max_index, max_score);
	
	
	return 0;
}
