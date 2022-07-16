import java.util.InputMismatchException;
import java.util.Scanner;

public class Ex3{
	public static void main(String[] args) {
		
		double valorDoAngulo = 0;
		boolean verify = false; 

		Scanner sc = new Scanner(System.in);

		while (verify == false){

			try{
				System.out.println("Digite o numero de angulos:");
				int n = sc.nextInt();

				try{
					AnguloObj[] array = new AnguloObj[n];//criação de um array do tipo AnguloObj com n posições
					for (int i = 0; i < n; i++) {

						System.out.println("Digite a medida do "+ (i+1) +"º angulo: ");
						valorDoAngulo = sc.nextDouble();

						AnguloObj invocador = new AnguloObj(valorDoAngulo);// criação do invocador

						invocador.funcaoSeno();
						invocador.funcaoCoseno();
						invocador.funcaoTangente();
						invocador.funcaoCotangente();
						invocador.toString();

						array[i] = invocador;
					}

					System.out.println("\n\nResultado =====================");

					for (int i = 0; i < array.length; i++) {
		    			System.out.println(array[i]);
		  			}
		  			verify = true;
				}
				catch(NegativeArraySizeException e1){
					System.out.println("Você não pode entrar com um número negativo de vezes!\n");
				}
			}
			catch(InputMismatchException e2){
				System.out.println("O que voce digitou nao é um valor válido! Tente novamente!\n");
				String limpaBuff = sc.next();
			}
		}

        
	}
}
