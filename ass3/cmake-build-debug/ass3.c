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
 * Function Name: isPowerInifinty
 * Input: 2 numbers, one base(double) and one exponent(int) to power to
 * Output: true(1) or false(0)
 * Function Operation: Checks if the number to be powered on is 0 powered by a negative exponent
 * @param base : double
 * @param exponent : int
 * @return number: int
 */
int isPowerInifinty(double base, int exponent) {
    return base == 0 && exponent < 0 ? 1 : 0;
}


double recEffiPow(double base, int exponent) {
    counter++;

    if (isPowerInifinty(base,exponent)) {
        return INFINITY_NUMBER;
    }

    double power;

    if (exponent != 0) {
        if (exponent % 2 ==0) {
            power = recEffiPow(base,exponent/2);
            return power * power;

        } else {
            return base * power * power;
        }
    } else {
        return 1;
    }


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

    if (isPowerInifinty(base,exponent)) {
        return INFINITY_NUMBER;
    }

    if (exponent != 0)
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

    if (isPowerInifinty(base,exponent)) {
        return INFINITY_NUMBER;
    }

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

