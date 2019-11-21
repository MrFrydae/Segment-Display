#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
#include <math.h>

#define boolean int
#define true 1
#define false 0

#define advanced true

#define CHARS_PER_LINE 7

typedef char *string;

typedef struct {
    char character;
    string enabled_7_bits;
    string enabled_14_bits;
} segment_def;

segment_def segments[] = {
        // Numbers
        {'0', "1110111", "11001100110011"},
        {'1', "0010010", "11111111111111"},
        {'2', "1011101", "11111111111111"},
        {'3', "1011011", "11111111111111"},
        {'4', "0111010", "11111111111111"},
        {'5', "1101011", "11111111111111"},
        {'6', "1101111", "11111111111111"},
        {'7', "1010010", "11111111111111"},
        {'8', "1111111", "11111111111111"},
        {'9', "1111011", "11111111111111"},

        // Letters
        {'A', "1111110", "11111111111111"},
        {'B', "0101111", "11111111111111"},
        {'C', "1100101", "11111111111111"},
        {'D', "0011111", "11111111111111"},
        {'E', "1101101", "11111111111111"},
        {'F', "1101100", "11111111111111"},
};

//" --------- "
//"| \  |  / |"
//"|  \ | /  |"
//" ---- ---- "
//"|  / | \  |"
//"| /  |  \ |"
//" --------- "

#define NUM_OF_SEGMENTS (sizeof(segments) / sizeof(segment_def))
#define NUM_OF_SEG_LINES 7

void process_string(string source);
void print_line(string source, int group, int line);

boolean get_segment(segment_def *segment, char character);
boolean is_segment_enabled(segment_def segment, int bit);

void print_character(char character);
void print_character_line(char character, int line);

#endif
