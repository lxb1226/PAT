#include<cstdio>
const int maxn = 30;
// 物品件数n，背包容量v,最大价值maxValue 
int n, V, maxValue = 0;
// w[i]为每件物品的重量,c[i]为每件物品的价值 
int w[maxn], c[maxn];
// DFS,index为当前处理的物品编号
// sumW和sumC分别为当前总重量和当前总价值 

//void DFS(int index, int sumW, int sumC){
//	if(index == n){			// 已经完成对n件物品的选择(死胡同) 
//		if(sumW <= V && sumC > maxValue){
//			maxValue = sumC;	// 不超过背包容量时更新最大价值maxValue 
//		}
//		return ;
//	}
//	// 岔道口 
//	DFS(index+1, sumW, sumC);	// 不选第index件物品 
//	DFS(index+1, sumW+w[index],sumC + c[index]);	//选第index件物品 
//}


// DFS优化
void DFS(int index, int sumW, int sumC){
	if(index == n){			// 已经完成对n件物品的选择(死胡同) 
		return ;
	}
	// 岔道口 
	DFS(index+1, sumW, sumC);	// 不选第index件物品 
	// 只有在加入第index件物品后未超过容量V，才能继续 
	if(sumw + w[index] <= V){
		if(sumC + c[index] > ans){
			ans = sumC + c[index];
		}
	DFS(index+1, sumW+w[index],sumC + c[index]);	//选第index件物品 
	}
} 

// 样例
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
