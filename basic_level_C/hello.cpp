#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

struct fruit{
	string name;
	int price;
	friend bool operator < (fruit f1, fruit f2){
		return f1.price > f2.price;
	}
}f1, f2, f3;

int main(void){
//	string str = "hello,world";
//   	cout << str;
//	printf("%s", str.c_str());

//	for(string::iterator it=str.begin(); it != str.end(); it++)
//		printf("%c", *it);
//	map<char,int> mp;
//	mp['m'] = 20;
//	mp['c'] = 50;
//	mp['r'] = 30;
//	for(map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
//		printf("%c->%d\n", it->first, it->second);
//	}

	priority_queue<fruit> q;
	f1.name = "Àæ×Ó";
	f1.price = 3;
	f2.name="Æ»¹û";
	f2.price = 4;
	f3.name="Ïã½¶";
	f3.price = 1;
	q.push(f1);
	q.push(f2);
	q.push(f3);
	
	cout << q.top().name << " " << q.top().price;
	
	return 0;
}
