#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define MAXN 12345
using namespace std;

int c[MAXN],C[MAXN];

int solve(int n,int *a) {
	int i,j,len,index,k;

	int b[n],d[n];
	len = 1;

	d[1] = a[0], c[0] = 1;
	for (int i = 1; i < n; ++ i) {
		if (d[len] < a[i]) {
			d[++ len] = a[i], c[i] = len;
		} else {
			int j = lower_bound(d + 1, d + len + 1, a[i]) - d;//¨°a¦Ì¨²¨°???¡ä¨®¨®¨²¦Ì¨¨¨®¨²¦Ì?¡ê????¨¹¨º?D¡ä?t¡¤?
			d[j] = a[i], c[i] = j;
		}
	}

	return len;
}

int solve2(int n,int *a) {
	int i,j,len,index,k;

	int b[n],d[n];
	len = 1;

	d[1] = a[0], C[0] = 1;
	for (int i = 1; i < n; ++ i) {
		if (d[len] < a[i]) {
			d[++ len] = a[i], C[i] = len;
		} else {
			int j = lower_bound(d + 1, d + len + 1, a[i]) - d;//¨°a¦Ì¨²¨°???¡ä¨®¨®¨²¦Ì¨¨¨®¨²¦Ì?¡ê????¨¹¨º?D¡ä?t¡¤?
			d[j] = a[i], C[i] = j;
		}
	}

	return len;
}

int main(void) {
	int i,j,n,len1,len2,cnt1,cnt2,max=-1,len=0,index,v,min=123456;

	scanf("%d",&n);
	int a[n],b[n];

	for (i=0; i<n; i++) {
		scanf("%d",&a[i]);
		b[n-1-i] = a[i];
	}
	solve(n,a);
	solve2(n,b);
//	for (i=0;i<n;i++) {
//		printf("i=%d a=%d b=%d c=%d C=%d\n",i,a[i],b[i],c[i],C[i]);
//	}

	for (i=1; i<n-1; i++) {
		len1 = c[i]-1;
		len2 = C[n-1-i]-1;
		if ((len1 > 0) && (len2 > 0)) {
			len = len1 + len2 + 1;
		}
		if (len > max) {
			max = len;
			index = i+1;
			v = a[i];
			min = abs(len1-len2);
		} else if ((len == max) && (abs(len1-len2) < min)) {
			max = len;
			index = i+1;
			v = a[i];
			min = abs(len1-len2);
		}
	}
	if (max > 2) {
		printf("%d %d %d",max,index,v);
	} else {
		printf("No peak shape");
	}

	return 0;
}
