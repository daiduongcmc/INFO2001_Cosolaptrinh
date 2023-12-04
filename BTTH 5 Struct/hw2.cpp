#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
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

void bubbleSortByGPA(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].GPA > arr[j + 1].GPA) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortByName(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].Name, arr[j + 1].Name) > 0) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearchByName(struct Student arr[], int n, char name[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].Name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int linearSearchByID(struct Student arr[], int n, char ID[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].ID, ID) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Student student[MAX_STUDENTS];
    int numStudent = 0;
    int choice;
    
    while (1) {
        printf("1. Them sinh vien\n");
        printf("2. Hien thi thong tin sinh vien\n");
        printf("3. Sap xep danh sach sinh vien theo diem GPA\n");
        printf("4. Sap xep danh sach sinh vien theo ten\n");
        printf("5. Tim kiem sinh vien theo ten\n");
        printf("6. Tim kiem sinh vien theo ID\n");
        printf("7. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (numStudent < MAX_STUDENTS) {
                    printf("Nhap ID cua sinh vien: ");
                    scanf("%s", student[numStudent].ID);
                    printf("Nhap ten cua sinh vien: ");
                    getchar();
                    fgets(student[numStudent].Name, sizeof(student[numStudent].Name), stdin);
                    printf("Nhap tuoi cua sinh vien: ");
                    scanf("%d", &student[numStudent].Age);
                    printf("Nhap GPA cua sinh vien: ");
                    scanf("%f", &student[numStudent].GPA);
                    if (student[numStudent].Age > 16 && student[numStudent].Age < 80) {
                        numStudent++;
                    } else {
                        printf("Tuoi khong hop le.\n");
                    }
                } else {
                    printf("Da dat den gioi han hoc sinh.\n");
                }
                break;
            case 2:
                if (numStudent > 0) {
                    printf("Thong tin cua hoc sinh:\n");
                    for (int i = 0; i < numStudent; i++) {
                        displayStudent(student[i]);
                    }
                } else {
                    printf("Khong co hoc sinh de hien thi.\n");
                }
                break;
            case 3:
                if (numStudent > 0) {
                    bubbleSortByGPA(student, numStudent);
                    printf("Danh sach sinh vien da sap xep theo diem GPA:\n");
                    for (int i = 0; i < numStudent; i++) {
                        displayStudent(student[i]);
                    }
                } else {
                    printf("Khong co sinh viende sap xep.\n");
                }
                break;
            case 4:
                if (numStudent > 0) {
                    bubbleSortByName(student, numStudent);
                    printf("Danh sach sinh vien da sap xep theo ten:\n");
                    for (int i = 0; i < numStudent; i++) {
                        displayStudent(student[i]);
                    }
                } else {
                    printf("Khong co sinh vien de sap xep.\n");
                }
                break;
            case 5: {
                if (numStudent > 0) {
                    char searchName[50];
                    printf("Nhap ten sinh vien can tim: ");
                    getchar();
                    fgets(searchName, sizeof(searchName), stdin);
                    searchName[strlen(searchName) - 1] = '\0';  // Xóa k? t? newline '\n'
                    int index = linearSearchByName(student, numStudent, searchName);
                    if (index != -1) {
                        printf("Thong tin sinh vien:\n");
                        displayStudent(student[index]);
                    } else {
                        printf("Khong tim thay sinh vien.\n");
                    }
                } else {
                    printf("Khong co sinh vien de tim kiem.\n");
                }
                break;
            }
            case 6: {
                if (numStudent > 0) {
                    char searchID[10];
                    printf("Nhap ID sinh vien can tim: ");
                    scanf("%s", searchID);
                    int index = linearSearchByID(student, numStudent, searchID);
                    if (index != -1) {
                        printf("Thong tin sinh vien:\n");
                        displayStudent(student[index]);
                    } else {
                        printf("Khong tim thay sinh vien.\n");
                    }
                } else {
                    printf("Khong co sinh vien de tim kiem.\n");
                }
                break;
            }
            case 7:
                printf("Cam on da su dung chuong trinh!\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    }

    return 0;
}
