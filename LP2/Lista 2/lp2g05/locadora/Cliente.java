package lp2g05.locadora;

import java.util.Vector;

public class Cliente extends Pessoa{
	String endereco;
	int codigoCliente;
	Vector<Aluguel> Historico;
	public Cliente(String nome, String dataNasc, String endereco, int codigoCliente) {
		super(nome, dataNasc);
		this.endereco = endereco;
		this.codigoCliente = codigoCliente;
		Historico = new Vector<Aluguel>();
	}
	public void adFilmeHist(String datadeLocacao, String datadeDevolucao, String codigodoFilme ){
		Aluguel aluguel = new Aluguel(datadeLocacao, datadeDevolucao, codigodoFilme);
		Historico.add(aluguel);
	}
	public String toString(){
		int i = 0; 
		String resp = ""; 
		for(i=0; i < Historico.size(); i++){
			resp += "\n" + Historico.get(i).toString();
		}
		return super.toString() + ", " + endereco + ", " + codigoCliente + resp;
			
	}
}
