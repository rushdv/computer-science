#include <stdio.h>

int main() {
    int marks;
    printf("Enter your marks (0-100): ");
    scanf("%d", &marks);

    // Check for valid input
    if (marks < 0 || marks > 100) {
        printf("Invalid marks entered.\n");
        return 0;
    }

    int grade = marks / 10;  // Create grade band

    switch (grade) {
        case 10:
        case 9:
        case 8:
            printf("Grade: A\nGrade Point: 4.0\n");
            break;
        case 7:
            printf("Grade: B\nGrade Point: 3.0\n");
            break;
        case 6:
            printf("Grade: C\nGrade Point: 2.0\n");
            break;
        case 5:
            printf("Grade: D\nGrade Point: 1.0\n");
            break;
        default:
            printf("Grade: F\nGrade Point: 0.0\n");
    }

    return 0;
}
