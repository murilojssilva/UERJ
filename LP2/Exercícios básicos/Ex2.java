import java.util.Scanner;
public class Ex2
{
	public static void main (String [] args)
	{
		char c;
		double a,b,res = 0;
		Scanner dado = new Scanner (System.in);
		System.out.println("Digite um valor para o primeiro argumento");
		a = dado.nextDouble();
		try
		{
			System.out.println("Digite um valor para o segundo argumento");
			b = dado.nextDouble();
			try
			{
				System.out.println("Digite a operação desejada: ");
				c = dado.next().charAt(0);
				if (c == '+')
				{
					res = a + b;
				}
				else if (c == '-')
				{
					res = a - b;
				}
				else if (c == '*')
				{
					res = a * b;
				}
				else if (c == '/')
				{
					if (b != 0) 
					{
						res = a / b;
					}
					else
					{
						System.out.println("Esse número não pode ser dividido");
						System.exit(0);
					}
				}
				System.out.println("O resultado da operação "+ c +" é: "+ res);
			}
			catch (NumberFormatException e1)
			{
				System.out.println("Esse argumento não é um número");
			}
		}
		catch(NumberFormatException e)
		{
			System.out.println("Esse argumento não é um número.");
		}
	}	
}