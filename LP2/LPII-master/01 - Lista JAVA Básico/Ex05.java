/*5. Escrever um programa que leia o nome de um aluno e as notas das três
provas que ele obteve no semestre. No final informar o nome do aluno e a
sua média (aritmética).*/

import java.util.Scanner;

public class Ex05{

	public static void main(String[] args){

		String nome;
		double p1, p2, p3, media;
		final double TOTAL_DE_PROVAS = 3.0;

		Scanner sc = new Scanner(System.in);

		System.out.println("Digite o nome do aluno:");
		nome = sc.nextLine();

		System.out.println("Digite a nota da P1:");
		p1 = sc.nextDouble();

		System.out.println("Digite a nota da P2:");
		p2 = sc.nextDouble();

		System.out.println("Digite a nota da P3:");
		p3 = sc.nextDouble();

		media = (p1+p2+p3)/TOTAL_DE_PROVAS;

		System.out.printf("Nome: %s\n", nome);
		System.out.printf("Média Final: %.2f\n", media);
	}
}
