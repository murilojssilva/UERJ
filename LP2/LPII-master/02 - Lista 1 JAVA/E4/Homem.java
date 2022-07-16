public class Homem extends PessoaIMC{

	@Override
	public String resultIMC(){
		
		String resultadoIMC = "";
		double valorIMC = peso/(altura*altura);

		if (valorIMC < 20.7){
			resultadoIMC = ""+valorIMC+" Abaixo do peso ideal";
		}
		else if((valorIMC > 20.7)  && (valorIMC < 26.4)){
			resultadoIMC = ""+valorIMC+" Peso Ideal";
		}
		else if(valorIMC > 26.4){
			resultadoIMC = ""+valorIMC+" Acima do peso ideal";
		}

		return resultadoIMC;
	}

	Homem(String nomePessoa, String dataNascimentoPessoa, double pesoPessoa, double alturaPessoa){
		super(nomePessoa,dataNascimentoPessoa,pesoPessoa,alturaPessoa);
	}

	public String toString(){

		String resultadoIMCdoHomem = "\nNome: " +nome+ 
						"\nData de Nascimento: "+dataNascimento+
						"\nPeso: "+peso+
						"\nAltura: "+altura+
						"\nIMC: "+resultIMC()+"\n";
		return resultadoIMCdoHomem;
	}
}