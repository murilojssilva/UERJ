package CalculoIMC;

import java.util.*;
import javax.swing.*;

//import javax.swing.*;
public class Ex2
{
	private static Scanner dado;

	public static void main(String[] args)
	{
		try
		{
			try
			{
				dado = new Scanner (System.in);
				Vector<PessoaIMC> pessoas = new Vector<PessoaIMC>();
				System.out.println("Digite o número de pessoas");
				int qtd = dado.nextInt();
				if (qtd>0)
				{
					for (int i = 0;i < qtd;i++)
					{
						PessoaIMC ser = null;
						System.out.println("\nInserir homem (h) ou mulher (m)");
						String sexo = dado.next();
						double peso = -1,altura = -1;
						while (sexo.compareTo("m") != 0 && sexo.compareTo("h") != 0)
						{
								System.out.println(sexo+"--Opção inválida\nInserir homem (h) ou mulher (m)");
								sexo = dado.next();
						}
						if (sexo.compareTo("h") == 0)
						{
							System.out.println("Digite o nome da pessoa");
							String nome = dado.next();
							System.out.println("Digite a data de nascimento da pessoa");
							String dataNascimento = dado.next();
							try
							{
								System.out.println("Digite o peso da pessoa");
								peso = Double.parseDouble(dado.next());
							}
							catch(NumberFormatException h1)
							{
								System.out.println("O argumento digitado é inválido");
								System.exit(0);
							}
							try
							{
								System.out.println("Digite a altura da pessoa");
								altura = Double.parseDouble(dado.next());
							}
							catch(NumberFormatException h2)
							{
								System.out.println("O argumento digitado é inválido");
								System.exit(0);
							}
							ser = new Homem(nome,dataNascimento,peso,altura);
							pessoas.add(ser);
						}
						else if (sexo.compareTo("m") == 0)
						{
							System.out.println("Digite o nome da pessoa");
							String nome = dado.next();
							System.out.println("Digite a data de nascimento da pessoa");
							String dataNascimento = dado.next();
							try
							{
								System.out.println("Digite o peso da pessoa");
								peso = Double.parseDouble(dado.next());
							}
							catch(NumberFormatException m1)
							{
								System.out.println("O argumento digitado é inválido");
								System.exit(0);
							}
							try
							{
								System.out.println("Digite a altura da pessoa");
								altura = Double.parseDouble(dado.next());
							}
							catch(NumberFormatException m2)
							{
								System.out.println("O argumento digitado é inválido");
								System.exit(0);
							}
							ser = new Mulher(nome,dataNascimento,peso,altura);
							//Mulher.imc();
							pessoas.add(ser);
						}
					}
				}
				else
				{
					System.exit(0);
				}
				Iterator<PessoaIMC> iter1 = pessoas.iterator();
					while(iter1.hasNext())
					{
			        	System.out.println(iter1.next());
			        }
			}
			catch(InputMismatchException e)
			{
				System.out.println("O argumento digitado é inválido.");
			}
		}
		catch (ExceptionInInitializerError e)
		{
			JOptionPane.showMessageDialog(null, null, "Erro ao executar o programa", JOptionPane.PLAIN_MESSAGE );
		}
	}
}