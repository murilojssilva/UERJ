package lp2g34.locadora;
import java.util.*;
import java.io.*;
public class Locadora
{
	Scanner dado = new Scanner (System.in);
	Hashtable <Integer,Cliente> cadastroClientes = new Hashtable<Integer, Cliente>();
	Hashtable <String,Filme>cadastroFilmes = new Hashtable<String,Filme>();
	private BufferedReader br;
	public Locadora (Hashtable <String,Filme>cadastroFilmes,Hashtable<Integer,Cliente> cadastroClientes)
	{
		this.cadastroFilmes = cadastroFilmes;
		this.cadastroClientes = cadastroClientes;
	}
	public Locadora() throws IOException
	{
		BufferedReader cl = new BufferedReader (new FileReader("Cliente.txt"));
		BufferedReader fi = new BufferedReader (new FileReader("Filme.txt"));
		try
		{
			while (cl.ready())
			{
				String linhac = cl.readLine();
				System.out.println(linhac);
			}
			while (fi.ready())
			{
				String linhaf = fi.readLine();
				System.out.println(linhaf);
			}
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Arquivo n�o encontrado.");
		}
	}
	public void cadastraCliente(Cliente novoCliente)
	{
		novoCliente.codigoCliente = dado.nextInt();
		cadastroClientes.put(novoCliente.getCodigo(),novoCliente);
	}
	public void cadastraFilme(Filme novoFilme)
	{
		novoFilme.codigo = dado.next();
		cadastroFilmes.put(novoFilme.getCodigo(),novoFilme);
	}
	/*public void salvaArquivo(Hashtable <String,Filme>cadastroFilmes,String nomeArquivo)
	{

		File arq = new File(nomeArquivo);
		String nome,conteudo;
		try
		{
			FileWritter f = new FileWritter (file,true);
			for (int i = 0;i < cadastroFilmes)
			{
				nome = cadastroFilmes.get(i);
				conteudo += "\r\n";
				f.write(conteudo);
			}
			f.close();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		catch (UserException e)
		{
			e.printStackTrace();
		}
	}*/
	public void leArquivo(String nomeArquivo) throws IOException
	{
		FileInputStream stream = new FileInputStream(nomeArquivo);
		InputStreamReader reader = new InputStreamReader(stream);
		br = new BufferedReader(reader);
		String linha = br.readLine();
		while (linha != null)
		{
			linha = br.readLine();
		}
	}
	/*public void alugaFilme (Cliente clienteAluga, Filme filmeAlugado)
	{
		filmeAlugado.aluga();
		clienteAluga.adFilmeHistorico().dataLocacao;
	}
	public void devolveFilme (Cliente clienteDevolve, Filme filmeDevolvido)
	{
		filmeDevolvido.devolve();
		clienteDevolve.adFilmeHistorico().dataDevolucao;
	}*/
	public String imprimeFilmes()
	{
		return "Filmes: "+cadastroFilmes;
	}
	public String imprimeClientes()
	{
		return "Clientes: "+cadastroClientes;
	}
	public Filme getFilme (String cod) throws FilmeNaoCadastradoEx
	{
		boolean temFilme = cadastroFilmes.get(cod) != null;
		if (temFilme == true)
			return cadastroFilmes.get(cod);
		else
			throw new FilmeNaoCadastradoEx ("Filme não cadastrado");
	}
	public Cliente getCliente (int cod) throws ClienteNaoCadastradoEx
	{
		boolean temCliente = cadastroFilmes.get(cod) != null;
		if  (temCliente == true)
			return cadastroClientes.get(cod);
		else
			throw new ClienteNaoCadastradoEx ("Cliente não cadastrado");
	}
	public Hashtable<Integer, Cliente> getCliente()
	{
		return cadastroClientes;
	}
	public Hashtable<String,Filme> getFilmes()
	{
		return cadastroFilmes;
	}
}