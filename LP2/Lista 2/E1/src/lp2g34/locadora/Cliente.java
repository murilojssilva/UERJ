package lp2g34.locadora;
import java.util.*;
public class Cliente extends Pessoa
{
	Scanner dado = new Scanner(System.in);
	String endereco;
	int codigo;
	Vector<Aluguel> Historico = new Vector<Aluguel>();
	public Cliente (String nome,String dataNasc,String endereco, int codigo)
	{
		super(nome,dataNasc);
		this.endereco = endereco;
		this.codigo = codigo;
	}
	public void adFilmeHistorico(String dataLocacao,String dataDevolucao,String codigoFilme)
	{
		Aluguel novoAluguel = new Aluguel (dataLocacao,dataDevolucao,codigoFilme);
		Historico.add(novoAluguel);
	}
	public int getCodigo()
	{
		return codigo;
	}
	public String toString()
	{
		return super.toString()+"\nEndereço do cliente: "+endereco+"\nCódigo do cliente: "+codigo;
	}
	public Vector<Aluguel> getHistorico ()
	{
		return Historico;
	}
}