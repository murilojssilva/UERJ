//Murilo de Jesus Santos Silva
import java.util.Scanner;
import java.util.InputMismatchException;
public class Ex3
{
	public static void main(String[] args)
	{
		try
		{
			Scanner dado = new Scanner(System.in);
			System.out.println("Digite a quantidade de argumentos a serem convertidos: ");
			int qtd = dado.nextInt();
			if (qtd != 0)
			{
				int i;
				AnguloObj [] dados = new AnguloObj[qtd];
				
					for (i = 0;i < qtd;i++)
					{
						System.out.println("Digite o valor do ângulo: ");
						double ang = dado.nextDouble();
						try
						{							
							AnguloObj valores = new AnguloObj();
							valores.AngObj(ang);
							valores.funcaoSeno();
							valores.funcaoCosseno();
							valores.funcaoTangente();
							valores.funcaoCotangente();
							valores.toString();
							dados[i] =  valores;
						}
						catch(InputMismatchException e1)
						{
							System.out.println("O argumento digitado não é um número.");
						}
					}
				System.out.println("\n\nResultado=====================\n");
				for (i = 0;i < qtd;i++)
				{
					System.out.println(dados[i]+"\n");
				}
			}
			else
			{
				System.exit(0);
			}
		}
		catch(InputMismatchException e2)
		{
			System.out.println("O argumento digitado não é um número.");
		}
	}
}
