//
//  Ptr.c
//  RefCount
//
//  Created by  on 9/7/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
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
