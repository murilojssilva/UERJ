public class Ex1{

	public static void main(String[] args){ 

		int nArgs = args.length;

		if (nArgs == 6){

			try{
				double xA = Double.parseDouble(args[0]);
				double yA = Double.parseDouble(args[1]);
				double xB = Double.parseDouble(args[2]);
				double yB = Double.parseDouble(args[3]);
				double xC = Double.parseDouble(args[4]);
				double yC = Double.parseDouble(args[5]);

				double distAB = Math.sqrt ( ((xB-xA)*(xB-xA)) + ((yB-yA)*(yB-yA))); 
				double distAC = Math.sqrt ( ((xC-xA)*(xC-xA)) + ((yC-yA)*(yC-yA))); 
				double distBC =	Math.sqrt ( ((xC-xB)*(xC-xB)) + ((yC-yB)*(yC-yB)));

				processaTriangulo(distAB, distAC, distBC);
			}
			catch (NumberFormatException e){
				for (int i = 0; i < nArgs; ++i)	{
					try{
						Double.parseDouble(args[i]);
					}
					catch(NumberFormatException e1){
						System.out.println("Problema no " + (i + 1) + "o argumento, ''" + args[i] + "'', nao é um numero.");
					}
				}
			}
		}

		else if (nArgs < 6){
			System.out.println("\nForam passados poucos parâmetros! Tente Novamente.\n");
		}

		else if (nArgs > 6){
			System.out.println("\nForam passados muitos parâmetros! Tente Novamente.\n");
		}
	}

	public static double calculaPerimetro(double distAB, double distAC, double distBC){
		double perimetro = distAB + distAC + distBC;
		return perimetro;
	}

	public static double calculaArea(double distAB, double distAC, double distBC){
		double semiperimetro = (distAB + distAC + distBC)/2;
		double area = Math.sqrt ((semiperimetro*(semiperimetro-distAB)*(semiperimetro-distAC)*(semiperimetro-distBC)));
		return area;
	}

	public static void imprimeResultados(double distAB, double distAC, double distBC){
		System.out.printf("\nO Perímetro do triangulo eh: %.2f unidades.\n" , calculaPerimetro(distAB, distAC, distBC));
		System.out.printf("A area do triangulo eh: %.2f unidades de area.\n", calculaArea(distAB, distAC, distBC));
	}

	public static void processaTriangulo(double distAB, double distAC, double distBC){

		if ((distAB < distAC + distBC) && (distAC < distAB + distBC) && (distBC < distAB+distAC)){// verifica se é um triangulo

			imprimeResultados(distAB, distAC, distBC);

        	if (distAB == distAC && distAB == distBC){	

        		System.out.println("Três lados iguais . Trata-se de um Triangulo Equilatero.\n");  
        	}
        	else if((distAB == distAC) || (distAB == distBC)){

          		System.out.println("Dois lados iguais . Trata-se de um Triangulo Isosceles.\n"); 
          	}
        	else{

            	System.out.println("Três lados diferentes. Trata-se de um Triangulo Escaleno.\n");
            }
        }
        else{

       		System.out.println("\nOs pontos dados não formam um triângulo.\n");
       	}
	}
}