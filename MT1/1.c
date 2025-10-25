#include <stdio.h>
#include <string.h>

typedef struct{
    int ID;
    char name[30];
    char department[20];
}Employee;

Employee fill(){
    Employee a;
    printf("\n enter the name:");
    scanf("%s", a.name);
    printf("\n enter the department:");
    scanf("%s", a.department);
    printf("\n enter the ID:");
    scanf("%d" ,&a.ID);
    return a;
}

void printemp(Employee i){
    printf("\n The name of the employee: %s ", i.name);
    printf("\n The department of the employee: %s ", i.department);
    printf("\n The ID of the employee: %d ", i.ID);    
}

int main(){
    Employee s[7];
    for (int i = 0; i < 7; i++){
        s[i] = fill();
    }
    int choice = 0;
    while (choice != 3){
        printf("\n Pelase choose one frome below: ");
        printf("\n For changeing the department of an employee write --> 1");
        printf("\n For listing the HR employees write --> 2");
        printf("\n For exit write --> 3");
        
        if (scanf("%d", &choice) != 1){
            printf("Invalid input");
            choice = 0;
            break;
        }
        if (choice == 1){
            for (int i = 0; i < 7; i++){
            if (s[i].department[0] == 'H' && s[i].department[1] == 'R'){
                    printemp(s[i]);
                }
            }
        }
        if(choice == 2){
            printf("\n Please enter the ID if the employee");
            int lookfor;
            scanf("%d", &lookfor);
            for (int i = 0; i < 7; i++){
                if(s[i].ID == lookfor){
                    printf("For what would you change for the department?");
                    char changefor[30];
                    scanf("%s", changefor);
                    strcpy(s[i].department, changefor);
                    break;
                }
            }
        }
    } 
 return 0;
} 
