/*12. Escreva um programa para ler o raio de um circulo, calcular e escrever a sua
área. (pR2)
Calculo: área= PI*(raio2)*/

import java.util.Scanner;
import java.lang.Math;

public class Ex12{

	public static void main(String[] args){

		double area, raio, raioAoQuadrado;
		final double PI = 3.14;

		Scanner sc = new Scanner(System.in);

		System.out.print("Digite o valor do Raio: ");
		raio = sc.nextDouble();

		raioAoQuadrado = Math.pow(raio,2);
		area = PI * raioAoQuadrado;

		System.out.printf("O valor da área deste círculo é: %.2f\n", area);
	}
}