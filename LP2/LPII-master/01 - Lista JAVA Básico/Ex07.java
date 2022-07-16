/*7. Ler uma temperatura em graus Celsius e apresentá-la convertida em graus
Fahrenheit. A fórmula de conversão é: F=(9*C+160) / 5, sendo F a
temperatura em Fahrenheit e C a temperatura em Celsius.*/

import java.util.Scanner;

public class Ex07{

	public static void main(String[] args){

		double f, c;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite o valor da temperatura em Celsius: ");
		c = sc.nextDouble();

		f = ((9*c)+160)/5;

		System.out.printf("A temperatura em Fahrenheit é: %.1f\n", f);
	}
}
