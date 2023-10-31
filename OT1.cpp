#include <stdio.h>
void opx (int a[], int n);
void fmax (int a[], int n);
void fmin (int a[], int n); 
void le (int a[], int n );
void tong (int a[], int n);

int main() {
    int n;

    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", &n);

    int a[n];

    printf("Nhap mang %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
 
 	opx(a,n);
 	fmax(a,n);
 	fmin(a,n);
 	le(a,n);
 	tong(a,n);
 
 return 0;   
}

void opx (int a[], int n) { 
    int x, i;
    printf("Nhap x: ");
    scanf("%d", &x);
    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("Gia tri phan tu thu %d la: %d\n", i + 1, x);
            break;
        }
    }
    if (i == n) {
        printf("Khong tim thay gia tri %d trong mang.\n", x);
    }
}    

void fmax (int a[], int n) {
    int max = a[0], MAX = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            MAX = i;
        }
    }
    printf("Vi tri max: %d, gia tri max: %d\n", MAX + 1, max);
}

void fmin (int a[], int n) {
    int min = a[0], MIN = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            MIN = i;
        }
    }
    printf("Vi tri min: %d, gia tri min: %d\n", MIN + 1, min);
}

void le (int a[], int n) {
    printf("Cac so le trong mang: ");
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void tong (int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    printf("Tong gia tri cua cac phan tu trong mang: %d\n", sum);
}

