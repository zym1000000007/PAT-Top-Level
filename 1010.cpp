#include <stdio.h>
#include <bits/stdc++.h>
#define MAX 123456
#define lowbit(x) ((x) & (-(x)))
using namespace std;

struct Node {
	int v,seq,index;
};

int c[MAX],b[MAX];

int getsum(int x) {
	int sum=0;
	for (int i=x; i>0; i-=lowbit(i)) {
		sum+=c[i];
	}
	return sum;
}

int add(int x,int k) {
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
	int i,n,m,a;

	scanf("%d",&n);
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
	for (i=1; i<=n; i++) {
		add(node[i].seq,1);
		m = getsum(node[i].seq);
		b[i] = node[i].seq-m;
	}
	for (i=1; i<=n; i++) {
		if (i > 1) {
			printf(" ");
		}
		printf("%d",b[i]);
	}
	return 0;
}
