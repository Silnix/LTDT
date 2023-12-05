#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n,x;
int a[10][10];		
int stack[100];
int stdOut[100];
int t = 0;			//dinh vi tri them dinh vao mang stack
int t1 = 0; 		//dinh vi tri them dinh vao mang stdout

void docFile();
void inFile();
void eulerDFS(int v);
int giatri();
bool isEuler(int n);
void eulerDFS2(int v);

int main() {
    docFile();
    inFile();
	
	if (isEuler(n)) {
    	printf("\nDo thi co chu trinh Euler\n");
		printf("\nNhap dinh xuat phat: ");
    	scanf("%d", &x);
    	int checkgiatri = giatri();	// 1: nho hon hoac bang 1; 0: lon hon 1
    											
    	if (checkgiatri == 1) {
        	printf("\nDon do thi:");
        	eulerDFS(x);
    	} else {
        	printf("\nDa do thi:");
        	eulerDFS2(x);
    	}	
    } else {
    	printf("\nDo thi khong co chu trinh Euler\n");
    }
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

void eulerDFS (int v) {
	stack[t++] = v; 						//them v vao stack o vi tri t
	while(t > 0) {
		int u = stack[t - 1];
		int k = 0;
		for (int i = 1; i <= n; i++) {
            if (a[u][i] != 0) { 			//tim dinh ke cua u
                stack[t++] = i; 			//them i vao stack
                a[u][i] = a[i][u] = 0; 		//xoa canh (u,i) va (i,u)
                k = 1; 						//da tim duoc canh ke
                break; 						//dung tim ke
            }
        }
		if (k == 0) {
			t--; 							//xoa dinh tren cung stack
            stdOut[t1++] = u; 				//them u vao stdout
		}
	}	
	printf("\nChu trinh Euler la:");
    	for (int i = t1 -1; i >=  0; i--) {
            printf("%d", stdOut[i]); 
            if (i > 0) 
                printf(" -> ");
            
        }
        printf("\n");
}

void eulerDFS2 (int v) {
	stack[t++] = v; 						//them v vao stack o vi tri t
	while(t > 0) {
		int u = stack[t - 1];
		int k = 0;
		for (int i = 1; i <= n; i++) {
            if (a[u][i] != 0) { 			//tim dinh ke cua u
                stack[t++] = i; 			//them i vao stack
                a[u][i]--; 
				a[i][u]--; 		
                k = 1; 						//da tim duoc canh ke
                break; 						//dung tim ke
            }
        }
		if (k == 0) {
			t--; 							//xoa dinh tren cung stack
            stdOut[t1++] = u; 				//them u vao stdout
		}
	}	
	printf("\nChu trinh Euler la:");
    	for (int i = t1 -1; i >=  0; i--) {
            printf("%d", stdOut[i]); 
            if (i > 0) 
                printf(" -> ");
            
        }
        printf("\n");
}

int giatri() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] > 1) {
                return 0;  // lon hon 1
            }
        }
    }
    return 1;  // nho hon hoac bang 1
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
        return 1;// duong cheo khac 0
    }
}

int tinhbac(int n) {			
    int bac = 0;
    for (int i = 1; i <= n; i++) {
        bac += a[i][n];
    }
    int checkduongcheo = duongcheo();
    if (checkduongcheo == 1) {
        bac += a[n][n];
    }
    return bac;
}

bool isEuler(int n) {
	int bacn = tinhbac(n);
    if (bacn % 2 != 0) { 	
	return false;
	}
	bacn = 0;
}
