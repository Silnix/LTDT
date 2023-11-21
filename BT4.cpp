#include <stdio.h>
#include <stdlib.h>

int n, x, v, t = 0;
int d[100], T[100], a[10][10];

void docFile();
void inFile();
void khoiTaoD();
void bfs(int v);

int main() {
    docFile();
    inFile();

    printf("\nNhap dinh bat dau v = ");
    scanf("%d", &v);
    khoiTaoD();
    printf("\nKet qua duyet BFS(%d) la:", v);
    bfs(v);

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

void bfs(int v) {
	T[t] = v; 												
    t++;
    d[v] = -1;
	while (t > 0) {
        x = T[0]; 								//x la vi tri dau tien trong mang T
        printf("%2d", x);						//in x ra lam ket qua
        for (int i = 0; i < t; i++) {			//doi cac phan tu trong mang T sang trai 1 vi tri
            T[i] = T[i + 1];
        } 
       	t--;
        for (int i = 1; i <= n; i++) {
            if (a[x][i] && !d[i]) {
                T[t] = i; 				//them i vao mang T vo vi tri t
				t++; 					//tang vi tri t			
                d[i] = -1; 				//danh dau dinh i da duyet
            }
        }
    }
}
