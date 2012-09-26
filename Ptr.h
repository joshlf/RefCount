// Copyright 2012 The Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef PTR_INC
#define PTR_INC
#define T ptr

typedef struct T *T;

// p is a heap-allocated pointer.
// passing a reference to a stack-allocated
// variable will cause an error when
// the ptr tries to free p.
//
// Return a reference-counted pointer 
// initialized to point at p.
T new(void *p);

// Increase the reference count
// of p and return a pointer to p.
T cp(T p);

// Decrease the reference count
// of p. If the reference count
// has reached 0, free the contained
// pointer
void del(T p);

// Same as del, except that *f
// is called on the contained pointer
// before it is freed
void delFunc(T p, void (*f)(void*));

// Return the contained pointer.
void* Ptr(T p);

#endif
