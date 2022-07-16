#include<stdio.h>
int main()
{
	int i;
	char num1[65],num2[65],soma[65],v1='0';
	for(i = 0; i < 65; i++)
	{
   	   soma[i] = '0';
   	   if (i==64)
   	   {
   	      			num1[i]='\0';
				num2[i]='\0';
				soma[i]='\0';  	   
   	   }
	}
	gets(num1);
	gets(num2);
	for (i=64;i>=0;i--)
	{
		if (num1[i]=='0' && num2[i]=='0')
		{
			if(v1 > '0')
			{
				soma[i] = '1';
				v1 = '0';
	  	        }
			else
			{
				soma[i]='0';
			}
		}
		else if (num1[i]=='1' && num2[i]=='0'||num1[i]=='0' && num2[i]=='1')
		{
			if(v1 > '0')
			{
    	       soma[i] = '0';
             v1='1';
	   	}
		        else
			{
				soma[i] = '1';
			}
 		}
		else if (num1[i]=='1' && num2[i]=='1')
		{
			if(v1 > '0')
			{
	    	        	soma[i] = '1';
                 	v1='1';
    	   }
                	else
			{
    		           soma[i] = '0';
        	           v1='1';
			}
		}
	}
	puts(soma);
}

