// Copyright 2012 The Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <stdio.h>
#include <stdlib.h>
#include "Ptr.h"

ptr* new(void* p) {
    ptr* new = malloc(sizeof(ptr));
    new->ctr = 1;
    new->p = p;
    return new;
}

ptr* cp(ptr* p) {
    p->ctr++;
    return p;
}

void del(ptr* p) {
    if (p->ctr == 1) {
        free(p->p);
        free(p);
    } else {
        p->ctr--;
    }
}

void delFunc(ptr* p, void (*f)(void*)) {
    if (p->ctr == 1) {
        f(p->p);
        free(p->p);
        free(p);
    } else {
        p->ctr--;
    }
}

void* Ptr(ptr* p) {
    return p->p;
}
