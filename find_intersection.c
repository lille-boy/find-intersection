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

/******************************************************************************
 *
 *****************************************************************************/
char* find_intersection(char *input_string)
{
    size_t size = sizeof(char) * (strlen(input_string) + 1);
    char *array1 = (char*)malloc(size);
    char *array2 = (char*)malloc(size);
    char *intersection = (char*)malloc(size);
    intersection[0] = '\0';

    if (DEBUG > 0) {
        printf("Input string: %s", input_string);
    }

    /* Extract first array */
    const char delimiter[2] = "\"";
    char *token = strtok(input_string, delimiter);
    if (token != NULL) {
        token = strtok(NULL, delimiter);
        if (token != NULL) {
            strcpy(array1, token);
            if (DEBUG > 1) {
                printf("array1: %s\n", array1);
            }
        }
    }

    /* Extract second array */
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        token = strtok(NULL, delimiter);
        if (token != NULL) {
            strcpy(array2, token);
            if (DEBUG > 1) {
                printf("array2: %s\n", array2);
            }
        }
    }

    /* Find intersection */
    if ((token = strtok(array2, " ,")) != NULL) {
        char *occurence = strstr(array1, token);
        if (occurence != NULL) {
            strcpy(intersection, token);
        }

        while( (token = strtok(NULL, " ,")) != NULL) {
            char *occurence = strstr(array1, token);
            if (occurence != NULL) {
                strcat(intersection, ",");
                strcat(intersection, token);
            }
        }
    }

    if (intersection[0] == '\0') {
        /* No intersection found */
        intersection = "false";
    }

    if (DEBUG > 0) {
        printf("intersection: %s\n", intersection);
    }

    return intersection;
}
