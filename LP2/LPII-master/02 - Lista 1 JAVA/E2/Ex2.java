import java.util.Scanner;

public class Ex2{

	public static void main(String[] args) {

		double valorDoAngulo;
		int nArgs = args.length;

		if (nArgs == 1) {

			try{
				valorDoAngulo = Double.parseDouble(args[0]);

				processaAngulos(valorDoAngulo);

				processaLoop(valorDoAngulo);
			}	
			catch(NumberFormatException e){
				System.out.println("\nO parametro de linha de comando " + args[0] + " é invalido!\n" );

				valorDoAngulo = 0;
			
				processaLoop(valorDoAngulo);
			}
		}

		else if (nArgs == 0){

			valorDoAngulo = 0;
			
			processaLoop(valorDoAngulo);
		}

		else if (nArgs != 0 || nArgs != 1){
			System.out.println("Foram passados parâmetros demais! Use apenas um numero!");
		}

	}

	public static void processaAngulos(double valorDoAngulo){

		System.out.printf("\nSeno: %.2f\n", Angulo.funcaoSeno(valorDoAngulo));

		System.out.printf("Coseno: %.2f\n", Angulo.funcaoCoseno(valorDoAngulo));

		System.out.printf("Tangente: %.2f\n", Angulo.funcaoTangente(valorDoAngulo));

		System.out.printf("Cotangente: %.2f\n\n", Angulo.funcaoCotangente(valorDoAngulo));
	}

	public static void processaLoop(double valorDoAngulo){
		
		Scanner sc = new Scanner(System.in);

		String valorDoAnguloString = String.valueOf(valorDoAngulo);

		while (valorDoAnguloString.isEmpty() == false){

			try{
				System.out.println("\nDigite uma medida em graus do angulo:");
				valorDoAnguloString = sc.nextLine();

				valorDoAngulo = Double.parseDouble(valorDoAnguloString);			

				processaAngulos(valorDoAngulo);
			}
			catch(NumberFormatException e){
				if (valorDoAnguloString.isEmpty() == false){
					System.out.println("\nO parametro " + valorDoAnguloString + " é inválido! Tente novamente!\n");
				}
				else{
					System.exit(0);
				}
			}
		}
	}
}