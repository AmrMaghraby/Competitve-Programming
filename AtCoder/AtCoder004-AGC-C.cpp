#include <bits/stdc++.h>
using namespace std;
const int N = 510;
char v[N][N];
char r[N][N];
char b[N][N];
int main(){
	int h,w;
	scanf("%d%d", &h, &w);
    for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			scanf(" %c", &v[i][j]);
		}
	}
	memset(b, '.', sizeof b);
	memset(r, '.', sizeof r);
	// blue
	for (int i = 0; i < h; ++i){
		if (i % 2 == 0){
			b[i][0] = '#';
		} else {
			for (int j = 0; j < w-1; ++j)
				b[i][j] = '#';
		}
	}
    // red
	for (int i = 0; i < h; ++i) {
		if (i % 2 == 1) {
			r[i][w-1] = '#';
		} else {
			for (int j = 1; j < w; ++j)
				r[i][j] = '#';
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if(b[i][j] == '.' && v[i][j] == '#') {
				b[i][j] = '#';
			}
			if(r[i][j] == '.' && v[i][j] == '#') {
				r[i][j] = '#';
			}
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			printf("%c", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			printf("%c", r[i][j]);
		}
		printf("\n");
	}
}
