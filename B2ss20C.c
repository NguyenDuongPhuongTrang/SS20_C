#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Shop{
	int id;
	char name[100];
	float importPrice, sellingPrice;
	int quantity;
};
void addProduct(struct Shop *sh, int *num, float *revenuePtr){
	printf("\nNhap ID san pham: ");
	scanf("%d", &sh[(*num) - 1].id);
	fflush(stdin);
	printf("Nhap ten san pham: ");
	fgets(sh[(*num) - 1].name, 100, stdin);
	printf("Nhap gia nhap: ");
	scanf("%f", &sh[(*num) - 1].importPrice);
	printf("Nhap gia ban: ");
	scanf("%f", &sh[(*num) - 1].sellingPrice);
	printf("Nhap so luong: ");
	scanf("%d", &sh[(*num) - 1].quantity);
	printf("\n");
}
void printProduct(struct Shop *sh, int *numPtr){
	printf("\nCac san pham hien co\n");
	for(int i = 0 ; i < *numPtr; i++){
		printf("\nID: %d\n", sh[i].id);
		printf("\nTen san pham: %s", sh[i].name);
		printf("\nGia ban: %.2f", sh[i].sellingPrice);
		printf("\nSo luong: %d", sh[i].quantity);
		printf("\n\n");
	}
}
void editProduct(struct Shop *sh, int *num){
	int id, found = 0;
	printf("\nNhap ID san pham can chinh sua: ");
	scanf("%d", &id);
	fflush(stdin);
	for(int i = 0; i < *num; i++){
		if(id == sh[i].id){
			printf("\nNhap ten san pham: ");
			fgets(sh[i].name, 100, stdin);
			printf("\nNhap gia nhap: ");
			scanf("%f", &sh[i].importPrice);
			printf("\nNhap gia ban: ");
			scanf("%f", &sh[i].sellingPrice);
			printf("\nNhap so luong: ");
			scanf("%d", &sh[i].quantity);
			found = 1;
		}
	}
	if(found == 0){
		printf("\nSan pham khong ton tai\n\n");
	}
	else{
		printf("\nSua hoan tat\n\n");
	}
}
void sortByPrice(struct Shop *sh, int *num){
	int sortPrice;
	printf("\n1. Tang dan\n");
	printf("\n2. Giam dan\n\n");
	fflush(stdin);
	scanf("%d", &sortPrice);
	switch(sortPrice){
		case 1:
			for(int i = 0; i < *num - 1; i++){
				for(int j = 0; j < *num - i - 1; j++){
					if(sh[j].sellingPrice > sh[j+1].sellingPrice){
						struct Shop temp = sh[j];
						sh[j] = sh[j+1];
						sh[j+1] = temp;
					}
				}
			}
			printf("\nSap xep hoan tat\n\n");
			break;
		case 2:
			for(int i = 0; i < *num - 1; i++){
				for(int j = 0; j < *num - i - 1; j++){
					if(sh[j].sellingPrice < sh[j+1].sellingPrice){
						struct Shop temp = sh[j];
						sh[j] = sh[j+1];
						sh[j+1] = temp;
					}
				}
			}
			printf("\nSap xep hoan tat\n\n");
			break;
		default:
			printf("\nChuc nang khong hop le\n\n");
			break;
	}
}
void searchProduct(struct Shop *sh, int *num){
	int id, found = 0;
	printf("\nNhap ID san pham: ");
	scanf("%d", &id);
	for(int i = 0; i < *num; i++){
		if(id == sh[i].id){
			printf("\nID: %d", sh[i].id);
			printf("\nTen san pham: %s", sh[i].name);
			printf("\nGia nhap : %.2f", sh[i].importPrice);
			printf("\nGia ban: %.2f", sh[i].sellingPrice);
			printf("\nSo luong: %d", sh[i].quantity);
			printf("\n\n");
			found = 1;
		}
	}
	if(found == 0){
		printf("\nID khong ton tai\n\n");
	}
}
void sellProduct(struct Shop *sh, int *num, float *revenuePtr){
	int id, found = 0, quantity;
	printf("\nNhap ID san pham muon ban: ");
	scanf("%d", &id);
	for(int i = 0; i < *num; i++){
		if(id == sh[i].id){
			found = 1;
			printf("\nNhap so luong san pham: ");
			scanf("%d", &quantity);
			if(sh[i].quantity <= 0){
				printf("\nSan pham da het vui long nhap them\n\n");
			}
			else if(quantity > sh[i].quantity){
				printf("\nKhong du so san pham\n\n");
			}
			else{
				(*revenuePtr) += quantity * sh[i].sellingPrice;
				sh[i].quantity -= quantity;
				printf("\nBan thanh cong\n\n");
			}
		}
	}
	if(found == 0){
		printf("\nID san pham khong ton tai\n\n");
	}
}
void checkProduct(struct Shop *sh, int *num, float *revenuePtr, int choice){
	if((*num) == 0){
		printf("\nKhong co san pham nao ton tai\n\n");
	}
	else{
		switch(choice){
			case 2:
				printProduct(sh, num);
				break;
			case 3:
				break;
			case 4:
				editProduct(sh, num);
				break;
			case 5:
				sortByPrice(sh, num);
				break;
			case 6:
				searchProduct(sh, num);
				break;
			case 7:
				sellProduct(sh, num, revenuePtr);
				break;
		}
	}
}
int main(){
	float revenue = 0;
	float *revenuePtr = &revenue;
	int choice, num = 0;
	int *numPtr = &num;
	struct Shop *sh = (struct Shop *)calloc(0, sizeof(struct Shop));
	do{
		printf("1. Nhap so luong va thong tin san pham\n");
		printf("2. Hien thi danh sach san pham\n");
		printf("3. Nhap san pham\n");
		printf("4. Cap nhat thong tin san pham\n");
		printf("5. Sap xep theo gia\n");
		printf("6. Tim kiem san pham\n");
		printf("7. Ban san pham\n");
		printf("8. Doanh thu hien tai\n");
		printf("9. Thoat\n");
		printf("Nhap chuc nang: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				(*numPtr)++;
				sh = realloc(sh, (*numPtr)*sizeof(struct Shop));
				addProduct(sh, numPtr, revenuePtr);
				break;
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				checkProduct(sh, numPtr, revenuePtr, choice);
				break;
			case 8:
				printf("\nDoanh thu cua ban la: %.2f\n\n", revenue);
				break;
			case 9:
				printf("\nThoat thanh cong\n\n");
				break;
			default:
				printf("\nChuc nang khong ton tai\n\n");
				break;
		}
	}
	while(choice != 9);
	free(sh);
	return 0;
}

