package lp2g34.locadora;

import java.io.*;
import java.util.*;
public class Ex1 
{
	private static Scanner dado = new Scanner(System.in);
	private static Locadora minhaLocadora;
	public static void main(String[] args) throws FileNotFoundException, IOException, CopiaNaoDisponivelEx, ClienteNaoCadastradoEx, FilmeNaoCadastradoEx, NenhumaCopiaAlugadaEx {
		int opcao;
		String cadastroFilme,cadastroCliente;
		while(true)
		{
			System.out.println("=========Menu Principal=========\n\nO que você deseja:\n1- Abrir Locadora\n2 - Criar nova locadora");
			opcao = dado.nextInt();
			if(opcao == 1)
			{
				try
				{
					System.out.println("Digite o nome do arquivo:\n1- De filmes (com .txt): ");
					cadastroFilme = dado.next();
					System.out.println("2- De cliente (com .txt): ");
					cadastroCliente = dado.next();
					minhaLocadora = new Locadora();
					minhaLocadora.leArquivo(cadastroFilme);
					minhaLocadora.leArquivo(cadastroCliente);
					break;
				}
				catch (Exception e)
				{
					System.out.println("Erro ao ler o arquvo");
				}
			}
			else if(opcao == 2)
			{
				minhaLocadora = new Locadora();
				break;
			}
			else{
				System.out.println("Opcao invalida!");
			}
		}
		
		System.out.println("Locadora");
		while(true)
		{
			System.out.println("=========Menu Locadora=========\n\nO que você deseja fazer\n1 - Manutenção\n2 - Cadastro\n3 - Locação\n4 - Exibir Relatorio\n5 - Sair");
			opcao = dado.nextInt();
			
			if(opcao == 1)
			{
				Manutencao(minhaLocadora);
			}
			else if(opcao == 2)
			{
				Cadastro(minhaLocadora);
			}
			else if(opcao == 3)
			{
				Locacao(minhaLocadora);
			}
			else if(opcao == 4)
			{
				Relatorio(minhaLocadora);
			}
			else if(opcao == 5)
			{
				System.out.println("O sistema foi encerrado!");
				break;
			}
			else
			{
				System.out.println("Opção inválida. Digite novamente\n");
			}
		}
	}
	static void Cadastro(Locadora minhaLocadora)
	{
		String endereco, nome, dataNasc,codigoFilme,titulo,categoria;
		int codigoCliente,opcao, opcaoSalvar,qtdFilmes,alugados = 0;
		while (true) 
		{	
			System.out.println("\n=========Menu de Cadastro=========\n\nO que você deseja cadastrar:\n1 - Clientes\n2 - Filmes\n3 - Salvar");
			opcao = dado.nextInt();
			if (opcao == 1)
			{
				System.out.println("Digite:\n Código do cliente: ");
				codigoCliente = dado.nextInt();
				System.out.println("Nome: ");
				nome = dado.nextLine();
				System.out.println("Endereço: ");
				endereco = dado.nextLine();
				System.out.println("Data de nascimento: ");
				dataNasc = dado.next();
				Cliente cliente = new Cliente(nome,dataNasc,endereco,codigoCliente);
				minhaLocadora.cadastraCliente(cliente);
				System.out.println("Cliente cadastrado.");
				break;
			}
			else if (opcao == 2) 
			{
				System.out.println("Digite:\n Código do filme: ");
				codigoFilme = dado.next();
				System.out.println("Título: ");
				titulo = dado.next();
				System.out.println("Categoria: ");
				categoria = dado.next();
				while (true) 
				{
					try 
					{
						System.out.println("Quantidade de filmes: ");
						qtdFilmes = dado.nextInt();
						break;
					} 
					catch (NumberFormatException e)
					{
						System.out.println("Digite um número inteiro.");
					}
				}
				alugados++;
				Filme filme = new Filme(codigoFilme,titulo,categoria,qtdFilmes,alugados);
				minhaLocadora.cadastraFilme(filme);
				System.out.println("Filme cadastrado.");
				break;
			}
			else if (opcao == 3)
			{
				while (true) 
				{		
					System.out.println("\n=========Menu Salvar=========\n\nO que você deseja salvar?\n1 - Catálogo de filmes\n2 - Catálogo de clientes");
					opcaoSalvar = dado.nextInt();
					if (opcaoSalvar == 1) 
					{
						minhaLocadora.salvaArquivo(null, "filmes");
						System.out.println("Arquivo salvo!");
						break;
					}
					else if (opcaoSalvar == 2) {
						minhaLocadora.salvaArquivo(null, "clientes");
						System.out.println("Arquivo salvo!");
						break;
					}

					else 
					{
						System.out.println("Opcao invalida!");
					}
				}
				break;
			}
			
			else {
				System.out.println("Opcao invalida!");
			}
		}
	}
	
	public static void Manutencao(Locadora minhaLocadora) throws IOException
	{
		try 
		{
			minhaLocadora.leArquivo("Filmes.txt");
			minhaLocadora.leArquivo("Clientes.txt");
			System.out.println("Relação de clientes \n");
			System.out.println(minhaLocadora.imprimeClientes());
			System.out.println("Relação de Filmes: \n");
			System.out.println(minhaLocadora.imprimeFilmes());
		} 
		catch (FileNotFoundException e) 
		{
			System.out.println("Arquivo nao encontrado!");
		}
		minhaLocadora.salvaArquivo(null,"clientes");
		minhaLocadora.salvaArquivo(null, "filmes");
		System.out.println("Relação de clientes e de filmes atualizada.");
	}
	static void Locacao(Locadora minhaLocadora) throws CopiaNaoDisponivelEx, ClienteNaoCadastradoEx, FilmeNaoCadastradoEx, NenhumaCopiaAlugadaEx {
		int opcao;
		while (true)
		{
			System.out.println("\n=========Menu Locação=========\n\nO que você deseja\n1 - Cadastrar um filmes\n2 - Alugar um filme\n3 - Devolver um filme");
			opcao = dado.nextInt();
			
			if (opcao == 1)
			{
				try
				{
					System.out.println(minhaLocadora.imprimeFilmes());
					break;
				}
				catch(ClassCastException e)
				{
					System.out.println("Formato de arquivo inválido");
				}
			}

			else if (opcao == 2)
			{
				String codigoCliente, codigoFilme;
				Cliente cliente;
				Filme filme;
				
				while (true) 
				{
					try 
					{
						System.out.println("Digite o codigo do cliente: ");
						codigoCliente = dado.next();
						cliente = minhaLocadora.getCliente(codigoCliente);
						break;
					}
					catch (ClienteNaoCadastradoEx e) 
					{
						System.out.println("Cliente Não cadastrado no sistema");
					} 	
				}
				try
				{
					if(cliente.getHistorico().size() == 5)
					{
						throw new LimiteDeAluguelExcedidoEx("Todos os filmes estão alugados.");
					}
				}
				catch(LimiteDeAluguelExcedidoEx e)
				{
					System.out.println("Limite de aluguel excedido. Não foi possível alugar");
					break;
				}
				while(true)
				{
					try
					{
						System.out.println("Digite o codigo do filme: ");
						codigoFilme = dado.next();
						filme = minhaLocadora.getFilme(codigoFilme);
						break;
					}
					catch (FilmeNaoCadastradoEx e) 
					{
						System.out.println("Filme não cadastrado no sistema");
					}
				}
				minhaLocadora.alugaFilme(cliente,filme);
				System.out.println("Filme alugado com sucesso!");
				break;
			}
			else if (opcao == 3) 
			{
				String codigoFilme;
				Filme filme;
				while (true) 
				{
					try 
					{
						System.out.println("Digite o codigo do filme: ");
						codigoFilme = dado.next();
						filme = minhaLocadora.getFilme(codigoFilme);
						break;
					} 
					catch (FilmeNaoCadastradoEx e) {
						System.out.println("Filme não cadastrado no sistema.");
					}
				}
				try{
					filme.devolve();
					System.out.println("Filme devolvido.");
					break;
				}
				catch (NenhumaCopiaAlugadaEx e) {
					System.out.println("Todos os filmes estão no catálogo");
					break;
				}
			}
			else
			{
				System.out.println("Opcao invalida!");
			}
		}
	}
	static void Relatorio(Locadora minhaLocadora)
	{	
		String opcao;
		while(true)
		{
			System.out.println("Selecione a opcao da operacao desejada: \n1 - Mostrar o catálogo de filmes\n2 - Listar cadastro de clientes\n[3] - Verificar historico de cliente:");
			opcao = dado.next();

			if(opcao == "1")
			{
				try
				{
					System.out.println(minhaLocadora.imprimeFilmes());
					break;
				}
				catch(ClassCastException e)
				{
					System.out.println("Formato de arquivo invalido.");
				}
			}
			else if(opcao == "2")
			{
				try
				{
					System.out.println(minhaLocadora.imprimeClientes());
					break;
				}
				catch(ClassCastException e)
				{
					System.out.println("Formato de arquivo invalido.");
				}
			}
			else if(opcao == "3")
			{	
				Cliente cliente;
				String codigo;
				try
				{
					System.out.println("Digite o codigo do cliente: ");
					codigo = dado.nextLine();
					cliente = minhaLocadora.getCliente(codigo);
					System.out.println(cliente.getHistorico());
					break;
				}
				catch(ClienteNaoCadastradoEx e)
				{
					System.out.println("Cliente não cadastrado no sistema");
				}
				catch(ClassCastException e)
				{
					System.out.println("Formato de arquivo inválido");
				}
			}
			else
			{
				System.out.println("Opção inválida");
			}
		}
	}
}