public abstract class PessoaIMC extends Pessoa{

	protected double peso, altura;

	PessoaIMC(String nomePessoa, String dataNascimentoPessoa, double pesoPessoa, double alturaPessoa){
		super(nomePessoa,dataNascimentoPessoa);
		peso = pesoPessoa;
		altura = alturaPessoa;
	}


	public double getPeso(){
		return peso;
	}

	public double getAltura(){
		return altura;
	}

	public double calculaIMC(double altura, double peso){

		double valorIMC = peso/(altura*altura);
		return valorIMC;
	}

	public String toString(){
		String dados =  "\nNome: " +nome+ 
						"\nData de Nascimento: "+dataNascimento+
						"\nPeso: "+peso+
						"\nAltura: "+altura+"\n";
		return dados;
	}

	public abstract String resultIMC();
}
