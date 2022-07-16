package lp2g05.locadora;

public class Filme {
	String codigodoFilme;
	String titulodoFilme;
	String categoria;
	int quantidade;
	int alugados;
	public Filme(String codigodoFilme, String titulodoFilme,String categoria,int quantidade,
			int alugados){
		this.codigodoFilme = codigodoFilme;
		this.titulodoFilme = titulodoFilme;
		this.categoria = categoria;
		this.quantidade = quantidade;
		this.alugados = alugados;
	}
	public Filme(String titulodoFilme){
		this.titulodoFilme = titulodoFilme;
	}
	public void aloca()throws Exception{
		alugados++;
		if(alugados >= quantidade){
			throw new Exception("CopiaNaoDisponivel");
		}
	}
	public void devolve()throws Exception{
		alugados--;
		if(alugados == 0){
			throw new Exception("NenhumaCopiaAlugada");
			}
	}	
	public String toString(){
		return codigodoFilme + ", " + titulodoFilme + ", " + categoria + ", " + quantidade 
				+ ", " + alugados;
	}
}
