/*
�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�

ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ����������� 3 ���±����������ֱ�Ϊ 18��15��10 ��֣����ۼ۷ֱ�Ϊ 75��72��45 ��Ԫ������г������������ֻ�� 20 ��֣���ô��������������Ӧ��������ȫ�� 15 ��ֵ� 2 ���±����Լ� 5 ��ֵ� 3 ���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��
ÿ���������һ������������ÿ�����������ȸ���һ�������� 1000 �������� N ��ʾ�±������������Լ������� 500�������Ϊ��λ���������� D ��ʾ�г���������������һ�и��� N ��������ʾÿ���±��Ŀ�����������Ϊ��λ�������һ�и��� N ��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���

�����ʽ��
��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С����� 2 λ��

����������
3 20
18 15 10
75 72 45

      
    
���������
94.50
*/

#include<cstdio>
#include<algorithm>

using namespace std;

struct mooncake{
	double price;
	double sell;
	double store;
}cakes[1010];

bool cmp(mooncake a, mooncake b){
	return a.price > b.price;
}
int main(void){
	int n;
	double D, ans = 0;
	scanf("%d %lf", &n,&D);
	for(int i = 0; i < n; i++)
		scanf("%lf", &cakes[i].store);
	for(int i = 0; i < n; i++){
		scanf("%lf", &cakes[i].sell);
		cakes[i].price = cakes[i].sell / cakes[i].store;
	}
	sort(cakes,cakes+n,cmp);
	for(int i = 0; i<n; i++){
		if(cakes[i].store < D){
			ans += cakes[i].sell;
			D -= cakes[i].store;
		}else{
			ans += cakes[i].price * D;
			break;
		}
	}
	printf("%.2f\n", ans);
	
	
	
	return 0;
}
