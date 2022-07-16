/*8. Elaborar um programa que efetue a apresentação do valor da conversão em
real (R$) de um valor lido em dólar (US$). O algoritmo deverá solicitar o valor
da cotação do dólar e também a quantidade de dólares disponíveis com o
usuário.*/

import java.util.Scanner;

public class Ex08{

	public static void main(String[] args){

		double real, dolar, cotacao;

		Scanner sc = new Scanner(System.in);

		System.out.println("Digite o valor em Dólar: U$");
		dolar = sc.nextDouble();

		System.out.println("Digite o valor da atual cotacao do dólar: ");
		cotacao = sc.nextDouble();

		real = dolar * cotacao;

		System.out.printf("Valor convertido em real: %.2f\n", real);
	}
}
