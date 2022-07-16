//Murilo de Jesus Santos Silva
public class Ex1
{
	public static void main(String[] args)
	{
		int i;
		if (args.length == 6)
		{
			try
			{
				double ax = Double.parseDouble(args[0]);
				double ay = Double.parseDouble(args[1]);
				double bx = Double.parseDouble(args[2]);
				double by = Double.parseDouble(args[3]);
				double cx = Double.parseDouble(args[4]);
				double cy = Double.parseDouble(args[5]);
				double dAB = Math.sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
				double dAC = Math.sqrt((cx-ax)*(cx-ax)+(cy-ay)*(cy-ay));
				double dBC = Math.sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
				perim(dAB,dAC,dBC);
				are(dAB,dAC,dBC);
				if((dAB < dAC + dBC) && (dAC < dAB + dBC) && (dBC < dAB + dAC))
                		{
					if (dAB == dAC && dAC == dBC && dAB == dBC)
					{
						System.out.println("O triângulo é equilátero");
					}
					else if (dAB == dAC || dAC == dBC || dAB == dBC)
					{
						System.out.println("O triângulo é isósceles");
					}
					else
					{   
						System.out.println("O triângulo é escaleno");
					}
				}
				else
				{
					System.out.println("Os pontos dados não formam um triângulo");
				}
			}
			catch(NumberFormatException e)
			{
				for (i = 0;i < args.length;i++)
				{
					try
					{
						Double.parseDouble(args[i]);
					}
					catch (NumberFormatException f)
					{
						System.out.println((i + 1)+"° argumento não é um número: "+args[i]);
					}
				}
			}
		}
		else if (args.length > 6)
		{
			System.out.println("Número de argumentos excessivo.");
		}
		else
		{
			System.out.println("Número de argumentos insuficiente.");
		}
	}
	public static double perim(double dAB,double dAC,double dBC)
	{
		double perimetro = dAB + dAC + dBC;
		System.out.println("O perimetro do triângulo é: "+perimetro+" unidades.");
		return perimetro;
	}
	public static double are(double dAB,double dAC,double dBC)
	{
		double semiPerim = (dAB + dAC + dBC)/2;
		double area = Math.sqrt(semiPerim*(semiPerim-dAB)*(semiPerim-dAC)*(semiPerim-dBC));
		System.out.println("A área do triângulo é: "+area+" unidades de área.");
		return semiPerim;
	}
}
