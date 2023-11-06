#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree.h"

#define LH -1  	 /* Cay con trai cao hon */
#define EH 0	 /* Hai cay con bang nhau */
#define RH 1 	 /* Cay con phai cao hon */


void themTu(AVLTree &T);
AVLNode* timKiem(AVLTree T, char tuAnh[]);
int suaTu(AVLTree &T, char tuAnh[]);


int main() {
    AVLTree t;
    t = NULL;
    char tu[20], tuUp[20], tuDel[20];
    char c;
    do {
        fflush(stdin);
        themTu(t);
        printf("Tiep tuc them (y/n): ");scanf("%c", &c);
    } while(c == 'y');
    NLR(t);
}

void themTu(AVLTree &T) {
	TU tu;
	do {
		printf("Nhap tu can them: ");gets(tu.tuAnh);
		if(timKiem(T, tu.tuAnh) != NULL)
			printf("Tu nay da co trong tu dien. Vui long nhap lai!!!\n");
	} while(timKiem(T, tu.tuAnh) != NULL);
	printf("Nhap tu loai: ");gets(tu.loaiTu);
	printf("Nhap nghia cua tu can them: ");gets(tu.nghia);
	printf("Nhap vi du ve tu da them: ");gets(tu.viDu);
	if(insertNode(T, tu))
		printf("Them thanh cong.\n");
	else if(!insertNode(T, tu))
		printf("Tu nay da co san trong tu dien");
	else
		printf("Khong du bo nho luu tru.\n");
}

AVLNode* timKiem(AVLTree T, char tuAnh[]) {
	if(T == NULL) {
		return NULL;
	}	
	if(stricmp(T->Key.tuAnh, tuAnh) == 0)
		return T;
	return (stricmp(T->Key.tuAnh, tuAnh) > 0)?timKiem(T->pLeft, tuAnh):timKiem(T->pRight, tuAnh);
}

int suaTu(AVLTree &T, char tuAnh[]) {
	if(T == NULL)
		return -1;
	AVLNode* T1 = timKiem(T, tuAnh);
	if(T1) {
		printf("Nhap tu loai: ");gets(T1->Key.loaiTu);
		printf("Nhap nghia cua tu: ");gets(T1->Key.nghia);
		printf("Nhap vi du ve tu: ");gets(T1->Key.viDu);
		return 1;
	}
	return 0;
}
