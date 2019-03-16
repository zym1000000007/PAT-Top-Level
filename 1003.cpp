#include <stdio.h>
#include <bits/stdc++.h>
#define INIMAX 123456789
#define MAX 1234
using namespace std;

map<string,int> city;
int n,m,w;
int r[MAX][MAX],pre[MAX];
string f,en,x,y;
bool vis[MAX];

bool BFS(int s,int t) {
	queue<int> que;
	memset(pre,-1,sizeof(pre));
	memset(vis,false,sizeof(vis));

	pre[s] = s;
	vis[s] = true;
	que.push(s);

	int p;
	while (!que.empty()) {
		p = que.front();
		que.pop();
		for (int i=1; i<=n; i++) {
			if ((r[p][i] > 0) && (vis[i] == false)) {
				pre[i] = p;
				vis[i] = true;
				if (i == t) {
					return true;
				}
				que.push(i);
			}
		}
	}
	return false;
}

int EK(int s,int t) {
	int maxflow = 0;
	int d;
	while (BFS(s,t)) {
		d = INIMAX;
		for (int i=t; i!=s; i=pre[i]) {
			d = min(d,r[pre[i]][i]);
		}
		for (int i=t; i!=s; i=pre[i]) {
			r[pre[i]][i] -= d;
			r[i][pre[i]] += d;
		}
		maxflow += d;
	}
	return maxflow;
}

int main() {
	cin >> f >> en >> m;
	city.insert(make_pair(f,city.size()+1));
	city.insert(make_pair(en,city.size()+1));
	for (int i=0; i<m; i++) {
		cin >> x >> y >> w;
		city.insert(make_pair(x,city.size()+1));
		city.insert(make_pair(y,city.size()+1));
		r[city[x]][city[y]] += w;
	}
	n = city.size();
	cout << EK(1,2);

	return 0;
}
