/*
 *  lab2exe_B.c
 *
 *  ENSF 614 Lab 2 Exercise B
 *
 */

int my_strlen(const char *s);
/*  Duplicates strlen from <string.h>, except return type is int.
 *  REQUIRES
 *     s points to the beginning of a string.
 *  PROMISES
 *     Returns the number of chars in the string, not including the
 *     terminating null.
 */

void my_strncat(char *dest, const char *source, int number_of_chars);
/*  Duplicates strncat from <string.h>, except return type is void.
 *  REQUIRES
 *     dest points to beginning of a string
 *     source points to the beginning of a string
 *     int to not be larger than the size of string source
 *     dest to have space for its own length + int + 1
 *  PROMISES
 *     Adds the amount of number_of_chars in source string to the end of dest string
 *
*/

int my_strcmp(const char *str1, const char *str2);
/* 
 *  Duplicates strcmp from <string.h>, except:
 *     0 is returned when strings are equal and
 *     ASCII value difference is returned of the first two character that are different
 *  REEQUIRES
 *     str1 points to beginning of a string
 *     str2 points to beginning of a string
 *  PROMISES
 *     return the ACSII value difference (str1 - str2) of the first two characters that are different.
 */

#include <stdio.h>
#include <string.h>

int my_strlen(const char *s)
{
       int count = 0;
       while (s[count] != '\0')
       {
              count++;
       }

       return count;
}

void my_strncat(char *dest, const char *source, int number_of_chars)
{

       int count = 0;
       while (dest[count] != '\0')
       {
              count++;
       }

       for (int i = 0; i < number_of_chars; i++)
       {
              dest[count] = source[i];
              count++;
       }

       dest[count] = '\0';

       printf("2");
}

int my_strcmp(const char *str1, const char *str2)
{
       int count = 0;
       while (str1[count] != '\0')
       {
              if (str1[count] != str2[count])
              {
                     break;
              }

              count++;
       }

       return (int)str1[count] - (int)str2[count];
}

int main(void)
{
       char str1[7] = "banana";
       const char str2[] = "-tacit";
       const char *str3 = "-toe";

       /* point 1 */
       char str5[] = "ticket";
       char my_string[100] = "";
       int bytes;
       int length;

       /* using strlen C libarary function */
       length = (int)my_strlen(my_string);
       printf("\nLine 1: my_string length is %d.", length); //0

       /* using sizeof operator */
       bytes = sizeof(my_string);
       printf("\nLine 2: my_string size is %d bytes.", bytes); //100

       /* using strcpy C libarary function */
       strcpy(my_string, str1);
       printf("\nLine 3: my_string contains: %s", my_string); //banana

       length = (int)my_strlen(my_string);
       printf("\nLine 4: my_string length is %d.", length); //6

       my_string[0] = '\0';
       printf("\nLine 5: my_string contains:\"%s\"", my_string); //""

       length = (int)my_strlen(my_string);
       printf("\nLine 6: my_string length is %d.", length); //0

       bytes = sizeof(my_string);
       printf("\nLine 7: my_string size is still %d bytes.", bytes); //100

       /* strncat append the first 3 characters of str5 to the end of my_string */
       my_strncat(my_string, str5, 3);
       printf("\nLine 8: my_string contains:\"%s\"", my_string); // tic

       length = (int)my_strlen(my_string);
       printf("\nLine 9: my_string length is %d.", length); //3

       my_strncat(my_string, str2, 4);
       printf("\nLine 10: my_string contains:\"%s\"", my_string); //tic-tac

       /* strncat append ONLY up ot '\0' character from str3 -- not 6 characters */
       my_strncat(my_string, str3, 6);
       printf("\nLine 11: my_string contains:\"%s\"", my_string); //tic-tac-toe

       length = (int)my_strlen(my_string);
       printf("\nLine 12; my_string has %d characters.", length); //11

       printf("\n\nUsing strcmp - C library function: ");

       printf("\n\"ABCD\" is less than \"ABCDE\" ... strcmp returns: %d",
              my_strcmp("ABCD", "ABCDE"));
       printf("\n\"ABCD\" is less than \"ABND\" ... strcmp returns: %d",
              my_strcmp("ABCD", "ABND"));
       printf("\n\"ABCD\" is equal than \"ABCD\" ... strcmp returns: %d",
              my_strcmp("ABCD", "ABCD"));
       printf("\n\"ABCD\" is less than \"ABCd\" ... strcmp returns: %d",
              my_strcmp("ABCD", "ABCd"));
       printf("\n\"Orange\" is greater than \"Apple\" ... strcmp returns: %d\n",
              my_strcmp("Orange", "Apple"));

       return 0;
}
