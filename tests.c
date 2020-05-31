/**************************************************************************************************
 *                                                                         ___    ____
 * Tests                                                                  /   |  / __ \
 *                                                                       / /| | / /_/ /
 *                                                                      / ___ |/ ____/
 *                                                                     /_/  |_/_/
 *
 *************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "find_intersection.h"

unsigned int pass = 0;
unsigned int fail = 0;
unsigned int executed = 0;

/******************************************************************************
 *
 *****************************************************************************/
static void test_result(const char *test_name, const char *output, const char *expected)
{
	if (strcmp(output, expected) == 0) {
		pass++;
		if(DEBUG >= 2) {
			printf("%s: pass\n", test_name);
		}
	}
	else {
		fail++;
		if(DEBUG >= 1) {
			printf("%s: fail - ", test_name);
		}
	}
	executed++;
}

/******************************************************************************
 * Test 1: only positive numbers
 *****************************************************************************/
static void test_1(void)
{
    char input[] = "[\"1, 3, 4, 7, 13\", \"1, 2, 4, 13, 15\"]";
    char* output = (char*)malloc(sizeof(char) * (strlen(input) + 1));

    find_intersection(input, output);
    test_result("test 1", output, "1, 4, 13");

    free(output);
}

/******************************************************************************
 * Test 2: only positive numbers
 *****************************************************************************/
static void test_2(void)
{
    char input[] = "[\"1, 3, 9, 10, 17, 18\", \"1, 4, 9, 10\"]";
    char* output = (char*)malloc(sizeof(char) * (strlen(input) + 1));
	
    find_intersection(input, output);
    test_result("test 2", output, "1, 9, 10");

    free(output);
}

/******************************************************************************
 * Test 3: includes negative numbers
 *****************************************************************************/
static void test_3(void)
{
    char input[] = "[\"-4, 1, 3, 4, 7, 13\", \"-4, -1, 1, 2, 4, 13, 15\"]";
    char* output = (char*)malloc(sizeof(char) * (strlen(input) + 1));
	
    find_intersection(input, output);
    test_result("test 3", output, "-4, 1, 4, 13");

    free(output);
}

/******************************************************************************
 * Test 4: no intersection
 *****************************************************************************/
static void test_4(void)
{
    char input[] = "[\"-4, 1, 3, 4, 7, 13\", \"-2, -1, 0, 2, 15\"]";
    char* output = (char*)malloc(sizeof(char) * (strlen(input) + 1));
	
    find_intersection(input, output);
    test_result("test 4", output, "false");

    free(output);
}

/******************************************************************************
 * Test 5: longer sequence
 *****************************************************************************/
static void test_5(void)
{
    char input[] = "[\"1, 3, 4, 9, 10, 17, 18, 22, 34, 35, 42\", \"1, 4, 9, 10, 18, 24, 34, 36\"]";
    char* output = (char*)malloc(sizeof(char) * (strlen(input) + 1));
	
    find_intersection(input, output);
    test_result("test 5", output, "1, 4, 9, 10, 18, 34");

    free(output);
}

/******************************************************************************
 *
 *****************************************************************************/
void tests_all(void)
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();

    printf("Tests Passed:   %d\n", pass);
    printf("Tests Failed:   %d\n", fail);
    printf("Tests Executed: %d\n", executed);
}
