#include<cstdio>
#include<cstring>
const int MAX_LEN = 10005;
char a[MAX_LEN], b[MAX_LEN];
bool HashTable[128];

int main(){
	fgets(a, MAX_LEN-1,stdin);
	fgets(b, MAX_LEN -1 , stdin);
	int lenA = strlen(a);
	int lenB = strlen(b);
	for(int i = 0; i < lenB; i++){
		HashTable[b[i]] = true;
	}
	for(int i = 0; i < lenA; i++){
		if(HashTable[a[i]] == false){
			putchar(a[i]);
		}
	}
} 
