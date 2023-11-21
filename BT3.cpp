#include <stdio.h>
#include <stdlib.h>

int n, x, k, t = 0;
int d[100], S[100], a[10][10];

void docFile();
void inFile();
void khoiTaoD();
void dfs(int x);

int main() {
    docFile();
    inFile();

    printf("\nNhap dinh can duyet x = ");
    scanf("%d", &x);
    khoiTaoD();
    printf("\nKet qua duyet DFS(%d) la: ", x);
	dfs(x);

    return 0;
}

void docFile() {
    FILE *f;
    f = fopen("D://110122227 - DA22TTB//mtk.txt", "r");
    if (f == NULL) {
        printf("Khong tim thay file! Vui long thu lai!");
        exit(0);
    } else {
        fscanf(f, "%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                fscanf(f, "%d", &a[i][j]);
            }
        }
    }
    fclose(f);
}

void inFile() {
    printf("Ma tran ke: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

void khoiTaoD() {
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
    }
}

void dfs(int x) {
    S[t] = x;
    t++;
    while (t > 0) {
        k = S[t - 1];
        t--;
        if (!d[k]) {
            printf("%2d", k);
            d[k] = -1;
        }
        for (int i = n; i >= 1; i--) {
            if (a[k][i] && !d[i]) {
                S[t] = i;
                t++;
            }
        }
    }
}
