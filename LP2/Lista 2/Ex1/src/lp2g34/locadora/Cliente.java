package lp2g34.locadora;
import java.util.*;
import java.text.*;
import java.util.Vector;
public class Cliente extends Pessoa
{
	Scanner dado = new Scanner(System.in);
	String endereco;
	int codigoCliente;
	Vector<Aluguel> Historico = new Vector<Aluguel>();
	public Cliente (String nome,String dataNasc,String endereco, int codigoCliente)
	{
		super(nome,dataNasc);
		this.endereco = endereco;
		this.codigoCliente = codigoCliente;
	}
	public void adFilmeHistorico(String dataLocacao,String dataDevolucao,String codigoFilme)
	{
		Aluguel novoAluguel = new Aluguel (dataLocacao,dataDevolucao,codigoFilme);
		Date data = new Date();
		DateFormat formato = new SimpleDateFormat("HH/mm/ss.SSS");  
		novoAluguel.dataLocacao = formato.format(data);  
		novoAluguel.dataDevolucao = formato.format(data);
		System.out.println("Código do filme: ");
		novoAluguel.codigoFilme = dado.next();
		Historico.add(novoAluguel);
	}
	public int getCodigo()
	{
		return codigoCliente;
	}
	public String toString()
	{
		return super.toString()+"\nEndereço do cliente: "+endereco+"\nCódigo do cliente: "+codigoCliente;
	}
};