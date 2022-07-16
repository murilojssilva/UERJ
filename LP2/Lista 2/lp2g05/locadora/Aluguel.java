package lp2g05.locadora;

public class Aluguel {
	String  datadeLocacao;
	String datadeDevolucao;
	String codigodoFilme;
	public Aluguel(String  datadeLocacao, String datadeDevolucao, String codigodoFilme){
		this.datadeDevolucao = datadeDevolucao;
		this.datadeLocacao = datadeLocacao;
		this.codigodoFilme = codigodoFilme;
	}
	public String toString(){
		return datadeLocacao + ", " + datadeDevolucao + ", " + codigodoFilme;
	}
	public static Aluguel fromString(String texto)
	{
		String[] args = texto.split(", ");
		if(args.length==3)
			return new Aluguel(args[0], args[1], args[2]);
		else 
			return null;
	}
	
}
