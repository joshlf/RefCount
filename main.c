// Copyright 2012 The Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <stdio.h>
#include "Ptr.h"

int main() {
    int* i = malloc(sizeof(int));
    *i = 5;
    ptr* p = new(i);
    ptr* q = cp(p);
    ptr* r = cp(q);
    
    printf("p: %d\n", *(int*)Ptr(p));
    printf("q: %d\n", *(int*)Ptr(q));
    printf("r: %d\n", *(int*)Ptr(r));
    
    del(p);
    del(q);
    del(r);
}
