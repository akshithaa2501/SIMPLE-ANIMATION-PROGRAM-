#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep()

#ifdef _WIN32
    #include <conio.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif

void animateVehicle(char vehicle[][40], int rows) {
    int i, j;
    
    for (i = 0; i < 40; i++) {  // Move vehicle across the screen
        system(CLEAR_SCREEN);
        
        int row,j;
        for (row = 0; row < rows; row++) {
            for (j = 0; j < i; j++) {
                printf(" ");  // Move the vehicle to the right
            }
            printf("%s\n", vehicle[row]);  // Print vehicle row by row
        }

        usleep(100000);  // Delay for smooth animation
    }
}

void displayMenu() {
    printf("Select a vehicle to animate:\n");
    printf("1. Car\n");
    printf("2. Truck\n");
    printf("3. Bike\n");
    printf("4. Bus\n");
    printf("5. Train\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    
    char car[][40] = {
        "     ______",
        "  _/  |\\",
        " | _     _   -'",
        "'(o)------(o)'"
    };

    char truck[][40] = {
        "      __________",
        " ___||\\_",
        "|[]|",
        " (o) ____________ (o)"
    };

    char bike[][40] = {
        "      ,o ",
        "    -o-/  ",
        "  /      \\ ",
        " (o)------(o) "
    };

    char bus[][40] = {
        "  ____________________",
        " | []  []  []  []  []|",
        " ||",
        "    O              O"
    };

    char train[][40] = {
        "      [=======]",
        " [========(O)=========]",
        "  |     TRAIN     |",
        "  (o)--------- (o)"
    };

    displayMenu();
    scanf("%d", &choice);

    printf("Starting animation...\n");
    sleep(2);  // Delay before animation starts

    switch (choice) {
        case 1:
            animateVehicle(car, 4);
            break;
        case 2:
            animateVehicle(truck, 4);
            break;
        case 3:
            animateVehicle(bike, 4);
            break;
        case 4:
            animateVehicle(bus, 4);
            break;
        case 5:
            animateVehicle(train, 4);
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            return 1;
    }

    printf("\nAnimation Complete!\n");
    return 0;
}
