#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define MAX 123456
#define lowbit(x) ((x) & (-(x)))

struct Node {
	int v,seq,index;
};

long long c[MAX];

long long getsum(int x) {
	long long sum=0;
	for (int i=x; i>0; i-=lowbit(i)) {
		sum += c[i];
	}
	return sum;
}

void add(int x,int k) {
	for (int i=x; i<MAX; i+=lowbit(i)) {
		c[i] += k;
	}
}

bool cmp1(Node a,Node b) {
	return a.v < b.v;
}

bool cmp2(Node a,Node b) {
	return a.index < b.index;
}

int main(void) {
	long long i,n,m,a,b,ans=0;

	scanf("%lld",&n);
	Node node[n+1];

	for (i=1; i<=n; i++) {
		scanf("%d",&a);
		node[i].v = a;
		node[i].index = i;
	}
	sort(node+1,node+n+1,cmp1);
	for (i=1; i<=n; i++) {
		node[i].seq = i;
	}
	sort(node+1,node+n+1,cmp2);
	add(node[1].seq,1);
	for (i=2; i<n; i++) {
		add(node[i].seq,1);
		m = getsum(node[i].seq);//¦Ì¨²i??¨ºy?¡ã??¡À¨¨??D?¦Ì???¨ºy+1
		a = i - m;
		b = node[i].seq - m;
		ans += a * b;
	}
	printf("%lld",ans);

	return 0;
}
