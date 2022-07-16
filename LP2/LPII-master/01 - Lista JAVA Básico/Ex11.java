/*11. Faça um programa que receba o preço de custo de um produto e mostre o
valor de venda. Sabe-se que o preço de custo receberá um acréscimo de
acordo com um percentual informado pelo usuário.*/

import java.util.Scanner;

public class Ex11{

	public static void main(String[] args){

		double precoDeCusto, valorDeVenda, acrescimo, taxa;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite o preço de custo do Produto: R$");
		precoDeCusto = sc.nextDouble();

		System.out.print("Digite a porcentagem que deseja aumentar o preço: ");
		acrescimo = sc.nextDouble();

		taxa = acrescimo / 100;

		valorDeVenda = precoDeCusto + (precoDeCusto*taxa);

		System.out.printf("O preço de venda do produto será: R$%.2f\n", valorDeVenda);
	}
}