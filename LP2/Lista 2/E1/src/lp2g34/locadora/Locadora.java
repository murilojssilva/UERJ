package lp2g34.locadora;
import java.util.*;
import java.io.*;
public class Locadora
{
	String addrf = "lp2g34\\filmes.txt";
	String addrc = "lp2g34\\clientes.txt";
	Scanner dado = new Scanner (System.in);
	Hashtable<Integer, Cliente> cadastroClientes = new Hashtable<Integer, Cliente>();
	Hashtable <String,Filme>cadastroFilmes = new Hashtable<String,Filme>();
	private BufferedReader br;
	public Locadora (Hashtable<Integer, Cliente> cadastroClientes, Hashtable<String, Filme> cadastroFilmes)
	{
		this.cadastroClientes = cadastroClientes;
		this.cadastroFilmes = cadastroFilmes;
	}
	public Locadora ()
	{
		cadastroClientes = new Hashtable <Integer, Cliente>();
		cadastroFilmes = new Hashtable <String, Filme>();
	}
	public void cadastraCliente(Cliente novoCliente)
	{
		novoCliente.codigo = dado.nextInt();
		cadastroClientes.put(novoCliente.getCodigo(),novoCliente);
	}
	public void cadastraFilme(Filme novoFilme)
	{
		novoFilme.codigo = dado.next();
		cadastroFilmes.put(novoFilme.getCodigo(),novoFilme);
	}
	public void salvaArquivo(Hashtable<?, ?> cadastro,String nomeArquivo)
	{
		File arquivoFilme = new File( addrf );
		try {
			FileWriter fw = new FileWriter(arquivoFilme);
			BufferedWriter bw = new BufferedWriter( fw );
			Enumeration<String> k = cadastroFilmes.keys();
			for(int i = 0; i < cadastroFilmes.size(); i++){
				String ch = k.nextElement();
				bw.write(cadastroFilmes.get(ch).codigo + '/' 
						+ cadastroFilmes.get(ch).titulo + '/' 
						+ cadastroFilmes.get(ch).categoria + '/' 
						+ cadastroFilmes.get(ch).qtd + '/'
						+ cadastroFilmes.get(ch).alugados + '\n');
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
			Enumeration<Integer> k2 = cadastroClientes.keys();
			for(int i = 0; i < cadastroClientes.size(); i++){
				Integer ch2 = k2.nextElement();
				String his = " ";
				int t = cadastroClientes.get(ch2).Historico.size();
				for(int j = 0; j<t; j++)
				{
					his += cadastroClientes.get(ch2).Historico.get(j).toString();
				}
				bw2.write(ch2 + "/"
						+ cadastroClientes.get(ch2).nome + '/'
						+ cadastroClientes.get(ch2).dataNasc + '/'
						+ cadastroClientes.get(ch2).endereco + '/'
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
	public void alugaFilme (Cliente clienteAluga, Filme filmeAlugado)
	{
		try
		{
			Calendar data = new GregorianCalendar(Calendar.YEAR,Calendar.MONTH,Calendar.DAY_OF_MONTH);
			Date dAlug = data.getTime();
			data.add(Calendar.DAY_OF_MONTH, 5);
			Date dDev = data.getTime();
			 
			filmeAlugado.aluga();
			clienteAluga.adFilmeHistorico(dAlug.toString(),dDev.toString(),filmeAlugado.getCodigo());
		}
		catch (CopiaNaoDisponivelEx e) 
		{
            System.out.println("Não há filmes no estoque.");
        }
	}
	public void devolveFilme (Cliente clienteDevolve, Filme filmeDevolvido) throws NenhumaCopiaAlugadaEx
	{
		try
		{
			Calendar data = new GregorianCalendar(Calendar.YEAR,Calendar.MONTH,Calendar.DAY_OF_MONTH);
			Date dAlug = data.getTime();
			data.add(Calendar.DAY_OF_MONTH, 5);
			Date dDev = data.getTime();
			filmeDevolvido.devolve();
			clienteDevolve.adFilmeHistorico(dAlug.toString(),dDev.toString(),filmeDevolvido.getCodigo());
		}
		catch (NenhumaCopiaAlugadaEx e) 
		{
            System.out.println("Todos os filmes estão no estoque.");
        }
	}
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
	public Cliente getCliente (String codigoCliente) throws ClienteNaoCadastradoEx
	{
		boolean temCliente = cadastroFilmes.get(codigoCliente) != null;
		if  (temCliente == true)
			return cadastroClientes.get(codigoCliente);
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