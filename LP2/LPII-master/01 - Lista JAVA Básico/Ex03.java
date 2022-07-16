/*3. Escrever um programa para determinar o consumo médio de um automóvel
sendo fornecida a distância total percorrida pelo automóvel e o total de
combustível gasto.*/

import java.util.Scanner;

public class Ex03{

	public static void main(String[] args){

		double consumoMedio, distInicial, distPercorrida, distFinal, combGasto;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite a distância incial percorrida pelo automóvel: ");
		distInicial = sc.nextDouble();

		System.out.print("Digite distância final que o automóvel percorreu: ");
		distFinal = sc.nextDouble();

		System.out.print("Digite a quantidade de combustível gasto no percurso: ");
		combGasto = sc.nextDouble();

		distPercorrida = distFinal - distInicial;

		consumoMedio = distPercorrida/combGasto;

		System.out.printf("A media de gasto desse carro é %.2f Km/L.\n", consumoMedio);
	}
}
