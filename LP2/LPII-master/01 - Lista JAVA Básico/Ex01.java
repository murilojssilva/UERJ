/*1. Escrever um programa java que receba dois números e exiba o resultado da sua soma.*/

import java.util.Scanner;

public class Ex1{

	public static void main (String[] args){

		int x, y, total;

		Scanner sc = new Scanner(System.in);

		System.out.println("Digite o valor do primeiro numero: ");
		x = sc.nextInt();

		System.out.println("Digite o valor do segundo numero: ");
		y = sc.nextInt();

		total = x+y;

		System.out.println("O resultado do processamento: ["+x+" + "+y+" = " +total+"]");
	}
}
