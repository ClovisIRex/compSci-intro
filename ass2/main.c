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
void HexToDec();
void BaseToDec();
void BitCount();


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
            case 4:
                HexToDec();
                break;
            case 5:
                BaseToDec();
                break;
            case 6:
                BitCount();
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
    printf("Enter a number:\n");
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

    // get initial first char from user and store in a temp buffer

    printf("Enter text:\n");
    scanf(" %c",&buffer);

    /* keep reading chars from stdin until user pressed 'Enter'. Flag is XOR'd to keep track of even/uneven
     * status instead of a counter or string length(which we are not allowed to use in this exercise)
    */

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




    // get initial first char from user and store in a temp buffer

    printf("Enter text:\n");
    scanf(" %c",&buffer);

    // keep reading chars from stdin until user pressed 'Enter'.

    while (buffer != '\n' ) {

        // If the text has anything other than lowercase Latin letters,it's invalid
        if (!(buffer >= 'a' && buffer <= 'z')) {
            isInvalidText = 1;
        }
        tempBuffer = buffer;

        scanf("%c",&buffer);

        /* As long as the text is not invalid and not ended with a backspace, check if the current char is bigger than,
         * smaller than or equal to the previous, and therefore determine the text type
        */

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

            // if we have both decreasing and increasing letters, it means the text is mixed

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

/**
 * Function Name: HexToDec
 * Input: Stdin
 * Output: Stdout
 * Function Operation: Converts Hex number from stdin to Decimal.
 *
 */
void HexToDec () {


    char buffer;
    int isInvalid = 0;



    // get initial first char from user and store in a temp buffer

    printf("Enter number:\n");
    scanf(" %c",&buffer);

    // keep reading chars from stdin until user pressed 'Enter'.

    while (buffer != '\n' ) {

        if ( (buffer >='0' && buffer <= '9') || (buffer >= 'A' && buffer <= 'F') || (buffer >= 'a' && buffer <= 'f')) {
            if (!isInvalid) {

                if (buffer >='0' && buffer <= '9') {
                    printf("%d",(buffer - '0'));
                }
                if  (buffer >= 'A' && buffer <= 'F') {
                    printf("%d",(buffer - 'A' + 10));
                }
                if  (buffer >= 'a' && buffer <= 'f') {
                    printf("%d",(buffer - 'a' + 10));
                }

            }
        } else {
            printf("Error! %c is not a valid digit in base 16\n",&buffer);
            isInvalid = 1;
        }

        scanf("%c",&buffer);
    }
    printf("\n");

}

/**
 * Function Name: BaseToDec
 * Input: Stdin
 * Output: Stdout
 * Function Operation: Checks type of a given text from stdin.
 *
 */
void BaseToDec () {}

/**
 * Function Name: BitCount
 * Input: Stdin
 * Output: Stdout
 * Function Operation: Checks type of a given text from stdin.
 *
 */
void BitCount () {
}


int main() {

    menu();

    return 0;

}