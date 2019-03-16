#include <stdio.h>
#include <map>
#include <set>
#include <math.h>
using namespace std;

typedef struct _Node {
	int hum,wolf;
	set <int> sw,sh;
} Node;

Node node[200];
int n,m,l,M,L,cnt,LIAR,solu;
int iswolf[200],isliar[200],ans[200],ANS[200];

int cmp1(int *a,int *b,int len) {
	int yes=0;
	for (int i=0; i<len; i++) {
		if (a[i] > b[i]) {
			yes = 1;
			break;
		} else if (a[i] < b[i]) {
			yes = -1;
			break;
		}
	}
	return yes;
}

int digui(int a,int wolf,int liar) {
	if (a <= n) {
		if (liar > l) {
			return -1;
		}
//		if (liar + n-a+1 < l) {
//			return -1;
//		}
		if (wolf > m) {
			return -1;
		}
		if (wolf + n-a+1 < m) {
			return -1;
		}
		iswolf[a] = 1;
		wolf++;
		liar += node[a].hum;
		for (auto it=node[a].sh.begin(); it!=node[a].sh.end(); it++) {
			isliar[*it] = 1;
		}
		digui(a+1,wolf,liar);
		wolf--;
		liar -= node[a].hum;
		for (auto it=node[a].sh.begin(); it!=node[a].sh.end(); it++) {
			isliar[*it] = 0;
		}
		iswolf[a] = 0;
		liar += node[a].wolf;
		for (auto it=node[a].sw.begin(); it!=node[a].sw.end(); it++) {
			isliar[*it] = 1;
		}
		digui(a+1,wolf,liar);
		for (auto it=node[a].sw.begin(); it!=node[a].sw.end(); it++) {
			isliar[*it] = 0;
		}
	} else {
		if ((liar == l) && (wolf == m)) {
			cnt = 0;
			LIAR = 0;
			for (int i=n; i>0; i--) {
				if (iswolf[i] == 1) {
					ans[cnt++] = i;
					if (isliar[i] == 1) {
						LIAR++;
					}
				}
			}
			if ((LIAR > 0) && (LIAR < m) && (cmp1(ans,ANS,cnt) > 0)) {
				solu = 1;
				for (int i=0; i<cnt; i++) {
					ANS[i] = ans[i];
				}
			}
		}
	}
}

int main(void) {
	int i,j,x;

	scanf("%d%d%d",&n,&m,&l);

	for (i=0; i<=n; i++) {
		node[i].hum = 0;
		node[i].wolf = 0;
	}
	for (i=1; i<=n; i++) {
		scanf("%d",&x);
//		speak[i] = x;
		if (x < 0) {
			node[abs(x)].wolf++;
			node[abs(x)].sw.insert(i);
		} else {
			node[abs(x)].hum++;
			node[abs(x)].sh.insert(i);
		}
	}
	digui(1,0,0);
	if (solu == 1) {
		for (int i=0; i<cnt; i++) {
			if (i > 0) {
				printf(" ");
			}
			printf("%d",ANS[i]);
		}
	} else {
		printf("No Solution");
	}

	return 0;
}
