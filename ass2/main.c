/*******************
 * Tal Livny
 * 316306091
 * 01
 * ass2
 *******************/


#include <stdio.h>


void menu();
void drawSquare();
void isEvenTextLength();
void CheckTextType();


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

            case 2:
                isEvenTextLength();
                break;

            case 3:
                CheckTextType();
                break;

            default:
                printf("Wrong option! \n");
        }
    } while( menu_option != EXIT_OPTION );


    return;
}



/**
 * Function Name: drawSquare
 * Input: Stdin
 * Output: Stdout
 * Function Operation: Draws a x*x square according to a number received by user Input. If the size is 3, the square has no diagonal lines.
 * If the square is size 1, the function draws only 'X'.
 */
void drawSquare () {
    #define NO_DIAGONAL_SIZE 3
    int number;

    // get square size by 2 * input + 1
    printf("Please Enter Size:\n");
    scanf("%d", &number);
    int square_size = 2* number +1;

    if (square_size == 1) {
        printf("X \n");
        return;
    }

    // draws square matrix with 2 loops, outer for rows ,inner for columns

    for (int i = 0; i < square_size; i++) {

        // First and last rows
        for (int j = 0; j < square_size; j++) {
            if (i==0 || i==square_size-1) {
                if (j==0 || j==square_size-1) {
                    printf("+");
                } else {
                    printf("-");
                }
            } else {

                // side frames

                if (j == 0 || j==square_size-1) {
                    printf("|");

                    //Middle of square
                } else if (j == (square_size-1)/2  && i == (square_size-1)/2) {
                    printf("X");

                    // Diagonal lines, none if square is 3*3
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


/**
 * Function Name: isEven
 * Input: Stdin
 * Output: Stdout
 * Function Operation: Checks if a given text from stdin is of even or odd length.
 *
 */
void isEvenTextLength () {

    char buffer;
    int flag = 0;

    //get inital first char from user and store in a temp buffer

    printf("Please Enter Text:\n");
    scanf(" %c",&buffer);

    // keep reading chars from stdin until user pressed 'Enter'. Flag is XOR'd to keep track of even/uneven
    // status instead of a counter or string length(which we are not allowed to use in this exercise)

    while( buffer != '\n' ) {
        scanf("%c",&buffer);
        flag ^= 1;
    };

    if (flag == 0) {
        printf("Your text's length is even\n");
    } else {
        printf("Your text's length is odd\n");
    }

}

/**
 * Function Name: CheckTextType
 * Input: Stdin
 * Output: Stdout
 * Function Operation: Checks type of a given text from stdin.
 *
 */
void CheckTextType () {

    char buffer,tempBuffer;
    int isInvalidText = 0;
    int isIncreasingText = 0;
    int isDecreasingText = 0;
    int isConstantText = 0;
    int isMixedText = 0;




    //get inital first char from user and store in a temp buffer

    printf("Please Enter Text:\n");
    scanf(" %c",&buffer);

    // keep reading chars from stdin until user pressed 'Enter'.

    while (buffer != '\n' ) {

        if (!(buffer >= 'a' && buffer <= 'z')) {
            isInvalidText = 1;
        }
        tempBuffer = buffer;

        scanf("%c",&buffer);

        if (!isInvalidText && buffer != '\n') {

            if (buffer > tempBuffer) {
                isIncreasingText = 1;
                isConstantText = 0;
            }

            if (buffer < tempBuffer) {
                isDecreasingText = 1;
                isConstantText = 0;

            }

            if (buffer == tempBuffer) {
                isConstantText = 1;
            }

            if (isIncreasingText && isDecreasingText) {
                isMixedText = 1;
            }

        }


    };

    if (isInvalidText) {
        printf("Your text is invalid\n");
    } else if (isMixedText) {
        printf("Your text is mixed\n");
    } else {
        if (isIncreasingText) {
            printf("Your text is increasing\n");
        } else if (isDecreasingText) {
            printf("Your text is decreasing\n");
        } else if (isConstantText) {
            printf("Your text is constant\n");
        }
    }



}

void main() {

    menu();

}