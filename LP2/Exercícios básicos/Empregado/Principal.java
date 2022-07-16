import java.util.Scanner;
import java.util.ImputMisMatchException;
public class Principal
{
	public static void main(String [] args)
	{
		Scanner dado = new Scanner(System.in);
		EmpregadoContratado emp = new EmpregadoContratado(String nome,String codigo,double salario,int numDep);
		for (;;)
		{
			try
			{
				int opc = dado.nextInt();
				if (opc == 0)
					break;
				else
				{
					System.out.println("Digite os dados do funcionário\nNome: ");
					emp.nome = dado.next();
					System.out.println("Código do empregado");
					emp.codigo = dado.next();
					System.out.println("Salário-base do empregado");
					emp.salario = dado.nextDouble();
					//empcomp = new EmpregadoContratado(String nome,String codigo,double salario,int numDep);
					emp.calculaSalario(aliquota);
				}
			}
			catch (InputMismatchException erro)
			{

			}
		}
	}
}
/*
public void finaliza()
{
	System.exit(0);
}*/