/*
 * Main program file.
 *
 * ENSF 614 Lab 2 Exercise E
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab2exe_E.h"

double read_double_only(void);
/*
 *  Read a double, then skip to the end of a line of input.
 *
 *  REQUIRES
 *     User has been prompted to enter a double.
 *  PROMISES
 *     If user enters bad input, exit is called with an arg of 1.
 *     Otherwise:
 *        Characters following the int are discarded up to
 *        end-of-line or end-of-file, whichever is first.
 *        Return value is the double that was read.
 */

int main(void)
{
  struct cplx w, z;			/* entered by user */
  struct cplx sum;			/* sum of w and z */
  struct cplx diff;			/* difference of w and z */
  struct cplx prod;			/* product of w and z */

  printf("This programs needs values for complex numbers w and z.\n");

  printf("  Please enter the real part of w     : ");
  w.real = read_double_only();
  printf("  Please enter the imaginary part of w: ");
  w.imag = read_double_only();

  printf("  Please enter the real part of z     : ");
  z.real = read_double_only();
  printf("  Please enter the imaginary part of z: ");
  z.imag = read_double_only();

  printf("\nw is (%f) + j(%f)\n", w.real, w.imag);
  printf("z is (%f) + j(%f)\n", z.real, z.imag);

  sum = cplx_add(w, z);
  cplx_subtract(w, z, &diff);
  cplx_multiply(&w, &z, &prod);

  printf("\nsum is (%f) + j(%f)\n", sum.real, sum.imag);
  printf("difference is (%f) + j(%f)\n", diff.real, diff.imag);
  printf("product is (%f) + j(%f)\n", prod.real, prod.imag);

  return 0;
}


double read_double_only(void)
{
  double value_read;
  int char_code;
 
  if (scanf("%lf", &value_read) != 1) {
    printf("Error trying to read in a double.  Program terminated.\n");
    exit(1);
  }
 
  char_code = getchar();
  while (char_code != '\n' && char_code != EOF)
    char_code = getchar();
 
  return value_read;
}