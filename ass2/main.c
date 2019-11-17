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
    int square_size = 2* number +1;

    if (square_size == 1) {
        printf("X \n");
        return;
    }

    for (int i = 0; i < square_size; i++) {
        for (int j = 0; j < square_size; j++) {
            if (i==0 || i==square_size-1) {
                if (j==0 || j==square_size-1) {
                    printf("+");
                } else {
                    printf("-");
                }
            } else {

                if (j == 0 || j==square_size-1) {
                    printf("|");
                } else if (j == (square_size-1)/2  && i == (square_size-1)/2) {
                    printf("X");
                } else if(square_size != NO_DIAGONAL_SIZE) {
                    if (j==i) {
                        printf("\\");
                    } else if (j == square_size-i-1){
                        printf("/");
                    } else {
                        printf(" ");
                    }
                }

                else {
                    printf(" ");
                }


            }
        }
        printf("\n");
    }

}


void main() {

    menu();

}