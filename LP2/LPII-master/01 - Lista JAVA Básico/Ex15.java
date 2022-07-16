/*15. Entrar com dois números e imprimi-los em ordem decrescente (suponha
números diferentes).*/	

import java.util.Scanner;

public class Ex15{

	public static void main(String[] args) {
		
		int x, y;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite o valor de X: ");
		x = sc.nextInt();

		System.out.print("Digite o valor de Y: ");
		y = sc.nextInt();

		if (x < y) {
			System.out.println(y+"..."+x);
		}
		else if (y < x) {
			System.out.println(x+"..."+y);
		}
		else {
			System.out.println(x+" = "+y);
		}
	}
}