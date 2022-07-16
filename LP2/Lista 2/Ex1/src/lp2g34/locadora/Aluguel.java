package lp2g34.locadora;
public class Aluguel
{
	String dataLocacao,dataDevolucao,codigoFilme;
	public Aluguel(String dataLocacao,String dataDevolucao,String codigoFilme)
	{
		this.dataLocacao = dataLocacao;
		this.dataDevolucao = dataDevolucao;
		this.codigoFilme = codigoFilme;
	}
	public String toString()
	{
		return "Data da locação: "+dataLocacao+"\nData da devolução: "+dataDevolucao+"\nCódigo do Filme: "+codigoFilme;
	}
}
