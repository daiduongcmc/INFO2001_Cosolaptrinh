#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    char author[100];
    float price;
} Book;

int main() {
    int n;
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    Book *books = (Book *)malloc(n * sizeof(Book));
    if (books == NULL) {
        printf("Khong the cap phat bo nho dong!\n");
        return 0;
    }
    printf("Nhap thong tin sach:\n");
    for (int i = 0; i < n; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ten sach: ");
        scanf("%s", books[i].title);
        printf("Ten tac gia: ");
        scanf("%s", books[i].author);
        printf("Gia sach: ");
        scanf("%f", &books[i].price);
    }
    printf("\nThong tin sach:\n");
    for (int i = 0; i < n; i++) {
        printf("Sach %d:\n", i + 1);
        printf("Ten sach: %s\n", books[i].title);
        printf("Ten tac gia: %s\n", books[i].author);
        printf("Gia sach: %.2f\n", books[i].price);
        printf("\n");
    }
    free(books);
    return 0;
}
