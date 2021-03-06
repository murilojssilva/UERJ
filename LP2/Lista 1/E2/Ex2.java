import java.util.Scanner;
public class Ex2
{
	public static void main(String[] args)
	{
		try
		{		
			double ang = Double.parseDouble(args[0]);;
			Scanner dado = new Scanner(System.in);
			if (args.length == 1)
			{
				Angulo.converteAngulo(ang);
				System.out.println("Seno: "+Angulo.funcaoSeno(ang));
				System.out.println("Cosseno: "+Angulo.funcaoCosseno(ang));
				System.out.println("Tangente: "+Angulo.funcaoTangente(ang));
				System.out.println("Cotangente: "+Angulo.funcaoCotangente(ang)+"\n");
				System.out.println("Digite uma medida em graus do ângulo");
				String ang2 = dado.nextLine();
				while (ang2.compareTo("") != 0)
				{
					try
					{
						double angulo2 = Double.parseDouble(ang2);
						Angulo.converteAngulo(angulo2);
						System.out.println("Seno: "+Angulo.funcaoSeno(angulo2));
						System.out.println("Cosseno: "+Angulo.funcaoCosseno(angulo2));
						System.out.println("Tangente: "+Angulo.funcaoTangente(angulo2));
						System.out.println("Cotangente: "+Angulo.funcaoCotangente(angulo2)+"\n");
						System.out.println("Digite uma medida em graus do ângulo");
						ang2 = dado.next();
					}
					catch (NumberFormatException f)
					{
							System.out.println("O argumento digitado é inválido.");
							System.exit(0);
					}
				}
			}			
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("O argumento digitado é inválido.");
		}	
	}
}
