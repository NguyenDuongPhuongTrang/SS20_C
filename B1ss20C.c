#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Books{
	char id[10];
	char name[100];
	char author[50];
	float price;
};
void addBooks(struct Books *book, int *number){
	for(int i=0; i<*number; i++){
		printf("Nhap ID sach: ");
		scanf("%d",&book[i].id);
		fflush(stdin);
		printf("Nhap ten sach: ");
		fgets(book[i].name,100,stdin);
		printf("Nhap ten tac gia: ");
		fgets(book[i].author,50,stdin);
		printf("Nhap gia sach: ");
		scanf("%f",&book[i].price);
	}
}
void printBooks(struct Books *book, int *numberPtr){
	printf("\nCac loai sach hien co la: \n");
	for(int i = 0; i < (*numberPtr); i++){
		printf("\nID: %d\n",*book[i].id);
		printf("\nTen sach: %s", book[i].name);
		printf("\nTac gia: %s", book[i].author);
		printf("\nGia tien: %.2f", book[i].price);
		printf("\n\n");
	}
}
void newBooks(struct Books *book, int *numberPtr){
	int index;
	printf("\nNhap vi tri muon them sach (0 -> %d): ", *numberPtr);
	scanf("%d", &index);
	if(index < 0 || index > *numberPtr){
		printf("\nVi tri them sach khong hop le\n\n");
	}
	else{
		(*numberPtr)++;
		book = realloc(book, (*numberPtr)* sizeof(struct Books));
		for(int i = (*numberPtr); i > index; i--){
			book[i] = book[i-1];
		}
		printf("\nNhap ID: ");
		scanf("%d", &book[index].id);
		fflush(stdin);
		printf("Nhap ten sach: ");
		fgets(book[index].name, 100, stdin);
		printf("Nhap ten tac gia: ");
		fgets(book[index].author, 100, stdin);
		printf("Nhap gia tien: ");
		scanf("%f", &book[index].price);
		printf("\n");
	}
}
void deleteBooks(struct Books *book, int *numberPtr){
	int id, found = 0;
	printf("\nNhap ID sach can xoa: ");
	scanf("%d", &id);
	for(int i = 0; i < (*numberPtr); i++){
		if(id == *book[i].id){
			found = 1;
			for(int j = i; j < (*numberPtr) - 1; j++){
				book[j] = book[j+1];
			}
		break;
		}
	}
	if(found == 0){
		printf("\nID sach khong ton tai\n\n");
	}
	else{
		(*numberPtr)--;
		printf("\nXoa thanh cong\n\n");
	}
}
void editBooks(struct Books *book, int *numberPtr){
	int id, found = 0;
	printf("\nNhap ID can chinh sua: ");
	scanf("%d", &id);
	fflush(stdin);
	for(int i = 0; i < (*numberPtr); i++){
		if(id == *book[i].id){
			found = 1;
			printf("\nNhap ten sach: ");
			fgets(book[i].name, 100, stdin);
			printf("Nhap ten tac gia: ");
			fgets(book[i].author, 100, stdin);
			printf("Nhap gia: ");
			scanf("%f", &book[i].price);
		}
	}
	if(found == 0){
		printf("\nID sach khong ton tai\n\n");
	}
	else{
		printf("\nChinh sau thanh cong\n\n");
	}
}
void sortPrice(struct Books *book, int *numberPtr){
	int choice;
	printf("\n1. Tang dan\n");
	printf("\n2. Giam dan\n\n");
	fflush(stdin);
	scanf("%d", &choice);
	switch(choice){
		case 1:
			for(int i = 0; i < (*numberPtr) - 1; i++){
				for(int j = 0; j < (*numberPtr) - i - 1; j++){
					if(book[j].price > book[j+1].price){
						struct Books temp = book[j];
						book[j] = book[j+1];
						book[j+1] = temp;
					}
				}
			}
			printf("\nSap xep hoan tat\n\n");
			break;
		case 2:
			for(int i = 0; i < (*numberPtr) - 1; i++){
				for(int j = 0; j < (*numberPtr) - i- 1; j++){
					if(book[j].price < book[j+1].price){
						struct Books temp = book[j];
						book[j] = book[j+1];
						book[j+1] = temp;
					}
				}
			}
			printf("\nsap xep thanh cong\n\n");
			break;
		default:
			printf("\nChuc nang nhap khong hop le\n\n");
			break;
	}
}void searchName(struct Books *book, int *numberPtr){
	char *name;
	int found = 0;
	name = (char *)calloc(100, sizeof(char));
	printf("\nNhap ten sach: ");
	fflush(stdin);
	fgets(name, 100, stdin);
	for(int i = 0; i < (*numberPtr); i++){
		if(strstr(book[i].name, name) != NULL){
			printf("\nID: %d", *book[i].id);
			printf("\nTen sach: %s", book[i].name);
			printf("\nTen tac gia: %s", book[i].author);
			printf("\nGia tien: %.2f", book[i].price);
			printf("\n");
			found = 1;
		}
	}
	printf("\n");
	if(found == 0){
		printf("\nTen sach khong ton tai\n\n");
	}
	free(name);
}
void checkBooks(struct Books *book, int *numberPtr, int choice){
	if((*numberPtr) == 0){
		printf("\nChua them sach vao thu vien\n\n");
	}
	else{
		switch(choice){
			case 2:
				printBooks(book, numberPtr);
				break;
			case 3:
				newBooks(book, numberPtr);
				break;
			case 4:
				deleteBooks(book, numberPtr);
				break;
			case 5:
				editBooks(book, numberPtr);
				break;
			case 6:
				sortPrice(book, numberPtr);
				break;
			case 7:
				searchName(book, numberPtr);
				break;
		}
	}
}
int main(){
	int choice, number = 0;
	int *numberPtr = &number;
	struct Books *book = (struct Books*)calloc(number, sizeof(struct Books));
	do{
		printf("\nMENU\n");
		printf("1.Nhap so luong thong tin sach\n");
		printf("2.Hien thi thong tin sach\n");
		printf("3.Them sach vao vi vi tri\n");
		printf("4.Xoa sach theo ma sach\n");
		printf("5.Cap nhat thong tin sach theo ma sach\n");
		printf("6.Sap xep sach theo gia\n");
		printf("7.Tim kiem sach theo ten sach\n");
		printf("8.THOAT\n");
		printf("Moi ban chon chuc nang: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap so luong sach: ");
				scanf("%d",&number);
				if(number <= 0){
					printf("So sach khong hop le\n");
				}else{
					book = realloc(book, number * sizeof(struct Books));
					addBooks(book,&number);
				}	
				break;
			case 2:
			case 3:	
			case 4:
			case 5:
			case 6:	
			case 7:
				checkBooks(book, numberPtr, choice);
				break;
			case 8:
				printf("THOAT THANH CONG\n");
				break;
			default:
				printf("Chuc nang khong hop le\n");
				break;
		}
	}while(choice!=8);
	free(book);
	return 0;
}

