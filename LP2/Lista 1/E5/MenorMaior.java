import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException;
public class MenorMaior implements JogoInterface
{
	Random sorteio = new Random();
	int tentmm = 0;
	public int vitmm = 0;
	Scanner dado = new Scanner(System.in);
	int sorteado = sorteio.nextInt(99)+1;
	public void resetar()
	{
		sorteado = sorteio.nextInt(99)+1;
	}
	public void abortar()
	{
		System.exit(0);
	}
	public Placar jogar()
	{
		int chute = 0;
		System.out.println("O jogo Maior Menos começou...");
		do
		{
			tentmm++;
			try
			{
				System.out.println("Digite um número entre 1 e 100: (0- Sair do jogo)");
				chute = dado.nextInt();
			}
			catch(InputMismatchException e4)
			{
				System.out.println("O argumento digitado não é um número");
			}
			if (chute == 0)
			{
				abortar();
			}
			else if (chute > 2 || chute < 0)
			{
				while (chute > 100 || chute < 0)		
				{			
					System.out.println("O argumento digitado não faz parte do jogo. Digite-o novamente:");
					chute = dado.nextInt();
				}		
			}
			if (chute > sorteado)
			{
				System.out.println("Esse número é maior que o sorteado");
			}
			else if (chute < sorteado)
			{
				System.out.println("Esse número é menor que o sorteado");
			}
			else
			{
				System.out.println("Parabéns, você acertou o número");
				break;
			}
			
		}while(chute != sorteado);
		resetar();
		vitmm++;
		Placar novoPlacar = new Placar("Veja o placar dessa rodada: "+tentmm);
		novoPlacar.setResultado();
		return novoPlacar;
	}
}
