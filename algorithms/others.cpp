// 最大公约数
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
} 

// 最小公倍数 ab/d, d为最大公约数
// 略

// 分数的表示和化简
struct Fraction{
	int up, down;
}; 

// 分数的化简
Fraction reduction(Fraction result){
	if(result.down < 0){
		result.up = - result.up;
		result.down = - result.down;
	}
	if(result.up == 0){
		result.down = 1;
	}else{
		int d = gcd(abs(result.up), abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
} 

// 分数的加法
Fraction add(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down + f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
} 
// 分数的减法 
Fraction minu(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down - f2.up * f1.down;
	result.down = f1.down * f2.down;
	return reduction(result);
} 

// 分数的乘法
Fraction multi(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}  

// 分数的除法 
Fraction div(Fraction f1, Fraction f2){
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

// 素数的判断
bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i = 2; i <= sqr; i++){
		if(n % i == 0) return false;
	}
	return true;
} 

bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i * i <= n; i++)
		if(n % 2 == 0) return false;
	return true;
}

// 素数表的获取
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
void Find_Prime(){
	for(int i = 1;i < maxn; i++){
		if(isPrime(i) == true){
			prime[pNum++] = i;
			p[i] = true;
		}
	}
} 

// 筛法求素数表
void Find_Prime(){
	for(int i = 2; i < maxn; i++){
		if(p[i] == false){
			prime[pNum++] = i;
			for(int j = i + i; j < maxn; j += i){
				p[j] = true;
			}
		}
	}
} 

// 质因子分解
struct factor{
	int x, cnt;
}fac[10]; 

if(n % prime[i] == 0){
	fac[num].x = prime[i];
	fac[num].cnt = 0;
	while(n % prime[i] == 0){
		fac[num].cnt++;
		n /= prime[i];
	}
	num++;
}

if(n != 1){
	fac[num].x = n;
	fac[num++].cnt = 1;
}

// 哈夫曼树
priority_queue<long long, vector<long long>, greater<long long>> q;
int main(){
	int n;
	long long temp, x, y, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &temp);
		q.push(temp);
	}
	while(q.size() > 1){
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x + y);
		ans += x + y;
	}
	printf("%lld\n", ans);
	return 0;
} 
