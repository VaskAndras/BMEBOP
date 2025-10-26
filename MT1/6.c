# include <stdio.h>
#include <string.h>

typedef struct {
    char flight_no[8];
    char origin[30];
    char destination[30];
    int seats; 
}Flight;

void print_flight(Flight a){
    printf("\n The flight:");
    printf("\n origin: %s", a.origin );
    printf("\n destination: %s", a.destination);
    printf("\n flight number: %s", a.flight_no);
    printf("\n Available seats: %d", a.seats);
}

Flight scan_flight(){
    Flight a;
    printf("\n Please enter the following atributes of the flight:");
    printf("\n origin:");
    scanf("%s", a.origin);
    printf("\n destination:");
    scanf("%s", a.destination);
    printf("\n flight number:");
    scanf("%s", a.flight_no);
    printf("\n Available seats:");
    scanf("%d", &a.seats);
    printf("\n");

    return a;
}


int main(){
    Flight a[10];
    
    for (int i = 0; i < 10; i++){
        a[i] = scan_flight();
    }

    int menu = 0;
    while (menu != 3){
        printf("\n\n --- Menu --- \n If you want to see the available flights, type: 1 \n If you want to update the seats, type: 2 \n");
        if (scanf("%d", &menu) != 1 || menu > 3 || menu < 1){
            printf("\nInvalid input, try again\n"); 
        }
        if (menu == 1){
            for (int i = 0; i < 10; i++){
                if (a[i].seats > 0){
                    print_flight(a[i]);
                }
            }
        }
        if (menu == 2 ){
            printf("\n Which flight would you like to change?\n");
            char input[8];
            scanf("%s", input);
            int index;
            for (int i = 0; i < 10; i++){
                if (strcmp(a[i].flight_no, input) == 0){
                    index = i;
                }
            }
            printf("\nEnter the new number of seats\n");
            scanf("%d", &a[index].seats);
        }
    }
    return 0;
}
