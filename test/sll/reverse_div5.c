/**
  Copyright (c) Microsoft Corporation.  All rights reserved.

  Create, attempt to reverse, and then destroy a singly-linked list.

  Similar to reverse_div3.c but nondeterministically breaks the list,
  so that reverse may terminate with a cyclic list, which destroy
  crashes on.
**/

#include "sll.h"


void reverse(PSLL_ENTRY *l) {
  PSLL_ENTRY c = *l, r = NULL;
  while(c != NULL) {
    PSLL_ENTRY t;
    t = c;
    if (nondet())
      c = c->Flink;
    t->Flink = r;
    r = t;
  }
  *l = r;
}

void main() {
  PSLL_ENTRY head;

  head = SLL_create(nondet());

  reverse(&head);

  SLL_destroy(head);
}
