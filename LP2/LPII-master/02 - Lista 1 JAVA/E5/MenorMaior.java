import java.util.Random;
import java.util.Scanner;

public class MenorMaior implements JogoInterface {
	
	private Random gera = new Random();
	private int numero, vitorias;
	private static Placar placar;
	private static Scanner sc = new Scanner(System.in);
	
	public MenorMaior(){
		this.numero = gera.nextInt(99) + 1;
	}
	
	public void resetar() {
		this.numero = gera.nextInt(99) + 1;
		jogar();	
	}

	public Placar jogar() throws NumberFormatException {	
		MenorMaior jogo = new MenorMaior();
		
		int tentativa, cont = 0;
		
		while (true) {
			while (true) {
				try {

					System.out.println("\n[MAIOR OU MENOR]\nEscolha um numero de 1 a 100:\n 0 - Sair do Jogo\n");
					tentativa = Integer.parseInt(sc.nextLine());
					if (tentativa < 0 || tentativa > 100){
						System.out.println("Numero invalido");
					}
					else{	
						break;
					}
				} 
				catch (NumberFormatException erro) {
					System.out.println("Digite apenas numeros!");
				}
			}
			if (tentativa == 0){
				abortar();
				return placar = new Placar(String.valueOf(false), String.valueOf(cont), String.valueOf(jogo.numero));
			}
			else if (tentativa == jogo.numero) {
				cont += 1;
				return placar = new Placar(String.valueOf(true), String.valueOf(cont), String.valueOf(jogo.numero));
			}	
			else if(tentativa > jogo.numero){
				System.out.println("O numero digitado eh MAIOR que o sorteado!");
				cont +=1;
			}
			else if(tentativa < jogo.numero) {
				System.out.println("O numero digitado eh MENOR que o sorteado!");
				cont +=1;
			}
		}		
	}

	public void abortar() {
		System.out.println("\nVoce desistiu!");
	}
	
	public void setVitorias(){
		vitorias = placar.getNumVitorias();
	}
	
	public int getVitorias(){
		setVitorias();
		return vitorias;
	}	
}