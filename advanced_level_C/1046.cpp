/*
The task is really simple: given N exits on a highway which forms a simple cycle, 
you are supposed to tell the shortest distance between any pair of exits.

Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3,10
?5
?? ]), followed by N integer distances D
?1
??  D
?2
??  ? D
?N
?? , where D
?i
??  is the distance between the i-th and the (i+1)-st exits, and D
?N
??  is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (¡Ü10
?4
?? ), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10
?7
?? .

Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
1-2,2-3
2 5
2-3,3-4,4-5
4 1
4-3,3-2,2-1
      
    
Sample Output:
3
10
7
*/

#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100005;
int dis[MAXN], A[MAXN];


int main(){
	int sum = 0, query, n, left, right;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", A+i);
		sum += A[i];
		dis[i] = sum;
	}

	scanf("%d", &query);
	for(int i = 0; i < query; i++){
		scanf("%d %d", &left, &right);
		if(left > right) swap(left, right);
		
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum-temp));
	}
}
