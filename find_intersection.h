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
     for example: ["1, 3, 4, 7, 13", "1, 2, 4, 13, 15"]
 * Return value:
 * - returns a pointer to the intersection, a comma-separated string
 *   containing the numbers found in both arrays
 *****************************************************************************/
char* find_intersection(char *input_string);

#endif /* FIND_INTERSECTION_H */
