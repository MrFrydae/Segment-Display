#include "display.h"

int main(int argc, string *argv) {
    if (argc < 3) {
        exit(EXIT_FAILURE);
    }

    int chars_per_line = atoi(argv[1]);

    process_string(argv[2], chars_per_line);

    return 0;
}

void process_string(string source, int chars_per_line) {
    int groups;
    if (strlen(source) <= chars_per_line) {
        groups = 1;
    } else {
        groups = ceil(strlen(source) / (chars_per_line * 1.0));
    }

    for (int group = 1; group <= groups; group++) {
        for (int line = 1; line <= NUM_OF_SEG_LINES; line++) {
            print_line(source, group, line, chars_per_line);
        }
    }
}

void print_line(string source, int group, int line, int chars_per_line) {
    string clone = malloc(sizeof(source));
    strcpy(clone, source);

    int increment = (group - 1) * chars_per_line;
    clone += increment;

    for (int i = 0; i < chars_per_line; i++) {
        print_character_line(clone[i], line);
    }

    printf("\n");
}

void print_character_line(char character, int line) {
    segment_def segment;
    if (!get_segment(&segment, character)) {
        return;
    }

    switch (line) {
        case 1:
            if (is_segment_enabled(segment, 1)) {
                printf(" --------- ");
            } else {
                printf("           ");
            }

            printf("   ");

            break;
        case 2:
            if (is_segment_enabled(segment, 2)) {
                printf("|");
            } else {
                printf(" ");
            }

            if (advanced) {
                if (is_segment_enabled(segment, 3)) {
                    printf(" \\ ");
                } else {
                    printf("   ");
                }

                if (is_segment_enabled(segment, 4)) {
                    printf(" | ");
                } else {
                    printf("   ");
                }

                if (is_segment_enabled(segment, 5)) {
                    printf(" / ");
                } else {
                    printf("   ");
                }
            } else {
                printf("         ");
            }

            if (is_segment_enabled(segment, advanced ? 6 : 3)) {
                printf("|");
            } else {
                printf(" ");
            }

            printf("   ");

            break;
        case 3:
            if (is_segment_enabled(segment, 2)) {
                printf("|");
            } else {
                printf(" ");
            }

            if (advanced) {
                if (is_segment_enabled(segment, 3)) {
                    printf("  \\");
                } else {
                    printf("   ");
                }

                if (is_segment_enabled(segment, 4)) {
                    printf(" | ");
                } else {
                    printf("   ");
                }

                if (is_segment_enabled(segment, 5)) {
                    printf("/  ");
                } else {
                    printf("   ");
                }
            } else {
                printf("         ");
            }

            if (is_segment_enabled(segment, advanced ? 6 : 3)) {
                printf("|");
            } else {
                printf(" ");
            }

            printf("   ");

            break;
        case 4:

            if (advanced) {
                printf(" ");

                if (is_segment_enabled(segment, 7)) {
                    printf("----");
                } else {
                    printf("    ");
                }

                printf(" ");

                if (is_segment_enabled(segment, 8)) {
                    printf("----");
                } else {
                    printf("    ");
                }

                printf(" ");
            } else {
                if (is_segment_enabled(segment, 4)) {
                    printf(" --------- ");
                } else {
                    printf("           ");
                }
            }

            printf("   ");

            break;
        case 5:
            if (is_segment_enabled(segment, advanced ? 9 : 5)) {
                printf("|");
            } else {
                printf(" ");
            }

            if (advanced) {
                if (is_segment_enabled(segment, 10)) {
                    printf("  /");
                } else {
                    printf("   ");
                }

                if (is_segment_enabled(segment, 11)) {
                    printf(" | ");
                } else {
                    printf("   ");
                }

                if (is_segment_enabled(segment, 12)) {
                    printf("\\  ");
                } else {
                    printf("   ");
                }
            } else {
                printf("         ");
            }

            if (is_segment_enabled(segment, advanced ? 13 : 6)) {
                printf("|");
            } else {
                printf(" ");
            }

            printf("   ");

            break;
        case 6:
            if (is_segment_enabled(segment, advanced ? 9 : 5)) {
                printf("|");
            } else {
                printf(" ");
            }

            if (advanced) {
                if (is_segment_enabled(segment, 10)) {
                    printf(" / ");
                } else {
                    printf("   ");
                }

                if (is_segment_enabled(segment, 11)) {
                    printf(" | ");
                } else {
                    printf("   ");
                }

                if (is_segment_enabled(segment, 12)) {
                    printf(" \\ ");
                } else {
                    printf("   ");
                }
            } else {
                printf("         ");
            }

            if (is_segment_enabled(segment, advanced ? 13 : 6)) {
                printf("|");
            } else {
                printf(" ");
            }

            printf("   ");

            break;
        case 7:
            if (is_segment_enabled(segment, advanced ? 14 : 7)) {
                printf(" --------- ");
            } else {
                printf("           ");
            }

            printf("   ");

            break;
    }
}

boolean is_segment_enabled(segment_def segment, int bit) {
    if (bit < 1) {
        return false;
    }

    if (advanced) {
        if (bit > 14) {
            return false;
        }

        return segment.enabled_14_bits[bit - 1] == '1';
    } else {
        if (bit > 7) {
            return false;
        }

        return segment.enabled_7_bits[bit - 1] == '1';
    }
}

boolean get_segment(segment_def *segment, char character) {
    for (int i = 0; i < NUM_OF_SEGMENTS; i++) {
        segment_def seg = segments[i];
        if (seg.character == character) {
            memcpy(segment, &seg, sizeof(segment_def));
            return true;
        }
    }

    return false;
}