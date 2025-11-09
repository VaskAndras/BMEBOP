#include <stdio.h>
#include <string.h>

typedef struct Date {
    int year, month, day;
} Date;

typedef struct Competitor {
    char name[31];
    Date birth;
    int rank;
} Competitor;

void Date_print(Date d){
    printf("%04d-%02d-%02d\n", d.year, d.month, d.day);
} //these are just declarations, you can complete the functions below!

Competitor Competitor_read(){
    Competitor c;
    printf("Enter competitor's name (max 30 chars): ");
    scanf(" %30[^\n]", c.name); // read until newline or max 30 chars
    printf("Enter birth date (year month day): ");
    scanf("%d %d %d", &c.birth.year, &c.birth.month, &c.birth.day);
    printf("Enter rank: ");
    scanf("%d", &c.rank);
    return c;
}

void Competitor_print(Competitor c){
    printf("Name: %s\n", c.name);
    printf("Birth Date: ");
    Date_print(c.birth);
    printf("Rank: %d\n", c.rank);
}

int main() {
    Competitor competitors[6] = {
        { "Am, Erica", {1984, 5, 6}, 1 },
        { "Abnorm, Al", {1982, 9, 30}, 3 },
        { "Pri, Mary", {1988, 8, 25}, 2 },
        { "Duck, Ling", {1979, 6, 10}, 5 },
        { "Mac, Donald", {1992, 4, 5}, 4 },
    };

    /* name of competitor 0 - printf %s */
    printf("Name of competitor 0: %s\n", competitors[0].name);
    /* rank of competitor 2 */
    printf("Rank of the competitor 2: %d\n", competitors[2].rank);
    /* birth date of competitor 4, use the given function */
    printf("Birth date of competitor 4: ");
    Date_print(competitors[4].birth);
    /* the first letter of the name of competitor 1 (a string is an array of characters) */
    printf("First letter of the name of competitor 1: %c\n", competitors[1].name[0]);
    /* is competitor 1 among the best three? yes/no, may use ?: operator */
    printf("Is competitor 1 among the best three? %s\n", (competitors[1].rank <= 3) ? "yes" : "no");
    /* is competitor 4 faster than competitor 3? */
    printf("Is competitor 4 is faster than competitor 3?", (competitors[4].rank < competitors[3].rank) ? "yes" : "no");
    /* was competitor 1 born in the same year as competitor 2? */
    printf("Was competritor 1 bon in the same zear as competitor 2?", (competitors[1].birth.year == competitors[2].birth.year) ? "yes" : "no");
    /* complete the Competitor_print() function,
     * then print all data of competitor 1 */
    printf("Data of competitor 1:\n");
    Competitor_print(competitors[1]);
    // Check if Abnorm, Al was competeing (using strcmp())
    if (strcmp(competitors[1].name, "Abnorm, Al") == 0) {
        printf("Abnorm, Al was competing.\n");
    } else {
        printf("Abnorm, Al was not competing.\n");
    }

    /* Create a function to add a new competitor according to user's input (using scanf)*/
    competitors[5] = Competitor_read();
    /*Add a new competitor as 6th element (index 5)*/
    printf("Data of the new competitor:\n");
    Competitor_print(competitors[5]);
    /* at last print all data of all competitors. */
    printf("All competitors:\n");
    for (int i = 0; i < 6; i++) {
        printf("Competitor %d:\n", i + 1);
        Competitor_print(competitors[i]);
    }

    return 0;
}

