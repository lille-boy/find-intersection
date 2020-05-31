/**************************************************************************************************
 *                                                                         ___    ____
 * Find the intersection of two arrays                                    /   |  / __ \
 *                                                                       / /| | / /_/ /
 *                                                                      / ___ |/ ____/
 *                                                                     /_/  |_/_/
 *
 *************************************************************************************************/
#ifndef FIND_INTERSECTION_H
#define FIND_INTERSECTION_H

#define DEBUG 0

/******************************************************************************
 * Description:
 * - finds the intersection between 2 arrays.
 * Parameter:
 * - input_string contains two arrays. The format is ["array1", "array2"],
 *   for example: ["1, 3, 4, 7, 13", "1, 2, 4, 13, 15"]
 * - intersection: pointer to the intersection, a comma-separated string
 *   that containa the numbers found in both arrays
 * Return value:
 * - none
 *****************************************************************************/
void find_intersection(char *input_string, char *intersection);

#endif /* FIND_INTERSECTION_H */
