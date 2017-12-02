#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fail(const char* reason, ...);
int* parseInput(const char* chars, const int len);

void main(int argc, char *argv[]) {
    if (argc != 2) {
        fail("USAGE: captcha <captcha>\n");
    }

    char* chars = argv[1];
    int len = strlen(chars);
    int* nums = parseInput(chars, len);

    int counter = 0;

    int i;
    for (i = 0; i < len; i++) {
        int cur = nums[i];
        // nums is a circular list
        int next = i != len-1 ? nums[i+1] : nums[0];

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

void fail(const char* reason, ...) {
    va_list args;
    va_start (args, reason);
    vprintf (reason, args);
    va_end (args);
    
    exit(-1);
}