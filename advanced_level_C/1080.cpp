#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

// TODO
using namespace std;
const int MAXN = 40001;
struct Applicant{
	int id;
	int Ge, Gi;
	int choice[6];
	int score_all;
	int rank;
}applicant[MAXN];

bool cmp(Applicant a, Applicant b){
	if(a.score_all != b.score_all) return a.score_all > b.score_all;
	else return a.Ge > b.Ge;
}


int quotas[101];
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d", quotas + i);
	}
	vector<int> numbers[m];
	for(int i = 0; i < n; i++){
		scanf("%d %d", &applicant[i].Ge, &applicant[i].Gi);
		applicant[i].id = i;
		applicant[i].score_all = round((applicant[i].Ge + applicant[i].Gi) / 2) + 0.5;
		for(int j = 0; j < k; j++)
			scanf("%d", &applicant[i].choice[j]);
	}
	sort(applicant, applicant + n, cmp);
	applicant[0].rank = 1;
	for(int i = 1; i < n; i++){
		if(applicant[i].score_all == applicant[i - 1].score_all){
			if(applicant[i].Ge != applicant[i-1].Ge) applicant[i].rank = applicant[i-1].rank + 1;
			else applicant[i].rank = applicant[i-1].rank;
		}else
			applicant[i].rank = applicant[i-1].rank + 1;
	}
//	for(int i = 0; i < n; i++){
//		printf("%d %d %d %d %d", applicant[i].id, applicant[i].Ge,applicant[i].Gi,applicant[i].score_all, applicant[i].rank);
//		for(int j = 0; j < k; j++){
//			printf(" %d", applicant[i].choice[j]);
//		}
//		printf("\n");
//	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int index = applicant[i].choice[j];
			if(quotas[index] > 0){
				numbers[index].push_back(applicant[i].id);
				quotas[index]--;
				break;
			}else{
				int id = numbers[index][numbers[index].size() - 1];
				if(applicant[i].rank == applicant[id].rank){
//					if(i == 9){
//						printf("%d %d %d", applicant[i].rank, )
//					}
					numbers[index].push_back(applicant[i].id);
					quotas[index]--;
					break;
				}
			}
		}
	}
	for(int i = 0; i < m; i++){
		int size = numbers[i].size();
		if(size != 0){
			sort(numbers[i].begin(),numbers[i].end());
			for(int j = 0; j < size; j++){
				if(j == size - 1)
					printf("%d\n", numbers[i][j]);
				else
					printf("%d ", numbers[i][j]);
			}
				
		}else{
			printf("\n");
		}
	}
	
	return 0;
}
