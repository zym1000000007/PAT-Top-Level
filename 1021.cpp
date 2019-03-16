#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

typedef struct _Node {
	int price,num,id,flag,group,use,dp;
	set <struct _Node*> s;
} Node;

set <int> choose,MAX;
vector <Node*> v[101];
int cnt,maxnum,PRICE,MINPRICE;

int DFS(Node *root,int group) {
	if (root) {
		root->group = group;
		v[group].push_back(root);
		for (auto it=root->s.begin(); it!=root->s.end(); it++) {
			if (((*it)->use == 1) && ((*it)->group == -1)) {//??TM?¨®¡ã?¡ê??1¨®D??1?¨¢D?¨²¨¦???¡ê?¦Ì?????2???????¦Ì?
				DFS(*it,group);
			}
		}
	}
}

int deep(Node** node,int be,int en,int group) {
	int i;
	int j = be;
	if (be - en < 0) {
		i = v[group][j]->id;
		deep(node,be+1,en,group);
		if (node[i]->dp == 0) {
			node[i]->dp = maxnum;
		}
		if ((node[i]->flag == 0) && (cnt+en-be >= maxnum)) {
			if ((cnt+node[i]->dp < maxnum) && (node[i]->dp > 0)) {
				return -1;
			}
			node[i]->flag = 1;
			choose.insert(i);
			cnt++;
			PRICE += node[i]->price;
			for (auto it = node[i]->s.begin(); it!=node[i]->s.end(); it++) {
				(*it)->flag--;
			}
			deep(node,be+1,en,group);
			node[i]->flag = 0;
			choose.erase(i);
			cnt--;
			PRICE -= node[i]->price;
			for (auto it = node[i]->s.begin(); it!=node[i]->s.end(); it++) {
				(*it)->flag++;
			}
		}
	} else {
		if (cnt > maxnum) {
			maxnum = cnt;
			MAX = choose;
			MINPRICE = PRICE;
		} else if (cnt == maxnum) {
			if (PRICE < MINPRICE) {
				maxnum = cnt;
				MAX = choose;
				MINPRICE = PRICE;
			}
		}
	}
}

int main(void) {
	int i,j,n,m,x,y,first,group,finalnum,finalprice,number,bad;
	set <int> finalchoose;

	scanf("%d%d",&n,&m);
	Node *node[1000];

	for (i=0; i<1000; i++) {
		node[i] = new Node;
		node[i]->id = i;
		node[i]->flag = 0;
		node[i]->group = -1;
		node[i]->use = 0;
		node[i]->dp = 0;
	}

	for (i=0; i<n; i++) {
		scanf("%d%d",&x,&y);//3??ID¨°a¡Áa??3¨¦1-M
		node[x]->s.insert(node[y]);
		node[y]->s.insert(node[x]);
	}
	for (i=0; i<m; i++) {
		scanf("%d%d",&x,&y);
		node[x]->use = 1;
		node[x]->price = y;
	}
	for (i=0; i<m; i++) {
		bad = 0;
		for (auto it=node[i]->s.begin(); it!=node[i]->s.end(); it++) {
			if ((*it)->use == 0) {
				bad++;
			}
		}
		node[x]->num = node[x]->s.size() - bad;
	}
	group = 0;
	for (i=0; i<1000; i++) {
		if ((node[i]->use == 1) && (node[i]->group == -1)) {
			DFS(node[i],group);
			group++;
		}
	}
	finalnum = 0;
	finalprice = 0;
	for (i=0; i<group; i++) {
		PRICE = 0;
		cnt = 0;
		choose.clear();
		maxnum = 0;
		MINPRICE = 0;
		MAX.clear();
		deep(node,0,v[i].size(),i);
		finalnum += maxnum;
		finalprice += MINPRICE;
		finalchoose.insert(MAX.begin(),MAX.end());
	}
	printf("%d\n",finalnum);
	first = 1;
	for (auto it = finalchoose.begin(); it!=finalchoose.end(); it++) {
		if (first == 0) {
			printf(" ");
		} else {
			first = 0;
		}
		printf("%03d",*it);
	}
	printf("\n%d",finalprice);

	return 0;
}
