#include<cstdio>
const int maxn = 30;
// ��Ʒ����n����������v,����ֵmaxValue 
int n, V, maxValue = 0;
// w[i]Ϊÿ����Ʒ������,c[i]Ϊÿ����Ʒ�ļ�ֵ 
int w[maxn], c[maxn];
// DFS,indexΪ��ǰ�������Ʒ���
// sumW��sumC�ֱ�Ϊ��ǰ�������͵�ǰ�ܼ�ֵ 

//void DFS(int index, int sumW, int sumC){
//	if(index == n){			// �Ѿ���ɶ�n����Ʒ��ѡ��(����ͬ) 
//		if(sumW <= V && sumC > maxValue){
//			maxValue = sumC;	// ��������������ʱ��������ֵmaxValue 
//		}
//		return ;
//	}
//	// ����� 
//	DFS(index+1, sumW, sumC);	// ��ѡ��index����Ʒ 
//	DFS(index+1, sumW+w[index],sumC + c[index]);	//ѡ��index����Ʒ 
//}


// DFS�Ż�
void DFS(int index, int sumW, int sumC){
	if(index == n){			// �Ѿ���ɶ�n����Ʒ��ѡ��(����ͬ) 
		return ;
	}
	// ����� 
	DFS(index+1, sumW, sumC);	// ��ѡ��index����Ʒ 
	// ֻ���ڼ����index����Ʒ��δ��������V�����ܼ��� 
	if(sumw + w[index] <= V){
		if(sumC + c[index] > ans){
			ans = sumC + c[index];
		}
	DFS(index+1, sumW+w[index],sumC + c[index]);	//ѡ��index����Ʒ 
	}
} 

// ����
/*
5 8
3 5 1 2 2
4 5 2 1 3

*/ 

int main(){
	scanf("%d%d", &n, &V);
	for(int i = 0; i < n; i++)
		scanf("%d", &w[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	DFS(0,0,0);
	printf("%d\n", maxValue);
}
