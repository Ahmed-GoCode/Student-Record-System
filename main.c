#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

// Student structure
struct Student {
    int rollNumber;
    char name[50];
    int age;
    float marks;
    char grade;
};

// Function prototypes
void addStudent(struct Student students[], int *count);
void displayStudents(const struct Student students[], int count);
char calculateGrade(float marks);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    printf("=== Simple Student Record System ===\n");

    do {
        printf("\n1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Choose option (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

void addStudent(struct Student students[], int *count) {
    if(*count >= MAX_STUDENTS) {
        printf("Database full! Maximum %d students.\n", MAX_STUDENTS);
        return;
    }

    printf("\n--- Add Student %d ---\n", *count + 1);
    printf("Roll Number: ");
    scanf("%d", &students[*count].rollNumber);

    printf("Name: ");
    getchar(); // Clear input buffer
    fgets(students[*count].name, 50, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &students[*count].age);

    printf("Marks: ");
    scanf("%f", &students[*count].marks);

    students[*count].grade = calculateGrade(students[*count].marks);

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(const struct Student students[], int count) {
    if(count == 0) {
        printf("No students in database!\n");
        return;
    }

    printf("\n=== Student Records ===\n");
    printf("--------------------------------------------\n");
    printf("Roll No.  Name           Age  Marks  Grade\n");
    printf("--------------------------------------------\n");

    for(int i = 0; i < count; i++) {
        printf("%-9d %-14s %-4d %-6.1f %c\n",
               students[i].rollNumber,
               students[i].name,
               students[i].age,
               students[i].marks,
               students[i].grade);
    }
    printf("--------------------------------------------\n");
}

char calculateGrade(float marks) {
    if(marks >= 90) return 'A';
    else if(marks >= 80) return 'B';
    else if(marks >= 70) return 'C';
    else if(marks >= 60) return 'D';
    else return 'F';
}