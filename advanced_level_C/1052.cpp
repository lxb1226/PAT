/*
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive N (<10
?5
?? ) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by ?1.

Then N lines follow, each describes a node in the format:

Address Key Next

      
    
where Address is the address of the node in memory, Key is an integer in [?10
?5
?? ,10
?5
?? ], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:
For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

      
    
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/

#include<cstdio>
#include<algorithm>

using namespace std;
const int size = 100010;
struct Node{
	int key;
	int address;
	int next;
	bool flag;
}nodes[size];

int cmp(Node a,  Node b){
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;
	}else{
		return a.key < b.key;
	}
}

int main(void){
	for(int i = 0; i < size; i++)
		nodes[i].flag = false;
	int N, begin;
	scanf("%d %d", &N, &begin);
	int key, address, next;
	for(int i = 0; i<N; i++){
		scanf("%d %d %d", &address, &key, &next);
		nodes[address].key = key;
		nodes[address].next = next;
		nodes[address].address = address;
	}
	int count = 0, p = begin;
	while(p != -1){
		nodes[p].flag = true;
		count++;
		p = nodes[p].next;
	}
	
	if(count == 0)
		printf("0 -1");
	else{
		sort(nodes, nodes+size, cmp);
		printf("%d %05d\n", count, nodes[0].address);
		for(int i = 0; i<count; i++){
			if(i != count - 1)
				printf("%05d %d %05d\n", nodes[i].address, nodes[i].key,nodes[i+1].address);
			else
				printf("%05d %d -1", nodes[i].address, nodes[i].key);
		}
	}
	
	
	return 0;
}
