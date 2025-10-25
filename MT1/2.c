#include <stdio.h>
#include <string.h>

typedef struct {
    int ID;
    char name[30];
    char department[20];
} Employee;

Employee fill() {
    Employee a;
    printf("\nEnter the name: ");
    scanf(" %s", a.name); // szöveg beolvasása szóközökkel

    printf("Enter the department: ");
    scanf(" %s", a.department);

    printf("Enter the ID: ");
    scanf("%d", &a.ID);

    return a;
}

void printemp(Employee i) {
    printf("\nThe name of the employee: %s", i.name);
    printf("\nThe department of the employee: %s", i.department);
    printf("\nThe ID of the employee: %d\n", i.ID);
}

int main() {
    Employee s[7];
    for (int i = 0; i < 7; i++) {
        printf("\n--- Filling employee %d ---\n", i + 1);
        s[i] = fill();
    }

    int choice = 0;
    while (choice != 3) {
        printf("\nPlease choose one from below: ");
        printf("\n1 -> List all HR employees");
        printf("\n2 -> Change the department of an employee");
        printf("\n3 -> Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n--- HR Employees ---\n");
            for (int i = 0; i < 7; i++) {
                if (strcmp(s[i].department, "HR") == 0) {
                    printemp(s[i]);
                }
            }
        }

        else if (choice == 2) {
            int lookfor;
            printf("\nPlease enter the ID of the employee: ");
            scanf("%d", &lookfor);

            int found = 0;
            for (int i = 0; i < 7; i++) {
                if (s[i].ID == lookfor) {
                    found = 1;
                    printf("Enter the new department: ");
                    scanf(" %s", s[i].department);
                    printf("Department updated successfully!\n");
                    break;
                }
            }
            if (!found)
                printf("Employee with ID %d not found.\n", lookfor);
        }

        else if (choice != 3) {
            printf("Invalid choice, please try again.\n");
        }
    }

    printf("\nExiting program.\n");
    return 0;
}