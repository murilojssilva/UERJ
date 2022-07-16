/*14. Entrar com dois números e imprimir o menor número (suponha números
diferentes). */

import java.util.Scanner;

public class Ex14{

	public static void main(String[] args) {
		
		int x, y;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite o valor de X: ");
		x = sc.nextInt();

		System.out.print("Digite o valor de Y: ");
		y = sc.nextInt();

		if (x < y) {
			System.out.println("O menor número é X: " +x);
		}
		else if (y < x) {
			System.out.println("O menor número é Y: " +y);	
		}
		else{
			System.out.println("Os numeros são iguais.");
		}
	}
}