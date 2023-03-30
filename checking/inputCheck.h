//
// Created by User on 09.03.2023.
//
#include <stdio.h>
#ifndef PRACTICE_1_INPUTCHECK_H
#define PRACTICE_1_INPUTCHECK_H

#endif //PRACTICE_1_INPUTCHECK_H

int intInput(int *link) {
    int boolean;
    boolean = scanf("%d", link);
    while ((getchar()) != '\n'); // to clear the stream
    if (boolean != 1) {
        return 0;
    } else {
        return 1;
    }
}