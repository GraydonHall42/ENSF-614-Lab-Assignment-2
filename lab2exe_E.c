/*
 * lab2exe_E.c
 * Implementation file for complex number module
 *
 * ENSF 614 Lab 2 Exercise E
 */

#include "lab2exe_E.h"

struct cplx
cplx_add(struct cplx z1, struct cplx z2)
{
  struct cplx result;

  result.real = z1.real + z2.real;
  result.imag = z1.imag + z2.imag;
  return result;
}
