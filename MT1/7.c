#include <stdio.h>
#include <string.h>

typedef struct {
    char title[61];   // max 60 karakter + null terminátor
    char artist[41];  // max 40 karakter + null terminátor
    int year;
} Exhibit;

int main() {
    Exhibit exhibits[7];
    int i, choice;

    // Beolvasás 7 kiállításra
    printf("Enter data for 7 exhibits:\n");
    for(i = 0; i < 7; i++) {
        printf("\nExhibit %d:\n", i + 1);

        printf("Title: ");
        scanf(" %60[^\n]", exhibits[i].title);

        printf("Artist: ");
        scanf(" %40[^\n]", exhibits[i].artist);

        printf("Year: ");
        scanf("%d", &exhibits[i].year);
    }

    // Menü
    printf("\nMenu:\n");
    printf("1 - List 2017 exhibits\n");
    printf("2 - Update year\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nExhibits from 2017:\n");
        for(i = 0; i < 7; i++) {
            if(exhibits[i].year == 2017) {
                printf("Title: %s | Year: %d\n", exhibits[i].title, exhibits[i].year);
            }
        }
    }
    else if(choice == 2) {
        char searchTitle[61];
        int newYear, found = 0;

        printf("\nEnter the title of the exhibit to update: ");
        scanf(" %60[^\n]", searchTitle);

        for(i = 0; i < 7; i++) {
            if(strcmp(exhibits[i].title, searchTitle) == 0) {
                printf("Enter new year: ");
                scanf("%d", &newYear);
                exhibits[i].year = newYear;
                printf("Year updated successfully.\n");
                found = 1;
                break;
            }
        }

        if(!found) {
            printf("Exhibit not found.\n");
        }
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}