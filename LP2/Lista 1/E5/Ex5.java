//Murilo de Jesus Santos Silva
import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException;
public class Ex5
{
	Scanner dado = new Scanner(System.in);
	int jogo,jogocc,jogomm;
	CaraCoroa cc = new CaraCoroa();
	MenorMaior mm = new MenorMaior();
	public void iniciar()
	{
		while (jogo != 1 || jogo != 2)
		{
			menuPrincipal();
			if (jogo == 1)
			{
				while (jogomm != 1 || jogomm != 0)
				{
					menuMenorMaior();
					if (jogomm == 1)
					{
						this.jogar(mm);
					}
					else if (jogomm == 2)
					{
						break;
					}
					else if (jogomm == 0)
					{
						finalizar();
					}
					else
					{
						while (jogomm > 2 || jogomm < 0)
						{	
							menuMenorMaior();
						}
						break;
					}
				}
			}
			else if (jogo == 2)
			{
				while (jogocc != 1 || jogocc != 0)
				{
					menuCaraCoroa();
					if (jogocc == 1)
					{
						this.jogar(cc);
					}
					else if (jogocc == 2)
					{
						break;
					}
					else if (jogocc == 0)
					{
						finalizar();
					}
					else
					{
						while (jogocc > 2 || jogocc < 0)
						{
							menuCaraCoroa();
						}
						break;
					}
				}
			}
			else if (jogo == 0)
			{
				finalizar();
			}
			else
			{
				System.out.println("Opção errada. Digite a opção novamente.");
			}
		}
	}
	public void jogar(JogoInterface j)
	{
		exibirPlacar(j.jogar());
	}
	public void exibirPlacar(Placar placar)
	{
		if (jogo == 1)
		{
			System.out.println("Quantidade de tentativas: "+mm.tentmm+"\nQuantidade de vitórias: "+mm.vitmm);
		}
		else if (jogo == 2)
		{
			System.out.println("Quantidade de tentativas: "+cc.tentcc+"\nQuantidade de vitórias: "+cc.vitcc);
		}
	}
	public void finalizar()
	{
		System.out.println("Obrigado por jogar. Espero que tenha gostado.");
		System.exit(0);
	}
	public void menuPrincipal()
	{
		try
		{
			System.out.println("\n=========Menu Principal=========\n\nO que você deseja jogar:\n1- Maior ou Menor\n2- Cara ou Coroa\n0- Sair do jogo");
			jogo = dado.nextInt();
		}
		catch(InputMismatchException e)
		{
			System.out.println("O argumento digitado não é um número.");
		}
	}
	public void menuMenorMaior()
	{
		try
		{
			System.out.println("\n\n=========Menor ou Maior=========\n\nO que você deseja:\n1- Jogar o Menor ou Maior\n2- Voltar ao menu principal\n0- Sair do programa");
			jogomm = dado.nextInt();
		}
		catch(InputMismatchException e)
		{
			System.out.println("O argumento digitado não é um número.");
			finalizar();
		}
	}
	public void menuCaraCoroa()
	{
		try
		{
			System.out.println("\n\n=========Cara ou Coroa=========\n\nO que você deseja:\n1- Jogar o Cara ou Coroa\n2- Voltar ao menu principal\n0- Sair do programa");
			jogocc = dado.nextInt();
		}
		catch(InputMismatchException e)
		{
			System.out.println("O argumento digitado não é um número.");
			finalizar();
		}
	}
	public static void main (String[] args)
	{
		Ex5 exec = new Ex5();
		exec.iniciar();
		exec.finalizar();
	}
}
