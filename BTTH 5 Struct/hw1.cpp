#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student{
	char ID[10];
	char Name[50];
	int Age;
	float GPA;
};

void displayStudent(struct Student s) {
    printf("ID: %s\n", s.ID);
    printf("Ho va Ten: %s\n", s.Name);
    printf("Tuoi: %d\n", s.Age);
    printf("GPA: %.2f\n", s.GPA);
    printf("\n");
}

int main(){
	struct Student student[100];
	int numStudent = 0;
	int choice;
	
	while(1){
		printf("1. Them sinh vien \n");
		printf("2. Hien thi thong tin sinh vien \n");
		printf("3. Chinh sua thong tin sinh vien \n");
		printf("4. Thoat chuong trinh \n");
		printf("Nhap lua chon cua ban:");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				if(numStudent < MAX_STUDENTS){
					printf("Nhap ID cua sinh vien: ");
					scanf("%s", &student[numStudent].ID);
					printf("Nhap ten cua sinh vien: ");
					getchar();
					fgets(student[numStudent].Name, sizeof(student[numStudent].Name), stdin);
					printf("Nhap tuoi cua sinh vien: ");
					scanf("%d", &student[numStudent].Age);
					printf("Nhap GPA cua sinh vien: ");
					scanf("%f", &student[numStudent].GPA);
					if(student[numStudent].Age > 16 && student[numStudent].Age < 80){
						numStudent++;
					}else {
						printf("Tuoi khong hop le.\n");
					}
				}else {
                    printf("Da dat den gioi han hoc sinh	.\n");
                }
				break;
			case 2:
				if(numStudent > 0){
					printf("Thong tin cua hoc sinh:\n");
					for (int i = 0; i < numStudent; i++){
						displayStudent(student[i]);
					}
				}else {
					printf("Khong co hoc sinh de hien thi.\n");
				}
				break;
			case 3:
				if(numStudent > 0){
					int studentIndex;
					printf("Nhap so thu tu cua sinh vien ban muon cap nhat(0-%d)", numStudent - 1);
					scanf("%d", &studentIndex);
					if(studentIndex >=0 && studentIndex < numStudent){
						printf("Nhap ID moi cua sinh vien: ");
						scanf("%s", &student[numStudent].ID);
						printf("Nhap ten cua sinh vien: ");
						getchar();
						fgets(student[numStudent].Name, sizeof(student[numStudent].Name), stdin);
						printf("Nhap tuoi cua sinh vien: ");
						scanf("%d", &student[numStudent].Age);
						printf("Nhap GPA cua sinh vien: ");
						scanf("%f", &student[numStudent].GPA);
						if(student[studentIndex].Age <= 16 && student[studentIndex].Age >= 80){
							printf("Tuoi khong hop le, thong tin cua sinh vien khong duoc cap nhat.\n");
						}
					}else {
						printf("Thu tu cua sinh vien khong hop le.\n");
					}
				}else{
					printf("Khong co thong tin cua sinh vien de cap nhat.\n");
				}
				break;
			case 4:
				printf("Dang thoat chuong trinh.\n");
				return 0;
			default:
				printf("Thong tin nhap khong hop le. Vui long thu lai.\n");
		}
		printf("\n");
	}
	return 0;
}
