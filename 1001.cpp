#include <stdio.h>
#include <stdlib.h>
#define max 501
#define MAX 123456789

//typedef struct _Leaf {
//};

typedef struct _Node {
	int city,cnt,use,flag,price,group;
	int child[max][3];

} Node;

Node *node[max];

int DFS(Node *a,int group) {
	int i;
	if (a) {
//		printf("city=%d group=%d\n",a->city,group);
		a->group = group;
		a->flag = 1;
		for (i=0; i<a->cnt; i++) {
			if ((node[a->child[i][0]]->flag == 0) && (a->child[i][2] == 1)) {
				DFS(node[a->child[i][0]],group);
			}
		}
	}
}

int cmp(const void*a,const void*b) {
	return ((int*)a)[2] - ((int*)b)[2];
}

int cmp2(const void*a,const void*b) {
	return (int*)a - (int*)b;
}

int main(void) {
	int i,j,n,m,a,b,c,d,group,Group,cnt,g1,g2,fee,Max,cn,find;

	scanf("%d%d",&n,&m);
	int broken[m][3];
	int protest[n+1];
//	Node *node[n+1]=(Node*)malloc((n+1)*sizeof(Node));

	for (i=0; i<=n; i++) {
		node[i] = (Node*)malloc(sizeof(Node));
		node[i]->cnt = 0;
		node[i]->flag = 0;
		node[i]->city = i;
	}

	cnt = 0;
	for (i=0; i<m; i++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (d == 0) {
			broken[cnt][0] = a;
			broken[cnt][1] = b;
			broken[cnt][2] = c;
			cnt++;
		}
		node[a]->child[node[a]->cnt][0] = b;
		node[a]->child[node[a]->cnt][1] = c;
		node[a]->child[node[a]->cnt++][2] = d;
		node[b]->child[node[b]->cnt][0] = a;
		node[b]->child[node[b]->cnt][1] = c;
		node[b]->child[node[b]->cnt++][2] = d;
	}
//	for (i=0;i<cnt;i++) {
//		printf("%d %d %d\n",broken[i][0],broken[i][1],broken[i][2]);
//	}
//	printf("cnt=%d\n",cnt);
	qsort(broken,cnt,3*sizeof(int),cmp);
//	for (i=0;i<cnt;i++) {
//		printf("%d %d %d\n",broken[i][0],broken[i][1],broken[i][2]);
//	}
	Max = 0;
	cn = 0;
	for (i=1; i<=n; i++) {
		for (j=0; j<=n; j++) {
			node[j]->flag = 0;
		}
		node[i]->flag = 1;
		node[i]->group = 0;
		fee = 0;
		group = 0;
		for (j=1; j<=n; j++) {
			if (node[j]->flag == 0) {
				group++;
				DFS(node[j],group);
			}
		}
//		printf("i=%d group=%d\n",i,group);
		Group = group;
		while (Group > 1) {
			find = 0;
			for (j=0; j<cnt; j++) {
				g1 = node[broken[j][0]]->group;
				g2 = node[broken[j][1]]->group;
				if ((g1 > 0) && (g2 > 0) && (g1 != g2)) {
					find = 1;
//					printf("")
					fee += broken[j][2];
					break;
				}
			}
			if (find == 0) {
				fee = MAX;
				break;
			}
			for (j=1; j<=n; j++) {//ио?DFS?и╣?им
				if (node[j]->group == g2) {
					node[j]->group = g1;
				}
			}
			Group--;
		}
		if (fee > Max) {
			Max = fee;
			protest[0] = i;
			cn = 1;
		} else if (fee == Max) {
			protest[cn++] = i;
		}
//		printf("i=%d fee=%d\n",i,fee);
	}

	if (Max == 0) {
		printf("0");
	} else {
//		qsort(protest,cn,sizeof(int),cmp2);
		for (i=0; i<cn; i++) {
			if (i > 0) {
				printf(" ");
			}
			printf("%d",protest[i]);
		}
	}

	return 0;
}
