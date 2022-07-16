import java.util.Scanner;
import javax.swing.JOptionPane;

public class Ex5 {
	
	private static Scanner sc = new Scanner(System.in);
	private static CaraCoroa caraCoroa;
	private static MenorMaior menorMaior;
	private static int vitorias, total, vezesJogadasCaraCoroa = 0, vezesJogadasmenorMaior = 0, vitoriasCaraCoroa = 0, vitoriasmenorMaior = 0;
	private static String avalia;

	public static void iniciar(){
		
		int opcao;
		boolean executa = true;
		
		while (executa) {
			try {
				System.out.println("\n[MENU PRINCIPAL]\nQual jogo deseja jogar:\n 1 - Cara ou Coroa\n 2 - Maior ou Menor\n 0 - Sair do Programa \nDigite uma das opcoes acima:");
				opcao = Integer.parseInt(sc.nextLine());

				switch (opcao) {
					case 0: {
						finalizar();
						executa = false;
						break;
					}
					case 1: {
						caraCoroa = new CaraCoroa();
						vezesJogadasCaraCoroa += 1;
						jogar(caraCoroa);
						vitoriasCaraCoroa += caraCoroa.getVitorias();
						break;
					}
					case 2: {
						menorMaior = new MenorMaior();
						vezesJogadasmenorMaior += 1;
						jogar(menorMaior);
						vitoriasmenorMaior += menorMaior.getVitorias();
						break;
					}
					default: {
						System.out.println("Opcao invalida!");
						break;
					}
				}
			} 
			catch (NumberFormatException e) {
				System.out.println("Digite apenas numeros!");
			}
		}
	}	
	
	
	public static void jogar(JogoInterface jogo){
		exibirPlacar(jogo.jogar());		
	}
	
	public static void exibirPlacar(Placar placar){
		String msg = placar.isVenceu() ? "\n[VITORIA]\nVoce venceu! :)" : "\n[DERROTA]\nVoce perdeu! :(";
		System.out.println(msg + "\nNumero de tentativas: [" + placar.getNumTentativas() + "]\nValor sorteado: [" + placar.getSorteado()+"]");
	}

	public static void finalizar(){
		total = vezesJogadasCaraCoroa + vezesJogadasmenorMaior;
		vitorias = vitoriasCaraCoroa + vitoriasmenorMaior;
		System.out.println("\n>>>>>>>>>>>>>>>>>>>>>[Resultado Final]<<<<<<<<<<<<<<<<<<<<<\n");
		System.out.println("Voce jogou " + total + " vezes!\n" + vezesJogadasCaraCoroa + " vezes o jogo Cara ou Coroa e " + vezesJogadasmenorMaior + " vezes o jogo Maior ou Menor!\n");
		System.out.println("Voce venceu " + vitorias + " vezes!\n" + vitoriasCaraCoroa + " vezes o jogo Cara ou Coroa e " + vitoriasmenorMaior + " vezes o jogo Maior ou Menor!\n");
		System.out.println("[AVALIE]\nEscreva uma mensagem sobre o que achou do programa:\n");
		avalia = sc.nextLine();
		System.out.println("\n **********[ Obrigado por utilizar o JotaGames 1.0 ]**********\n");
	}
	
	public static void main(String[] args) {
		Ex5 play = new Ex5();		
		play.iniciar();   
	}	
}
