package lp2g05;
import java.io.File;
import java.util.Scanner;
import lp2g05.locadora.Cliente;
import lp2g05.locadora.Filme;
import lp2g05.locadora.Locadora;

public class Principal{ 
	static Locadora locadora;

	//static void Locacao(Locadora minhaLocadora) throws CopiaNaoDisponivelEx, ClienteNaoCadastradoEx, FilmeNaoCadastradoEx, NenhumaCopiaAlugadaEx {
	public static Filme lerFilme(Scanner scanner){
		System.out.println("Digite o codigo do Filme: ");
		String cod = scanner.next();
		System.out.println("Digite o t�tulo do Filme: ");
		String titulo = scanner.next();
		System.out.println("Digite a categoria do Filme: ");
		String categoria = scanner.next();
		System.out.println("Digite a quantidade do Filme: ");
		String sqtd = scanner.next();
		int qtd2 = Integer.parseInt(sqtd);
		System.out.println("Digite a quantidade de \""+titulo+"\" que estao alugados: ");
		String salu = scanner.next();
		int alu = Integer.parseInt(salu);
		Filme filme = new Filme(cod, titulo, categoria, qtd2, alu);
		return filme;
	}
	public static Cliente lerCliente(Scanner scanner){
		int cod2;
		while(true){
			System.out.println("Digite o codigo do cliente: ");
			String cod = scanner.next();
			try{
				cod2 = Integer.parseInt(cod);
				break;
			}
			catch(Exception e){
				System.out.println(e.getMessage());
			}
		}
		System.out.println("Digite o nome do cliente: ");
		String nome = scanner.next();
		System.out.println("Digite a data de nascimento do cliente: ");
		String data = scanner.next();
		System.out.println("Digite o endereco do cliente: ");
		String end = scanner.next();
		Cliente cliente = new Cliente(nome, data, end, cod2);
		return cliente;
	}

	public static void main(String[] args){
		System.out.println("qualquer coisa");
		locadora = new Locadora();
		File f = new File("nome_do_arquivo.txt");
		if(f.exists()&&!f.isDirectory())
		{
			locadora.leArquivo();
		}
		while(true){
			System.out.print("Digite:" + "\n" 
					+ "(1)Cadastro" + "\n" + "(2)Alugar" + "\n" + "(3)Relatorio" 
					+ "\n" + "(4)Devolver" + "\n" + "(5)Salvar"+ "\n" +"(6)Sair" + "\n" );
			Scanner ler = new Scanner(System.in);
			int nlido;
			while(true){
				String numLeitura = ler.nextLine();
				try{	
					nlido = Integer.parseInt(numLeitura);
					break;
				}
				catch(NumberFormatException e){
					System.out.println("Por favor digite um numero"); 	
				}
			}
			String codf = "";
			switch(nlido){
			case 1:
				while(true){
					System.out.println("digite: (1)Filme ou (2)Cliente");
					String num = ler.next();
					int num2;
					try{
						num2 = Integer.parseInt(num);
						if(num2 == 1){
							locadora.cadastraFilme(lerFilme(ler));
							break;
						}
						else if(num2 == 2){
							locadora.cadastraCliente(lerCliente(ler));
							break;
						}
					}
					catch(Exception e){
						System.out.println(e.getMessage());

					}	
				}
				break;
			case 2:
				String codc;
				int codc2;
				while(true){
					System.out.println("digite o codigo do cliente: ");
					codc = ler.next();
					try{
						codc2 = Integer.parseInt(codc);
						break;
					}
					catch(Exception e){
						System.out.println(e.getMessage());
					}
				}

				System.out.println("digite o codigo do filme: ");
				codf = ler.next();// <<-- e isso

				Cliente cliente;
				Filme filme;
				try {
					cliente = locadora.getCliente(codc2);
					//filme = locadora.getFilme(codf);
					//locadora.alugaFilme(cliente, filme);
					System.out.println("Filme alugado com sucesso");
				} 	
				catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case 3:
				while(true){
					System.out.println("Digite (1)Filmes (2)Clientes");
					String num3 = ler.nextLine();
					int numero;
					try{
						numero = Integer.parseInt(num3);
						if(numero == 1){
							System.out.println(locadora.imprimeFilmes());

							break;
						}
						else{
							System.out.println(locadora.imprimeClientes());
							break;}
					}
					catch(Exception e){
						System.out.println(e.getMessage());
					}	
				}
				break;
			case 4:
				System.out.println("Digite o codigo do Filme: ");
				codf = ler.nextLine();// <<--- isso
				try {
					Filme film2 = locadora.getFilme(codf);
					film2.devolve();
					System.out.println("Filme devolvido com sucesso");
				}
				catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case 5:
				locadora.salvaArquivo();
				break;
			case 6:
				locadora.salvaArquivo();
				System.exit(0);
				ler.close();
				break;
			}		
		}
	}
}