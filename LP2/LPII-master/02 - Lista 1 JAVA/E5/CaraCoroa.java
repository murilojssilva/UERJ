import java.util.Random;
import java.util.Scanner;

public class CaraCoroa implements JogoInterface {

	private Random moeda = new Random();
	private String face;
	private int  numero, vitorias;
	private static Placar placar;
	private static Scanner sc = new Scanner(System.in);
	
	public CaraCoroa(){
		numero = moeda.nextInt(2)+1;
		if(numero == 1){
			this.face = "Cara";	
		} 
		else{
			this.face = "Coroa";	
		} 
	}
	
			
	public void resetar() {
		numero = moeda.nextInt(2)+1;
		if(numero == 1){
			this.face = "Cara";	
		} 
		else{
			this.face = "Coroa";
		}
		jogar();		
	}

	public Placar jogar() {
		CaraCoroa jogo = new CaraCoroa();
			
		int tentativa;
		while (true) {
			try {
				System.out.println("\n[CARA OU COROA]\nQual lado da moeda deseja escolher:\n 1 - Cara\n 2 - Coroa\n 0 - Sair do Jogo \n");
				tentativa = Integer.parseInt(sc.nextLine());
				if (tentativa < 0 || tentativa > 2){
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
			return placar = new Placar(String.valueOf(false), "0", String.valueOf(jogo.face));
		}
		else if (tentativa == jogo.numero) {
			return placar = new Placar(String.valueOf(true), "1", String.valueOf(jogo.face));
		}
		else{
			return placar = new Placar(String.valueOf(false), "1", String.valueOf(jogo.face));	
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
