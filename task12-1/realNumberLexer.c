#include "realNumberLexer.h"
#include <stdbool.h>

enum State {
    FIRST_CHAR,
    INTEGER_PART,
    DOT,
    FRACTIONAL_PART,
    E,
    EXPONENT_PART_SIGN,
    EXPONENT_PART,
    NOT_CORRECT
};

bool isRealNumberRecordCorrect(const char *str) { //digit+ (. digit+)? (E(+ | -)? digit+)?
    int state = FIRST_CHAR;

    for (int i = 0; str[i] != '\0'; i++) {
        switch (state) {
            case FIRST_CHAR:
                if (str[i] >= '0' && str[i] <= '9') {
                    state = INTEGER_PART;
                } else {
                    state = NOT_CORRECT;
                }
                break;
            case INTEGER_PART:
                if (str[i] >= '0' && str[i] <= '9') {
                    state = INTEGER_PART;
                } else if (str[i] == '.') {
                    state = DOT;
                } else if (str[i] == 'E') {
                    state = E;
                } else {
                    state = NOT_CORRECT;
                }
                break;
            case DOT:
                if (str[i] >= '0' && str[i] <= '9') {
                    state = FRACTIONAL_PART;
                } else {
                    state = NOT_CORRECT;
                }
                break;
            case FRACTIONAL_PART:
                if (str[i] >= '0' && str[i] <= '9') {
                    state = FRACTIONAL_PART;
                } else if (str[i] == 'E') {
                    state = E;
                } else {
                    state = NOT_CORRECT;
                }
                break;
            case E:
                if (str[i] == '+' || str[i] == '-') {
                    state = EXPONENT_PART_SIGN;
                } else if (str[i] >= '0' && str[i] <= '9') {
                    state = EXPONENT_PART;
                } else {
                    state = NOT_CORRECT;
                }
                break;
            case EXPONENT_PART_SIGN:
                if (str[i] >= '0' && str[i] <= '9') {
                    state = EXPONENT_PART;
                } else {
                    state = NOT_CORRECT;
                }
                break;
            case EXPONENT_PART:
                if (str[i] >= '0' && str[i] <= '9') {
                    state = EXPONENT_PART;
                } else {
                    state = NOT_CORRECT;
                }
                break;
            case NOT_CORRECT:
                break;
        }
    }

    return (state == INTEGER_PART || state == FRACTIONAL_PART || state == EXPONENT_PART);
}