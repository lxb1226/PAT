#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn = 510;
const int INF = 100000000;

struct Station{
	double distance;
	double price;
}stations[maxn];

bool cmp(Station a, Station b){
	return a.distance < b.distance;
}

int main(){
	int n;
	double Cmax, D, Davg;
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
	for(int i = 0; i < n; i++){
		scanf("%lf %lf", &stations[i].price, &stations[i].distance);
	}
	// 数组最后面放置终点，价格为0，终点距离为D 
	stations[n].price = 0;
	stations[n].distance = D;

	sort(stations, stations + n, cmp);
	if(stations[0].distance != 0){	// 如果排序后的第一个加油站距离不是0，说明无法前进 
		printf("The maximum travel distance = 0.00\n");
	}else{
		int now = 0;	// 当前加油站编号
		// 总花费、当前油量及满油行驶距离 
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;
		while(now < n){	// 每次循环将选出下一个需要到达的加油站 
		// 选出从当前加油站满油能到达范围内的第一个油价低于当前油价的加油站 
			// 如果没有低于当前油价的加油站,则选择价格最低的那个 
			int k = -1;
			double priceMin = INF;
			for(int i = now + 1; i <= n && stations[i].distance - stations[now].distance <= MAX; i++){
				if(stations[i].price < priceMin){
					priceMin = stations[i].price;
					k = i;
					// 如果找到第一个油价低于当前油价的加油站,直接中断循环 
					if(priceMin < stations[now].price) break;
				}
			}
			if(k == -1) break;	// 满油状态下无法找到加油站,退出循环输出结果 
			// 下面为能找到可到达的加油站k，计算转移花费
			// need为从now到k需要的油量 
			double need = (stations[k].distance - stations[now].distance) / Davg;
			if(priceMin < stations[now].price){	// 如果加油站k的油价低于当前油价
				// 只买足够到达加油站k的油 
				if(nowTank < need){
					ans += (need - nowTank) * stations[now].price;
					nowTank = 0;
				}else{
					nowTank -= need;
				}
			}else{	// 如果加油站k的油价高于当前油价 
				ans += (Cmax - nowTank) * stations[now].price;
				nowTank = Cmax - need;
			}
			now = k;	// 到达加油站k,进入下一层循环 
		}
		// 能到达终点 
		if(now == n) printf("%.2f\n", ans);
		else printf("The maximum travel distance = %.2f\n", stations[now].distance + MAX);
	}
	return 0;
	
	
	





}
