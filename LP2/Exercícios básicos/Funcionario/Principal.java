import java.util.Scanner;
import java.util.InputMismatchException;
import java.io.*;
public class Principal
{
	public static void main(String[] args)
	{
		Scanner dado = new Scanner(System.in);
		int i = 0,pessoas = -1;
		try
		{
			System.out.printf("Digite a quantidade de funcionários: ");
			pessoas = dado.nextInt();
			if (pessoas > 0)
			{
				String func[] = new String [pessoas];
				for (;i < pessoas;i++); 
				{
					Funcionarios f = null;
					try
					{
						System.out.printf("Nome do funcionário: ");
						f.nome = dado.next();
					}
					catch(InputMismatchException e)
					{
						System.out.println("Argumento inválido.");
					}
					try
					{
						System.out.printf("Departamento do funcionário: ");
						f.departamento = dado.next();
					}
					catch (InputMismatchException e)
					{
						System.out.println("Argumento inválido.");
					}
					try
					{	
						System.out.printf("Dia de entrada do funcionário: ");
						f.dia = dado.nextInt();
					}
					catch (InputMismatchException e)
					{
						System.out.println("Argumento inválido.");
					}
					try
					{	
						System.out.printf("Mês de entrada do funcionário: ");
						f.mes = dado.nextInt();
					}catch (InputMismatchException e)
					{
						System.out.println("Argumento inválido.");
					}
					try
					{	
						System.out.printf("Ano de entrada do funcionário: ");
						f.ano = dado.nextInt();
					}
					catch (InputMismatchException e)
					{
						System.out.println("Argumento inválido.");
					}
					System.out.printf("RG do funcionário: ");
					f.rg = dado.next();
					while (f.rg.length() != 9)
					{
						System.out.printf("RG do funcionário inválido. Digite-o novamente: ");
						f.rg = dado.next();	
					}
					try
					{
						System.out.printf("Salário do funcionário: ");
						f.salario = dado.nextDouble();
						f.bonifica(1000);
						System.out.println("O funcionário recebeu um aumento de 1000,00 R$. O novo salário é de "+f.salario+" reais");
					}
					catch (InputMismatchException e)
					{
						System.out.println("Argumento inválido.");
					}
					int verifica = -1;
					do
					{
						try
						{
							System.out.printf("Este funcionário está na empresa? (0- Sim 1- Não): ");
							verifica = dado.nextInt();
						}
						catch (InputMismatchException e)
						{
							System.out.println("Argumento inválido.");
						}
						if (verifica == 0)
						{
							f.funcEmpresa = true;
						}
						else if (verifica == 1)
						{
							f.funcEmpresa = false;
						}
						else
						{
								System.out.println("Opção errada. Digite-a novamente.");
						}
					}while (verifica != 1 && verifica != 2);
					func [i] = f.toString();
				}
				for (i = 0;i < pessoas;i++)
				{
					System.out.println(func[i]);
				}
			}
		}
		catch(InputMismatchException e)
		{
			System.out.printf("Argumento inválido");
		}
	}
}