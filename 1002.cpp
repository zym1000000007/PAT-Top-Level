#include<algorithm>
#include <iostream>
#include<cstdio>
//#define N 100
#define MAX(a,b) a < b ? b : a
using namespace std;

struct goods {
	int sign;//???¡¤D¨°o?
	int weight;//???¡¤??¨¢?
	int value;//???¡¤???¦Ì
	int dead;
};

int n,bestValue,cv,cw,C;//???¡¤¨ºy¨¢?¡ê????¦Ì¡Á?¡ä¨®¡ê?¦Ì¡À?¡ã???¦Ì¡ê?¦Ì¡À?¡ã??¨¢?¡ê?¡À3¡ã¨¹¨¨Y¨¢?
struct goods goods[60];

bool cmp(struct goods x,struct goods y) {
	return x.dead < y.dead;
}

int KnapSack(int n,struct goods a[],int C) {
	int V[n+1][C+1];
	int min;
	for (int i=0; i<=n; i++)
		for (int j=0; j<=C; j++)
			V[i][j] = 0;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= C; j++) {
//				if (a[i-1].dead <= k)
			if (j < a[i-1].weight)
				V[i][j] = V[i-1][j];
			else {
				if (a[i-1].dead < j)
					min = a[i-1].dead;
				else
					min = j;
				V[i][j] = MAX(V[i-1][j],V[i-1][min-a[i-1].weight] + a[i-1].value);
			}
//				else
//					V[i][j][k] = V[i-1][j][k];
//				printf("i=%d j=%d V=%d\n",i,j,V[i][j]);
		}
	return V[n][C];
}
int main() {
	scanf("%d",&n);
	int C = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d",&goods[i].value,&goods[i].weight,&goods[i].dead);
		if (goods[i].dead > C)
			C = goods[i].dead;
	}
	sort(goods,goods+n,cmp);
//	printf("\n");
//	for (int i=0; i<n; i++) {
//		printf("%d %d %d\n",goods[i].value,goods[i].weight,goods[i].dead);
//	}
	int sum2 = KnapSack(n,goods,C);
	printf("%d",sum2);

	return 0;
}
