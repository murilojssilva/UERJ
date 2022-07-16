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
		return "Data da loca��o: "+dataLocacao+"\nData da devolu��o: "+dataDevolucao+"\nC�digo do Filme: "+codigoFilme;
	}
}
