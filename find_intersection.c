/**************************************************************************************************
 *                                                                         ___    ____
 * Find the intersection of two arrays                                    /   |  / __ \
 *                                                                       / /| | / /_/ /
 *                                                                      / ___ |/ ____/
 *                                                                     /_/  |_/_/
 *
 *************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "find_intersection.h"

const char delimiter[2] = "\"";

/******************************************************************************
 * Function that extracts one array from the input string
 *****************************************************************************/
static void extract_array(char *token, char *array)
{
    if (token != NULL) {
        token = strtok(NULL, delimiter);
        if (token != NULL) {
            strcpy(array, token);
            if (DEBUG > 1) {
                printf("array: %s\n", array);
            }
        }
    }
}

/******************************************************************************
 * Function that finds the numbers that appear in both input arrays
 *****************************************************************************/
void find_intersection(char *input_string, char *intersection)
{
    size_t size = sizeof(char) * (strlen(input_string) + 1);
    char *array1 = (char*)malloc(size * sizeof(char));
    char *array2 = (char*)malloc(size * sizeof(char));

    intersection[0] = '\0';

    if (DEBUG > 0) {
        printf("Input string: %s ", input_string);
    }

    /* Extract first array */
    char *token = strtok(input_string, delimiter);
    if (array1 != NULL) {
        extract_array(token, array1);

        /* Extract second array */
        token = strtok(NULL, delimiter);
        if (array2 != NULL) {
            extract_array(token, array2);

            /* Find intersection */
            if ((token = strtok(array2, ", ")) != NULL) {
                if (strstr(array1, token) != NULL) {
                    strcpy(intersection, token);
                }
                while( (token = strtok(NULL, ", ")) != NULL) {
                    if (strstr(array1, token) != NULL) {
                        if (intersection[0] == '\0') {
                            strcpy(intersection, token);
                        }
                        else {
                            strcat(intersection, ", ");
                            strcat(intersection, token);
                        }
                    }
                }
            }
            free(array2);
        }
        free(array1);
    }

    /* No intersection found */
    if (intersection[0] == '\0') {
        memcpy(intersection, "false", 6);
    }

    if (DEBUG > 0) {
        printf("intersection: %s\n", intersection);
    }
}
