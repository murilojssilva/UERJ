import java.util.Scanner;
import java.util.InputMismatchException;
public class Fibonacci
{
	public void Fibonacci()
	{
		try
		{
			Scanner dado = new Scanner(System.in);
			int n = dado.nextInt();
			long n2 = 1, n1 = 1, aux = 0;
			for (int i = 0;i < n; i++)
			{
				System.out.println((i+1)+": "+n1);
				aux = n2;
				n2+=n1;
				n1=aux;
			}
		}
		catch(InputMismatchException erro)
		{
			System.out.println("Argumento inválido");
		}
	}
	public static void main (String [] args)
	{
		Fibonacci();	
	}
}