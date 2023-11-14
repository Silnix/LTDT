#include <stdio.h>
#include <stdlib.h>

int a[10][10], n, x;

void docfile();
void infile();
int doixung();
int tinhbac(int x);
int tinhbacra(int x);
int tinhbacvao(int x);

int main() {
    docfile();
    infile();

    printf("\nNhap dinh can tinh bac x = ");
    scanf("%d", &x);

    int checkdoixung = doixung(); 										// 1: co doi xung; 0: khong doi xung
    if (checkdoixung == 1) {      										// vo huong
        printf("\n->Bac dinh %d la: %d.", x, tinhbac(x));
    } else { 															// co huong
        printf("\n->Bac vao dinh x = %d la: %d.", x, tinhbacvao(x));
        printf("\n->Bac ra dinh x = %d la: %d.", x, tinhbacra(x));
    }
    return 0;
}

void docfile() {
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

void infile() {
    printf("Ma tran ke: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}

int doixung() {
    int dung = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != a[j][i]) {
                dung = 0;
                break;
            }
        }
        if (!dung) {
            break;
        }
    }
    if (dung) {
        return 1; // co doi xung
    } else {
        return 0; // khong doi xung
    }
}

int duongcheo() {
    int dung = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i][i] != 0) {
            dung = 0;
            break;
        }
    }
    if (dung) {
        return 0; // duong cheo bang 0
    } else {
        return 1; // duong cheo khac 0
    }
}

int tinhbac(int x) {				//tong dong x, quan tam duong cheo, xem co khuyen khong
    int bac = 0;
    for (int i = 1; i <= n; i++) {
        bac += a[x][i];
    }
    int checkduongcheo = duongcheo();
    if (checkduongcheo == 1) {
        bac += a[x][x];
    }
    return bac;
}

int tinhbacvao(int x) {				//tong cot x
    int bac = 0;
    for (int i = 1; i <= n; i++) {
        bac += a[i][x];
    }
    return bac;
}

int tinhbacra(int x) {				//tong dong x
    int bac = 0;
    for (int i = 1; i <= n; i++) {
        bac += a[x][i];
    }
    return bac;
}

