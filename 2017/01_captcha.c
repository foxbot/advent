#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fail(const char* reason, ...);
int* parseInput(const char* chars, const int len);
int* parsePart(const char* chars);

void main(int argc, char *argv[]) {
    if (argc != 3) {
        fail("USAGE: captcha <captcha> <part>\n");
    }

    char* chars = argv[1];
    int len = strlen(chars);
    if (len % 2 != 0) {
        fail("ERROR: input string must contain an even quantity of numbers");
    }
    int* nums = parseInput(chars, len);
    int* part = parsePart(argv[2]);

    int distance;
    if (*part == 1) distance = 1;
    else {
        distance = len / 2;
    }

    int counter = 0;

    int i;
    for (i = 0; i < len; i++) {
        int cur = nums[i];
        // nums is a circular list
        int nextPos = i+distance;
        if (nextPos >= len) nextPos-=len;
        int next = nums[nextPos];

        if (cur == next) {
            counter += cur;
        }
    }

    printf("%d\n", counter);
}

// Parse a single string into an int[]
int* parseInput(const char* chars, const int len) {
    int* nums = malloc(len * sizeof(int));

    int i;
    for (i = 0; i < len; i++) {
        char c = chars[i];
        if (c < '0' || c > '9') {
            fail("ERROR: invalid char in captcha: %c\n", c);
        }
        nums[i] = c - '0';
    }

    return nums;
}
int* parsePart(const char* chars) {
    int* number = malloc(sizeof(int));
    int len = strlen(chars);
    if (len != 1 || (chars[0] < '1' || chars[0] > '2')) {
        fail("ERROR: part must be one of '1' or '2'");
    }
    *number = chars[0] - '0';
    return number;
}

void fail(const char* reason, ...) {
    va_list args;
    va_start (args, reason);
    vprintf (reason, args);
    va_end (args);
    
    exit(-1);
}