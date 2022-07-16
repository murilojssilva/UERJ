import java.util.Scanner;
public class Ex1
{
	public static void main (String[] args)
	{
		int n,i;
		double salario,media = 0;
		Scanner dado = new Scanner (System.in);
		System.out.println("Digite a quantidade de pessoas dessa empresa");
		n = dado.nextInt();
		try
		{
			for (i = 0;i < n; i++)
			{
				System.out.println("\nDigite o salário do "+i+1+"º funcionário: ");
				salario = dado.nextDouble();
				media += salario;
			}
			media /= n;
			System.out.println("A média de salários dessa empresa é de: "+media);
		}
		catch(NumberFormatException e)
		{
			System.out.println("O argumento digitado não é um número");
		}
	}
}