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
 * Output: 'boolean' int: true(1) or false(0)
 * Function Operation: Checks if the number to be powered on is 0 powered by a negative exponent
 * @param base : double
 * @param exponent : int
 * @return number: int
 */
int isBaseZeroAndNegativeExponent(double base, int exponent) {
    counter++;
    return base == 0 && exponent < 0 ? 1 : 0;
}

/**
 * Function Name: recEffiPow
 * Input: 2 numbers, one base(double) and one exponent(int) to power to
 * Output: the base powered by the exponent( base ^ exponent)
 * Function Operation: Powers the base by usage of an efficient recursion algorithm
 * @param base : double
 * @param exponent : int
 * @return number: double
 */
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
 * Function Operation: Powers the base by usage of a naive recursion algorithm
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

 /**
  * Function Name: isPermutation
  * Input: 2 arrays of ints, 2 sizes of each corresponding array(int)
  * Output: 'boolean' int: true(1) or false(0)
  * Function Operation: checks if both arrays are permutations of one another
  * @param arr1
  * @param size1
  * @param arr2
  * @param size2
  * @return
  */
int isPermutation(int arr1[], int size1, int arr2[], int size2) {

    int sum1 = 0;
    int sum2 = 0;
    int zeroCount1 = 0;
    int zeroCount2 = 0;
    int mul1 = 1;
    int mul2 = 1;

    // if the sizes of the arrays are not equal, it cannot be a permutation by definition

    if (size1 != size2) {
        return 0;
    }

    /*
      sum up and multiply all first array values which are not zero (counting zero in will hurt the result),
      count number of zero's separately
     */

     for (int i = 0; i < size1; i++) {
         counter++;

         if (arr1[i] != 0) {
             sum1 += arr1[i];
             mul1 *= arr1[i];
         } else {
             zeroCount1++;
         }
     }

     /*
      sum up and multiply all second array values which are not zero (counting zero in will hurt the result),
      count number of zero's separately
     */

     for (int i = 0; i < size2; i++) {
         counter++;

         if (arr2[i] != 0) {
             sum2 += arr2[i];
             mul2 *= arr2[i];
         } else {
             zeroCount2++;
         }
     }

     /* Permutation can be defined when the sum and multiplication are equal for all values different from zero
        for both arrays (arrays must have the same number of values,each value can be matched
        by a single equal value from the second array).

        if any of the arrays have zero's in them, we must compare the number of zero's
        in order to see if it matches across both arrays. if the don't match,
        it's not a permutation (each value must be equal to ONE and only ONE value of the second array,
        a value without it's equal pair is illegal in permutations. Since it's a zero,
        we cannot compute it normally in sums and multiplication, only separately.

        if no zero's are present, we can just compare both the sum and multiplication values normally.

        e.g {0,2} and {2,0} are permutations, but not {0,0,2) and {2,0}
     */

     if (zeroCount1 > 0 || zeroCount2 > 0) {
         return (sum1 == sum2) && (mul1 == mul2) && (zeroCount1 == zeroCount2);
     }

     return (sum1 == sum2) && (mul1 == mul2);



}

void printArr2D(int arr[][MAX], int rows, int columns) {
}

