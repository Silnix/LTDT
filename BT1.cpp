#include <stdio.h>
#include <stdlib.h>

int a[10][10], n;
void docfile();
void infile();
int doixung();
int duongcheo();
int giatri();

int main() {
    docfile();
    infile();
    
    int checkdoixung = doixung();							// 1: co doi xung; 0: khong doi xung
    int checkduongcheo = duongcheo();						// 1: khac 0; 0: bang 0
    int checkgiatri = giatri();								// 1: nho hon hoac bang 1; 0: lon hon 1
    
    if (checkdoixung == 1)  {							//vo huong											
        if (checkduongcheo == 0) {	
			if (checkgiatri == 1) {
        		printf("\n-->Ten: Don do thi vo huong");
    		} else {
        		printf("\n-->Ten: Da do thi vo huong");
    		}	
        } else {
            printf("\n-->Ten: Gia do thi");						
        }
    } else {											//co huong
    	if (checkgiatri == 1) {
        	printf("\n-->Ten: Don do thi co huong");
    	} else {
        	printf("\n-->Ten: Da do thi co huong");
    	}
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
        return 1;// co doi xung
    } else {
        return 0;// khong doi xung
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
        return 1;// duong cheo khac 0
    }
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
