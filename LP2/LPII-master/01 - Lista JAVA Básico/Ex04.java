/*4. Escrever um programa que leia o nome de um vendedor, o seu salário fixo e o
total de vendas efetuadas por ele no mês (em dinheiro). Sabendo que este
vendedor ganha 15% de comissão sobre suas vendas efetuadas, informar o
seu nome, o salário fixo e salário no final do mês.*/

import java.util.Scanner;

public class Ex04{

	public static void main(String[] args){

		String nome;
		double salFixo, totalVendas, salFinal;
		final double TAXA_COMISSAO = 0.15;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite o nome do vendedor: ");
		nome = sc.nextLine();

		System.out.print("Digite o valor do salário fixado: R$");
		salFixo = sc.nextDouble();

		System.out.print("Digite o valor das vendas efetuadas: R$");
		totalVendas = sc.nextDouble();

		salFinal = salFixo+(totalVendas*TAXA_COMISSAO);

		System.out.printf("Nome: %s\n", nome);
		System.out.printf("Salário Fixo: R$%.2f\n", salFixo);
		System.out.printf("Salário Final: R$%.2f\n", salFinal);
	}
}
