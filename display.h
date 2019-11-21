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

typedef char *string;

typedef struct {
    char character;
    string enabled_7_bits;
    string enabled_14_bits;
} segment_def;

segment_def segments[] = {
        // Numbers
        {'0', "1110111", "11001100110011"},
        {'1', "0010010", "00001100000010"},
        {'2', "1011101", "10000111100001"},
        {'3', "1011011", "10000101000011"},
        {'4', "0111010", "01000111000010"},
        {'5', "1101011", "11000011000011"},
        {'6', "1101111", "11000011100011"},
        {'7', "1010010", "10000100000010"},
        {'8', "1111111", "11000111100011"},
        {'9', "1111011", "11000111000011"},

        // Letters
        {'A', "1111110", "11000111100010"},
        {'B', "0101111", "10010101001011"},
        {'C', "1100101", "11000000100001"},
        {'D', "0011111", "10010100001011"},
        {'E', "1101101", "11000011100001"},
        {'F', "1101100", "11000010100000"},
        {'G', "0000000", "11000001100011"},
        {'H', "0000000", "01000111100010"},
        {'I', "0000000", "10010000001001"},
        {'J', "0000000", "00000100100011"},
        {'K', "0000000", "01001010100100"},
        {'L', "0000000", "01000000100001"},
        {'M', "0000000", "01101100100010"},
        {'N', "0000000", "01100100100110"},
        {'O', "0000000", "11000100100011"},
        {'P', "0000000", "11000111100000"},
        {'Q', "0000000", "11000100100111"},
        {'R', "0000000", "11000111100100"},
        {'S', "0000000", "11000011000011"},
        {'T', "0000000", "10010000001000"},
        {'U', "0000000", "01000100100011"},
        {'V', "0000000", "01001000110000"},
        {'W', "0000000", "01000100110110"},
        {'X', "0000000", "00101000010100"},
        {'Y', "0000000", "00101000001000"},
        {'Z', "0000000", "10001000010001"}
};

#define NUM_OF_SEGMENTS (sizeof(segments) / sizeof(segment_def))
#define NUM_OF_SEG_LINES 7

void process_string(string source, int chars_per_line);
void print_line(string source, int group, int line, int chars_per_line);

boolean get_segment(segment_def *segment, char character);
boolean is_segment_enabled(segment_def segment, int bit);

void print_character_line(char character, int line);

#endif
