/*9. Faça um programa que receba um valor que foi depositado e exiba o valor
com rendimento após um mês.
Considere fixo o juro da poupança em 0.70% a. m.*/

import java.util.Scanner;

public class Ex09{

	public static void main(String[] args){

		double valorDepositado, novoValor;
		final double JURO_FIXO = 0.007;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite o valor a ser Depositado: R$");
		valorDepositado = sc.nextDouble();

		novoValor = valorDepositado + (valorDepositado * JURO_FIXO);

		System.out.printf("Novo valor após um mês: R$%.2f\n", novoValor);
	}

}
