#include<stdio.h>
int main()
{
      	int x, pulo = 0;
      	char A[65],B[65],result[65];
      	
    	A[65]='\0';
    	B[65]='\0';
     	
    	gets(A);
     	gets(B);
     	
        for (x = 64; x >= 0; x--)
     	{
     		if (A[x]== 0 && B[x]== 0)
     		{
     			if(pulo == 1)
     			{
     				result[x] = 1;
     				pulo = 0;
     	  	        }
     			else if (pulo == 0)
     			{
    				result[x]=0;
     			}
    		}
    		else if (A[x] == 1 && B[x] == 0)
      		{
     			if(pulo == 1)
     			{
     			        pulo = 1; 
   				        result[x] = 0;
    	   		}
    		        else if (pulo == 0)
    			{
     				result[x] = 1;
     				
    			}
      		}
    		else if (A[x] == 0 && B[x] == 1)
    		{
     			if (pulo == 1)
     			{
                         result[x] = 0;
                	     pulo = 1;
     	   		}
     		        else if (pulo == 0)
     			{
     				result[x] = 1;
     			}
      		}
      		else if (A[x] == 1 && B[x] == 1)
     		{
     			if(pulo == 1)
     			{
     	    	        	result[x] = 1;
                      		pulo = 1;
         	  		}
                     	else if (pulo == 0)
    			{
         		           result[x] = 0;
             	           pulo = 1;
     			}
      		}
     	}
    	
   		puts(result);
     
}
