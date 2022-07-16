public class Pessoa
{
	protected String nome, dataNascimento;
	public Pessoa(String nome,String dataNascimento)
	{
		this.nome = nome;
		this.dataNascimento = dataNascimento;
	}
	public String toString()
	{
		return "Nome: "+nome+"\nData de Nascimento: "+dataNascimento;
	}
}