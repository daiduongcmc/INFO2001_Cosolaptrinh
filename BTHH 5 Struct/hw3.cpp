#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char position[50];
    float salary;
};

void displayEmployee(struct Employee s) {
    printf("ID: %d\n", s.id);
    printf("Ho va Ten: %s\n", s.name);
    printf("Vi tri: %s\n", s.position);
    printf("Luong: %.2f\n", s.salary);
    printf("\n");
}

int main() {
	struct Employee employees[100];
	int numEmployees = 0;
    int choice;
    
	while(1){
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep nhan vien\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                if (numEmployees < MAX_EMPLOYEES) {
					struct Employee newEmployee;
                	printf("Nhap ma nhan vien: ");
                	scanf("%d", &newEmployee.id);
                	printf("Nhap ten nhan vien: ");
                	getchar();
					fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
                	printf("Nhap chuc vu: ");
                	getchar();
					fgets(newEmployee.position, sizeof(newEmployee.position), stdin);
                	printf("Nhap luong: ");
                	scanf("%f", &newEmployee.salary);
                	employees[numEmployees] = newEmployee;
                	numEmployees++;
                }else {
                printf("Khong the them nhan vien. So luong nhan vien da dat gioi han.\n");
            	}
                break;
            }
            case 2: {
                int id;
                printf("Nhap Id nhan vien can xoa: ");
                scanf("%d", &id);

                int foundIndex = -1;
                for (int i = 0; i < numEmployees; i++) {
                    if (employees[i].id == id) {
                        foundIndex = i;
                        break;
                    }
                }
                if (foundIndex != -1) {
                    for (int i = foundIndex; i < numEmployees - 1; i++) {
                        employees[i] = employees[i + 1];
                    }
                    numEmployees--;

                    printf("Da xoa nhan vien.\n");
                } else {
                    printf("Khong tim thay nhan vien co ma nhan vien la %d.\n", id);
                }
                break;
            }
            case 3: {
                if (numEmployees == 0) {
                    printf("Khong co nhan vien nao duoc luu tru.\n");
                } else {
                    printf("Danh sach nhan vien:\n");
                    printf("Ma NV\tTen NV\tChuc vu\tLuong\n");
                    for (int i = 0; i < numEmployees; i++) {
                        printf("%d\t%s\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].position, employees[i].salary);
                    }
                }
                break;
            }
            case 4: {
                for (int i = 0; i < numEmployees - 1; i++) {
                    for (int j = 0; j < numEmployees - 1 - i; j++) {
                        if (employees[j].id > employees[j + 1].id) {
                            struct Employee temp = employees[j];
                            employees[j] = employees[j + 1];
                            employees[j + 1] = temp;
                        }
                    }
                }
                printf("Da sap xep nhan vien theo ma nhan vien.\n");
                break;
            }
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}
