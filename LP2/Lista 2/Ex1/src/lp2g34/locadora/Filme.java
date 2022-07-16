package lp2g34.locadora;

public class Filme //
{
	String codigo,titulo,categoria;
	int qtd,alugados;
	public Filme (String codigo,String titulo,String categoria,int qtd,int alugados)
	{
		this.codigo = codigo;
		this.titulo = titulo;
		this.categoria = categoria;
		this.qtd = qtd;
		this.alugados = alugados;
	}
	public Filme (String titulo)
	{
		this.titulo = titulo;
	}
	public void aluga() throws CopiaNaoDisponivelEx
	{
		if (this.alugados > qtd)
		{
			throw new CopiaNaoDisponivelEx("Quantidade indispon√≠vel no estoque.");
		}
		else
		{
			this.alugados++;
		}
	}
	public void devolve() throws NenhumaCopiaAlugadaEx//getFilme.put(novoCliente.getCodigo(),novoCliente);iaAlugadaEx
	{
		if (this.alugados == 0)
		{
			throw new NenhumaCopiaAlugadaEx("Todos os filmes est√£o no estoque estoque.");
		}
		else
		{
			this.alugados--;
		}
	}
	public String toString()
	{
		return "CÛdigo do filme: "+codigo+"\nTÌtulo do filme: "+titulo+"\nCategoria do filme: "+categoria+"\nQuantidade de filmes: "+qtd+"\nQuantidade de filmes alugados: "+alugados;
	}
	public String getCodigo()
	{
		return codigo;
	}
}