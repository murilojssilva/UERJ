package lp2g05.locadora;

public class Pessoa {
	String nome;
	String dataNasc;
	public Pessoa(String nome, String dataNasc){
		this.nome = nome;
		this.dataNasc = dataNasc;
	}
	public String toString(){
		return nome + ", " +dataNasc;
	}

}
