#include <stdio.h>
void fx (int a[][100], int n, int x);
void fy (int a[][100], int n, int y);
void fk (int a[][100], int n, int k);
void fm (int a[][100], int n, int m);
void chan (int a[][100], int n);
void duongcheo (int a[][100], int n);
void check (int a[][100], int n);
void doixung (int a[][100], int n);

int main() {
    int n;
    	printf("Nhap he so n cua ma tran vuong: ");
    	scanf("%d", &n);
    int a[100][100];
    	printf("Nhap ma tran: \n");
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			printf("Phan tu a[%d][%d]: ",i,j);
        		scanf("%d", &a[i][j]);	
    		}
    	}	
		printf("Ma tran vuong vua nhap:\n");
    	for (int i = 0; i < n; i++) {
        	for (int j = 0; j < n; j++) {
            	printf("%3d ", a[i][j]);
        	}
        	printf("\n");
    	}
	int x, y, k, m;
    	printf("Nhap hang x: ");
    	scanf("%d", &x);
	fx(a,n,x);
		printf("Nhap cot y: ");
    	scanf("%d", &y);
    fy(a,n,y);
    	printf("Nhap hang k: ");
    	scanf("%d", &k);
    fk(a,n,k);
    	printf("Nhap cot m: ");
    	scanf("%d", &m);
    fm(a,n,m);
    
    chan(a,n);
 	duongcheo(a,n);
 	check(a,n);
 	doixung(a,n);
 	
 return 0;   
}

void fx (int a[][100], int n, int x) {
	int maxHangx = a[x - 1][0];
    for (int j = 1; j < n; j++) {
        if (a[x - 1][j] > maxHangx) {
            maxHangx = a[x - 1][j];
        }
    }
    printf("Phan tu lon nhat tren hang %d: %d\n", x, maxHangx);
}
    
void fy (int a[][100], int n, int y) {
	int minCoty = a[0][y - 1];
    for (int i = 1; i < n; i++) {
        if (a[i][y - 1] < minCoty) {
            minCoty = a[i][y - 1];
        }
    }
    printf("Phan tu nho nhat tren cot %d: %d\n", y, minCoty);
}

void fk (int a[][100], int n, int k) {
	int tongHangk = 0;
    for (int j = 0; j < n; j++) {
        tongHangk += a[k - 1][j];
    }
    printf("Tong cac phan tu tren hang %d: %d\n", k, tongHangk);
}

void fm (int a[][100], int n, int m) {   
    int tongCotm = 0;
    for (int i = 0; i < n; i++) {
        tongCotm += a[i][m - 1];
    }
    printf("Tong cac phan tu tren cot %d: %d\n", m, tongCotm);
}

void chan (int a[][100], int n) {
	int sum = 0;
    printf("Tong cac phan tu co gia tri chan la: ");
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (a[i][j] % 2 == 0) {
           		sum += a[i][j];
        	}
    	}
    }
    printf("%d",sum);
    printf("\n");
}

void duongcheo (int a[][100], int n) {
	int dung = 1;
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) {
            dung = 0;
            break;
        }
    }
    if (dung) {
        printf("Duong cheo bang 0\n");
    }else {
        printf("Duong cheo khac 0\n");
    }
}

void check (int a[][100], int n) {
	int dung = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 1) {
                dung = 0;
                break;
            }
        }
        if (!dung) {
            break;
        }
    }
    if (dung) {
        printf("YES\n");
    }else {
        printf("NO\n");
    }
}

void doixung (int a[][100], int n) {
	int dung = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
        printf("DOI XUNG\n");
    } else {
        printf("KHONG DOI XUNG\n");
    }
}
