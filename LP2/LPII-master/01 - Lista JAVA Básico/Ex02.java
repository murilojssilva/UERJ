/*2. Escrever um programa que receba dois números e ao final mostre a soma, 
subtração, multiplicação e a divisão dos números lidos.*/

import java.util.Scanner;

public class Ex2{

	public static void main (String[] args){

		int x, y, total, diferenca, produto, quociente, resto;

		Scanner sc = new Scanner(System.in);

		System.out.println("Serão realizadas as operações X*Y sendo * as quatro operações básicas.");

		System.out.print("Digite o valor do X: ");
		x = sc.nextInt();

		System.out.print("Digite o valor do Y: ");
		y = sc.nextInt();

		total = x+y;
		diferenca = x-y;
		produto = x*y;
		quociente = x/y;
		resto = x%y;

		System.out.println("Resultados: ");

		System.out.println(x+"+"+y+"="+total);
		System.out.println(x+"-"+y+"="+diferenca);
		System.out.println(x+"*"+y+"="+produto);
		System.out.println(x+"/"+y+"="+quociente);
		System.out.println(x+"%"+y+"="+resto);
	}
}
