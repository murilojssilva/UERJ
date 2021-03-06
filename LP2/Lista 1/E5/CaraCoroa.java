import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException;
public class CaraCoroa implements JogoInterface
{
	Random sorteio = new Random();
	int tentcc = 0;
	public int vitcc = 0;
	Scanner dado = new Scanner(System.in);
	int sorteado = sorteio.nextInt(2)+1;
	public void resetar()
	{
		sorteado = sorteio.nextInt(2)+1;
	}
	public void abortar()
	{
		System.exit(0);
	}
	public Placar jogar()
	{
		int chute = 0;
		System.out.println("O jogo Cara ou Coroa começou...");
		tentcc++;
		try
		{
			System.out.println("Digite um número: 1- par 2- ímpar 0- Sair do jogo");
			chute = dado.nextInt();
		}
		catch(InputMismatchException e)
		{
			System.out.println("O argumento digitado não é um número");
		}
		resetar();
		if (chute == 0)
		{
			abortar();
		}
		else if (chute > 2 || chute < 0)
		{
			while (chute > 2 || chute < 0)		
			{			
				System.out.println("O argumento digitado não faz parte do jogo. Digite-o novamente:");
				chute = dado.nextInt();
			}
			
		}
		if (chute != sorteado)
		{
			System.out.println("Que pena, você errou.\n");
			resetar();
		}
		else
		{
			vitcc++;
			System.out.println("Parabéns, você acertou o número.\n");
		}
		sorteado = sorteio.nextInt(2)+1;
		Placar novoPlacar = new Placar("Veja o placar dessa rodada: "+tentcc);
		novoPlacar.setResultado();
		return novoPlacar;
	}
}
