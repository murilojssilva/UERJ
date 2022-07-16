package lp2g05.locadora;
import java.io.*;
import java.util.Collections;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.Scanner;

public class Locadora {
	Hashtable<Integer, Cliente> cadClientes;
	Hashtable<String, Filme> cadFilmes;
	String addrf = "lp2g34\\filmes.txt";
	String addrc = "lp2g34\\clientes.txt";
	public Locadora(){
		cadClientes = new Hashtable<Integer, Cliente>();
		cadFilmes = new Hashtable<String, Filme>();
	}
	int i = 0; 

	public void leArquivo()
	{
		try {
			Scanner scanner = new Scanner(new FileReader(addrf));
			while(scanner.hasNextLine())
			{
				String linha = scanner.nextLine();
				String[] campos = linha.split("/");
				String codf = campos[0];
				String titf = campos[1];
				String catf = campos[2];
				int qf = Integer.parseInt(campos[3]);
				int af = Integer.parseInt(campos[4]);
				Filme f = new Filme(codf, titf, catf, qf, af);
				cadFilmes.put(codf, f);
			}		
			scanner.close();
		}
		catch (FileNotFoundException e) {
			}
		try {
			Scanner scanner = new Scanner(new FileReader(addrc));
			while(scanner.hasNextLine())
			{
				String linha = scanner.nextLine();
				String[] campos = linha.split("/");
				int codc = Integer.parseInt(campos[0]);
				String nome = campos[1];
				String data = campos[2];
				String end = campos[3];
				String his = campos[4].substring(1);
				String[] alu = his.split(";");
				Cliente c = new Cliente(nome, data, end, codc);
				for(int i = 0 ; i<alu.length;i++)
				{
					if(alu[i].compareTo("")!=0)
						c.Historico.add(Aluguel.fromString(alu[i]));
				}
				cadClientes.put(codc, c);
			}		
			scanner.close();
		}
		catch (FileNotFoundException e) {
			}
	}
	public void salvaArquivo(){
		File arquivoFilme = new File( addrf );
		try {
			FileWriter fw = new FileWriter(arquivoFilme);
			BufferedWriter bw = new BufferedWriter( fw );
			Enumeration<String> k = cadFilmes.keys();
			for(i = 0; i < cadFilmes.size(); i++){
				String ch = k.nextElement();
				bw.write(cadFilmes.get(ch).codigodoFilme + '/' 
						+ cadFilmes.get(ch).titulodoFilme + '/' 
						+ cadFilmes.get(ch).categoria + '/' 
						+ cadFilmes.get(ch).quantidade + '/'
						+ cadFilmes.get(ch).alugados + '\n');
				}
			bw.close();
			fw.close();
			}
		catch (IOException e)
		{
			System.out.println("Erro ao escrever o arquivo filmes.txt");
		}
		File arquivoClientes = new File(addrc);
		try {
			FileWriter fw2 = new FileWriter(arquivoClientes);
			BufferedWriter bw2 = new BufferedWriter( fw2 );
			Enumeration<Integer> k2 = cadClientes.keys();
			for(i = 0; i < cadClientes.size(); i++){
				Integer ch2 = k2.nextElement();
				String his = " ";
				int t = cadClientes.get(ch2).Historico.size();
				for(int i = 0; i<t; i++)
				{
					his += cadClientes.get(ch2).Historico.get(i).toString();
				}
				bw2.write(ch2 + "/"
						+ cadClientes.get(ch2).nome + '/'
						+ cadClientes.get(ch2).dataNasc + '/'
						+ cadClientes.get(ch2).endereco + '/'
						+ his + '\n');
			}
			bw2.close();
			fw2.close();
		}
		catch (IOException e) 
		{
			System.out.println("Erro ao escrever o arquivo clientes.txt");
		}
	}
	public void cadastraCliente(Cliente cliente){
		cadClientes.put(cliente.codigoCliente, cliente);
	}
	public void cadastraFilme(Filme filme){
		cadFilmes.put(filme.codigodoFilme, filme);
	}

	public Cliente getCliente(int codigoCliente) throws Exception{
		Cliente c = cadClientes.get(codigoCliente);
		if(c != null)
			return c;
		else{
			throw new Exception("cliente nao cadastrado"); 
		}
	}
	public Filme getFilme(String codigodoFilme) throws Exception{
		Filme f = cadFilmes.get(codigodoFilme);
		if(f != null)
			return f;
		else{
			throw new Exception("filme nao cadastrado"); 
		}
	}

	public void alugaFilme(Cliente cliente, Filme filme) throws Exception{
		long time = System.currentTimeMillis();
		filme.aloca();
		cliente.adFilmeHist(Long.toString(time), Long.toString(time+345600000), 
				filme.codigodoFilme);
	}
	
	public String imprimeFilmes(){
		int j = 0;
		LinkedList<String> film = new LinkedList<>();
		Enumeration<String> k = cadFilmes.keys();
		for(j=0; j < cadFilmes.size() ;j++){
			String ch = k.nextElement(); 
			film.add(cadFilmes.get(ch).titulodoFilme);
			}
		Collections.sort(film);
		int i = 0;
		String resp = "";
		for(i=0; i < film.size(); i++){
			resp += film.get(i) + ", ";
		}
		return resp;
	}
	
	public String imprimeClientes(){
		int p = 0;
		LinkedList<String> client = new LinkedList<>();
		Enumeration<Integer> k = cadClientes.keys();
		for(p=0; p < cadClientes.size() ;p++){
			Integer ch = k.nextElement(); 
			client.add(cadClientes.get(ch).nome);
			}
		Collections.sort(client);
		int i = 0;
		String resp = "";
		for(i=0; i < client.size(); i++){
			resp += client.get(i) + ", ";
		}
		return resp;
	}
}