#include <stdio.h>
#include "mypushpop.h"

#define MAXVAL 100   /* maximum depth of val stack */
static int sp = 0;          /* next free stack position */
static double val[MAXVAL];  /* value stack */

void push(double f)  /* push: push f onto value stack */
{
   if (sp < MAXVAL)
      val[sp++] = f;
   else
      printf("error: stack full, can't push %g\n", f);
}

double pop(void)     /* pop: pop and return top value from stack */
{
   if (sp > 0)
      return val[--sp];
   else 
   {
      printf("error: stack empty\n");
      return 0.0;
   }
}
