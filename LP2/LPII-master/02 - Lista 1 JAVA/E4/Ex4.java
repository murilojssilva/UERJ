import java.util.Scanner;
import java.util.Vector;
import java.util.Iterator;
import java.util.InputMismatchException;

public class Ex4{

	private static Scanner sc = new Scanner(System.in);
	private static String nomePessoa, dataNascimentoPessoa, pesoPessoaString, alturaPessoaString;
	private static double pesoPessoa, alturaPessoa;


	public static void main(String[] args) {
		
		Vector<PessoaIMC> vector = new Vector<PessoaIMC>();
		int nPessoas = 0;

		boolean verificaPessoas = false;
		while (verificaPessoas == false){

			try{
				System.out.println("Digite o numero de pessoas: ");
				nPessoas = sc.nextInt();
				sc.nextLine();			

				if (nPessoas <= 0){
					System.out.println("Número de pessoas inválido!");
				}
				else{
					for (int i = 0; i < nPessoas; i++) {

						boolean verificaSexo = false;
						while (verificaSexo == false){
							System.out.println("Inserir homem (h) ou mulher (m)?");
							String sexo = sc.next();
							sc.nextLine();

							if (sexo.compareTo("h") == 0){
								entradaDeDados();
								Homem homem = new Homem(nomePessoa,dataNascimentoPessoa,pesoPessoa,alturaPessoa);
								vector.add(homem);
								verificaSexo = true;
							}
							else if (sexo.compareTo("m") == 0){
								entradaDeDados();
								Mulher mulher = new Mulher(nomePessoa,dataNascimentoPessoa,pesoPessoa,alturaPessoa);
								vector.add(mulher);
								verificaSexo = true;
							}
							else{
								System.out.println("Sexo invalido!");
							}
							verificaPessoas = true;
						}
					}
				}	
			}
			catch(InputMismatchException e){
				System.out.println("Você entrou com um dado inválido! Tente novamente!");
				String limpaBuff = sc.next();
			}
		}

    	Iterator it = vector.iterator();
  
    	System.out.println("----------");
    	while(it.hasNext()){
			System.out.println(it.next());
		}
	}

	public static void entradaDeDados(){

		System.out.println("Digite o nome: ");
		nomePessoa = sc.nextLine();

		System.out.println("Digite a data de nascimento: ");
		dataNascimentoPessoa = sc.nextLine();

		boolean verificaPeso = false;
		while (verificaPeso == false){
			try{
				System.out.println("Digite o peso: ");
				pesoPessoaString = sc.nextLine();
				pesoPessoa = Double.parseDouble(pesoPessoaString);
				if (pesoPessoa <= 0){
					System.out.println("O peso deve ser maior que 0!");
				}
				else{
					verificaPeso = true;
				}
			}
			catch(NumberFormatException e){
				System.out.println("O numero digitado deve usar ponto (.) e ser real!");
			}
		}

		boolean verificaAltura = false;
		while (verificaAltura == false){
			try{
				System.out.println("Digite a altura (em metros): ");
				alturaPessoaString = sc.nextLine();
				alturaPessoa = Double.parseDouble(alturaPessoaString);
				if (alturaPessoa <= 0){
					System.out.println("O peso deve ser maior que 0!");
				}
				else{
					verificaAltura = true;
				}
			}
			catch(NumberFormatException e){
				System.out.println("O numero digitado deve usar ponto (.) e ser real!");
			}
		}
	}
}