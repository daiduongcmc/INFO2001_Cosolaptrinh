#include <stdio.h>

int main() {
    int numStudents;
    printf("Input the number of students: ");
    scanf("%d", &numStudents);
    float scores[numStudents];
    for (int i = 0; i < numStudents; i++) {
        printf("Input the grade of student %d: ", i + 1);
        scanf("%f", &scores[i]);
    }
    float totalScore = 0;
    for (int i = 0; i < numStudents; i++) {
        totalScore += scores[i];
    }
    float averageScore = totalScore / numStudents;
    printf("The average score of the whole class is: %.2f\n", averageScore);

    return 0;
}
