#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

int main(){
	int n;
	map<int,int> mp;
	scanf("%d", &n);
	int id, score;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &id, &score);
		if(mp.count(id) != 0) mp[id] += score;
		else mp[id] = score;
	}
	map<int,int>::iterator it = mp.begin();
	int max_id, max_score = 0;
	for(it; it != mp.end(); it++){
		if(it->second > max_score){
			max_id = it->first;
			max_score = it->second;
		}
	}
	printf("%d %d", max_id, max_score);
	
}
