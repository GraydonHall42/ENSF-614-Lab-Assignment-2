#include <stdio.h>
int main()
{
   char * s3 = "BCD";  // best to have const in front so instead i get compilation error 
   s3[0]='A'; // this is illegal!

   char s4[] = "BCD";
   s4[0]='A'; // this is okay though!

   printf("%s", s3); // %s is format specifier

   return 0;
}