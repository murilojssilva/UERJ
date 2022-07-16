package lp2g34.locadora;
public class Pessoa
{
	String nome,dataNasc;
	public Pessoa(String nome, String dataNasc)
	{
		this.nome = nome;
		this.dataNasc = dataNasc;
	}

	public String toString()
	{
		return "Nome: "+nome+"\nData de Nascimento: "+dataNasc+"\n";
	}
}