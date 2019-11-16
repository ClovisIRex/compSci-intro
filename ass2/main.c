/*******************
 * Tal Livny
 * 316306091
 * 01
 * ass2
 *******************/


#include <stdio.h>


void menu();
void drawSquare();

void menu() {
    #define EXIT_OPTION 0

    int menu_option;

    do {

        printf("Choose an option: \n");
        printf("1: Draw\n");
        printf("2: Even or Odd\n");
        printf("3: Text type\n");
        printf("4: Hex to Dec\n");
        printf("5: Base to Dec\n");
        printf("6: Count bits\n");
        printf("0: Exit \n");
        scanf("%d",&menu_option);

        switch (menu_option) {

            case EXIT_OPTION:
                break;

            case 1:
                drawSquare();
                break;

            default:
                printf("Wrong option! \n");
        }
    } while( menu_option != EXIT_OPTION );


    return;
}

void drawSquare () {
    #define NO_DIAGONAL_SIZE 3

    int number;
    printf("Enter Size:\n");
    scanf("%d", &number);
    int square_size = 2 * number + 1;

    void drawSquareFrame();

    if (square_size == 1) {
        printf("X \n");
        return;
    }

    for (int i = 0; i < square_size; i++) {
        if ( i == 0) {
            printf("+");

            for (int j = 0; j < square_size; j++) {
                printf("-");
            }
            printf("+\n");
        }

        for (int j = 0; j < square_size; j++) {
            if (square_size != NO_DIAGONAL_SIZE) {

                if (i ==1) {
                    if (j == square_size-i + 1) {
                        printf("/");
                    }
                }

                if (i ==square_size-2) {
                    if (j == square_size-i +1) {
                        printf("\\");
                    }
                }

                if (j == square_size/2 + 1 && i == square_size/2) {
                    printf("X");
                } else if (j == i+1) {
                    printf("\\");
                } else if (j == square_size-i) {
                    printf("/");
                } else if (j == 0) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
        }

        printf(" |");


        if (i == square_size-1) {
            printf("\n+");

            for (int j = 0; j < square_size; j++) {
                printf("-");
            }
            printf("+\n");
        }

        printf("\n");
    }

}


void main() {

    menu();

}