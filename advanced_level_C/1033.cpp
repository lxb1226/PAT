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
	// �������������յ㣬�۸�Ϊ0���յ����ΪD 
	stations[n].price = 0;
	stations[n].distance = D;

	sort(stations, stations + n, cmp);
	if(stations[0].distance != 0){	// ��������ĵ�һ������վ���벻��0��˵���޷�ǰ�� 
		printf("The maximum travel distance = 0.00\n");
	}else{
		int now = 0;	// ��ǰ����վ���
		// �ܻ��ѡ���ǰ������������ʻ���� 
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;
		while(now < n){	// ÿ��ѭ����ѡ����һ����Ҫ����ļ���վ 
		// ѡ���ӵ�ǰ����վ�����ܵ��ﷶΧ�ڵĵ�һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ 
			// ���û�е��ڵ�ǰ�ͼ۵ļ���վ,��ѡ��۸���͵��Ǹ� 
			int k = -1;
			double priceMin = INF;
			for(int i = now + 1; i <= n && stations[i].distance - stations[now].distance <= MAX; i++){
				if(stations[i].price < priceMin){
					priceMin = stations[i].price;
					k = i;
					// ����ҵ���һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ,ֱ���ж�ѭ�� 
					if(priceMin < stations[now].price) break;
				}
			}
			if(k == -1) break;	// ����״̬���޷��ҵ�����վ,�˳�ѭ�������� 
			// ����Ϊ���ҵ��ɵ���ļ���վk������ת�ƻ���
			// needΪ��now��k��Ҫ������ 
			double need = (stations[k].distance - stations[now].distance) / Davg;
			if(priceMin < stations[now].price){	// �������վk���ͼ۵��ڵ�ǰ�ͼ�
				// ֻ���㹻�������վk���� 
				if(nowTank < need){
					ans += (need - nowTank) * stations[now].price;
					nowTank = 0;
				}else{
					nowTank -= need;
				}
			}else{	// �������վk���ͼ۸��ڵ�ǰ�ͼ� 
				ans += (Cmax - nowTank) * stations[now].price;
				nowTank = Cmax - need;
			}
			now = k;	// �������վk,������һ��ѭ�� 
		}
		// �ܵ����յ� 
		if(now == n) printf("%.2f\n", ans);
		else printf("The maximum travel distance = %.2f\n", stations[now].distance + MAX);
	}
	return 0;
	
	
	





}
