/*10. A Loja Mamão com Açúcar está vendendo seus produtos em 5 (cinco)
prestações sem juros. Faça um programa que receba um valor de uma compra
e mostre o valor das prestações. */

import java.util.Scanner;

public class Ex10{

	public static void main(String[] args){

		double valorCompra, prestacoes, valorParcela;
		final double NUMERO_DE_VEZES = 5.0;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite o valor das compras: R$");
		valorCompra = sc.nextDouble();

		System.out.print("Digite em quantas vezes deseja dividir o pagamento: ");
		prestacoes = sc.nextDouble();

		valorParcela = valorCompra/prestacoes;

		System.out.printf("Cada prestação desta compra será no valor de: R$%.2f sem juros.\n", valorParcela);
	}
}