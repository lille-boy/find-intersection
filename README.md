# Find Intersection

## Goal
Have the function `find_intersection(input_string)` read the array of strings stored in
`input_string` which will contain 2 elements: the first element will represent a list of
comma-separated numbers sorted in ascending order, the second element will represent a second list
of comma-separated numbers (also sorted). Your goal is to return a comma-separated string
containing the numbers that occur in elements of `input_string` in sorted order. If there is no
intersection, return the string `false`.

For example: if `input_string` contains `["1, 3, 4, 7, 13", "1, 2, 4, 13, 15"]` the output should
return "1, 4, 13" because those numbers appear in both strings. The array given will not be empty,
and each string inside the array will be of numbers sorted in ascending order and may contain
negative numbers.

## Examples
```
Input: ["1, 3, 4, 7, 13", "1, 2, 4, 13, 15"]
Output: 1, 4, 13
```
```
Input: ["1, 3, 9, 10, 17, 18", "1, 4, 9, 10"]
Output: 1, 9, 10
```
## Build
`make`

## Execute
The array of strings is stored in a file array.txt.
`./find_intersection array.txt`

Executing all tests returns the number of tests passed, failed and executed.
`./find_intersection -t`
