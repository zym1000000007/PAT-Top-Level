#include <stdio.h>
#include <bits/stdc++.h>
#define MAX 12345
using namespace std;

vector <int> city[MAX];
int tt,cnt,sig,n,m;
int visit[MAX],dfn[MAX],low[MAX],s[MAX],color[MAX];

int targin(int u) {
	visit[u] = 1;
	low[u]=dfn[u]=cnt++;
	s[++tt]=u;
	for (auto it=city[u].begin(); it!=city[u].end(); it++) {
		int v = (*it);
		if (visit[v] == 0) {
			targin(v);
		}
		if (visit[v] == 1) {
			low[u] = min(low[u],low[v]);
		}
	}
//	printf("u=%d dfn=%d low=%d tt=%d sig=%d\n",u,dfn[u],low[u],tt,sig);
	if (dfn[u] == low[u]) {
		sig++;
		do {
			color[s[tt]] = sig;
			visit[s[tt]] = -1;
		} while (s[tt--] != u);
	}
}

void solve() {
	tt = -1;
	cnt = 1;
	sig = 0;
	for (int i=1; i<=n; i++) {
		if (visit[i] == 0) {
			targin(i);
		}
	}
}

int main() {
	int k,x,y;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		scanf("%d%d",&x,&y);
		city[x].push_back(y);
	}
	solve();
	scanf("%d",&k);
	for (int i=0; i<k; i++) {
		scanf("%d%d",&x,&y);
		if (color[x] == color[y]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
//	for (int i=1; i<=n; i++) {
//		printf("%d color=%d low=%d\n",i,color[i],low[i]);
//	}

	return 0;
}
