
public class pessoa {
	protected String nome; //ou tem que ser private?
	protected String dataNascimento; // ou tem que ser private?
	 
	public pessoa(String nome, String dataNascimento){
		this.nome = nome;
		this.dataNascimento = dataNascimento;
	}
	public String toString(){
		return "Nome" + nome + "\n" + "Data de Nascimento" + dataNascimento ;
	}
	
}
