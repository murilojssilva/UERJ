#include "mypushpop.h"
#include "mygetop.h"
#include "progPag076.h"

#include <stdio.h> /* for atof() */
#include <stdlib.h> 

/*#define MAXOP 100/* max size of operand or operator */
/*#define NUMBER '0'/* signal that a number was found */

main()      /* reverse Polish calculator */
{
   int type;
   double op2;
   char s[MAXOP];
   while ((type = getop(s)) != EOF) 
   {
      switch (type) {
         case NUMBER:
            push(atof(s));
         break;

         case '+':
            push(pop() + pop());
         break;

         case '*':
            push(pop() * pop());
         break;

         case '-':
            op2 = pop();
            push(pop() - op2);
         break;

         case '/':
            op2 = pop();
            if (op2 != 0.0)
               push(pop() / op2);
            else
               printf("error: zero divisor\n");
         break;

         case '\n':
            printf("\t%.8g\n", pop());
         break;

         default:
            printf("error: unknown command %s\n", s);
         break;
      }
   }
   return 0;
}
