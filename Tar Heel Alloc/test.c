/* -*- mode:c; c-file-style:"k&r"; c-basic-offset: 4; tab-width:4; indent-tabs-mode:nil; mode:auto-fill; fill-column:78; -*- */
/* vim: set ts=4 sw=4 et tw=78 fo=cqt wm=0: */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main() {
    int i = 32;
    int *x = malloc(i);
    int a = *x;

    for(int j = 0; j <= (i/4); j++) {
        a =*(x + j);
        printf("ALLOCPOISON %x\n", a);

    }

    free(x);
    for(int j = 0; j <= (i/4); j++) {
        a =*(x + j);
        printf("FREEPOISON %x\n", a);

    }
    // void *x = malloc(2048);
    // void *y = malloc(2048);
    // void *z = malloc(2048);
    // void *a = malloc(2048);
    // void *b = malloc(2048);
    // free(z);
    // free(y);
    // free(a);
    // free(x);
    // free(b);
    return (errno);
}
