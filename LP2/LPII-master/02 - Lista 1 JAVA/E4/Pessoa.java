public class Pessoa{
		
	protected String nome, dataNascimento;

	Pessoa(String nomePessoa, String dataNascimentoPessoa){
		nome = nomePessoa;
		dataNascimento = dataNascimentoPessoa;
	}

	public String toString(){
		String dados = "\nNome: " +nome+ 
						"\nPessoa: "+dataNascimento+"\n";
		return dados;
	}
}