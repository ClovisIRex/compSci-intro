/********************
    * Tal Livny
    * 316306091
    * 01
    * ass3
    * 30/11/2019
*********************/

#include "ass3.h"
#include <stdio.h>
#include <math.h>

const int INFINITY_NUMBER = 1.0/0;
int counter = 0;

/**
 * Function Name: isBaseZeroAndNegativeExponent
 * Input: 2 numbers, one base(double) and one exponent(int) to power to
 * Output: true(1) or false(0)
 * Function Operation: Checks if the number to be powered on is 0 powered by a negative exponent
 * @param base : double
 * @param exponent : int
 * @return number: int
 */
int isBaseZeroAndNegativeExponent(double base, int exponent) {
    return base == 0 && exponent < 0 ? 1 : 0;
}


double recEffiPow(double base, int exponent) {
    counter++;

    double result;
    double pow;

    // return "Infinity" if the base is 0 the negative exponent

    if (isBaseZeroAndNegativeExponent(base, exponent)) {
        return INFINITY_NUMBER;
    }

    if (exponent == 1) {
        return base;
    }

    if (exponent != 0) {

        /* recursion stops when the exponent reaches 1 after dividing by 2 log2(n)
           times(n is the inputted exponent value) , complexity is Olog2(n)
        */

        pow = recEffiPow(base, exponent / 2);

        /* if the exponent is even we can apply the efficient algorithm normally
           (multiply by the result instead of calling the function n times for efficiency)
         */

        if ( exponent % 2 == 0) {
            result = pow * pow;
        } else {

            // if the exponent is odd we need to multiply by the double base to get an accurate number(exponent is int)
            result = base * pow * pow;
        }

        return result;
    }

    return 1;


}

/**
 * Function Name: recPow
 * Input: 2 numbers, one base(double) and one exponent(int) to power to
 * Output: the base powered by the exponent( base ^ exponent)
 * Function Operation: Powers the base by usage of a naive recursion
 * @param base : double
 * @param exponent : int
 * @return number: double
 */
double recPow(double base, int exponent) {
    counter++;

    // return "Infinity" if the base is 0 the negative exponent

    if (isBaseZeroAndNegativeExponent(base, exponent)) {
        return INFINITY_NUMBER;
    }

    if (exponent != 0)

        /* recursion stops when the exponent reaches 0 after subtracting 1 n
           times(n is the inputted exponent value), complexity is O(n+1)
        */

        return (base*recPow(base, exponent-1));
    else
        return 1;

}
/**
 * Function Name: iterPow
 * Input: 2 numbers, one base(double) and one exponent(int) to power to
 * Output: the base powered by the exponent( base ^ exponent)
 * Function Operation: Powers the base by iterating in a loop and multiplying it n(exponent) times
 * @param base : double
 * @param exponent : int
 * @return number: double
 */
double iterPow(double base, int exponent) {
    double power = 1;

    if (isBaseZeroAndNegativeExponent(base, exponent)) {
        return INFINITY_NUMBER;
    }

    /* loop stops when the i range reaches n after adding 1 n
           times(n is the inputted exponent value), complexity is O(n)
    */

    for (int i = 1; i <= exponent; i++) {
        counter++;
        power *= base;
    }

    return power;
}

int isPermutation(int arr1[], int size1, int arr2[], int size2) {
}

void printArr2D(int arr[][MAX], int rows, int columns) {
}

