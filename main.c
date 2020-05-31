/**************************************************************************************************
 *                                                                         ___    ____
 * Main Program                                                           /   |  / __ \
 *                                                                       / /| | / /_/ /
 *                                                                      / ___ |/ ____/
 *                                                                     /_/  |_/_/
 *
 *************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tests.h"
#include "find_intersection.h"

#define MAX_LENGTH 256

/******************************************************************************
 * Main
 *****************************************************************************/
int main(int argc, char *argv[])
{
    if (argc > 1) {
        char *command = argv[1];
        if ((command[0] == '-') && (command[1] == 't')) {
            tests_all();
        }
        else {
            char *in_file_path = argv[1];
            FILE *input_file = fopen(in_file_path, "r");

            if(input_file != NULL){
                char input_string[MAX_LENGTH];
                fgets(input_string, MAX_LENGTH, input_file);
                printf("Input: %s", input_string);

                size_t size = sizeof(char) * (strlen(input_string) + 1);
                char *intersection = (char*)malloc(size);
                find_intersection(input_string, intersection);
                printf("Output: %s\n", intersection);
            }
            fclose(input_file);
        }
    }
    else {
        printf("Error, missing argument\n");
    }

    return 0;
}
