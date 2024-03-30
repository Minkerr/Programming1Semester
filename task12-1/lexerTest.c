#include "lexerTest.h"

#include "stdbool.h"
#include "stdio.h"
#include "realNumberLexer.h"

bool testEmptyString() {
    return !isRealNumberRecordCorrect("");
}

bool testStringStartsWithDot() {
    return !isRealNumberRecordCorrect(".239");
}

bool testStringEndsWithE() {
    return !isRealNumberRecordCorrect("222E");
}

bool testStringEndsWithSignAfterE() {
    return !isRealNumberRecordCorrect("222E-");
}

bool testStringWithTwoE() {
    return !isRealNumberRecordCorrect("222E10E10");
}

bool testStringWithTwoDots() {
    return !isRealNumberRecordCorrect("222.10.10");
}

bool testCorrectString1() {
    return isRealNumberRecordCorrect("222.10");
}

bool testCorrectString2() {
    return isRealNumberRecordCorrect("0.0");
}

bool testCorrectString3() {
    return isRealNumberRecordCorrect("0.5E10");
}

bool testCorrectString4() {
    return isRealNumberRecordCorrect("222E+1000");
}

void runAllTestsForTask12(){
    if(testCorrectString1()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testCorrectString2()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testCorrectString3()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testCorrectString4()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testEmptyString()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testStringEndsWithE()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testStringEndsWithSignAfterE()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testStringStartsWithDot()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testStringWithTwoDots()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }

    if(testStringWithTwoE()){
        printf("Test passed\n");
    }
    else {
        printf("Test failed\n");
    }
}
