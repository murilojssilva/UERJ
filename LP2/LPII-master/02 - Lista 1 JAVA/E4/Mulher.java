public class Mulher extends PessoaIMC{

	@Override
	public String resultIMC(){
		
		String resultadoIMC = "";
		double valorIMC = peso/(altura*altura);

		if (valorIMC < 19){
			resultadoIMC = ""+valorIMC+" Abaixo do peso ideal";
		}
		else if((valorIMC > 19)  && (valorIMC < 25.8)){
			resultadoIMC = ""+valorIMC+" Peso Ideal";
		}
		else if(valorIMC > 25.8){
			resultadoIMC = ""+valorIMC+" Acima do peso ideal";
		}

		return resultadoIMC;
	}

	Mulher(String nomePessoa, String dataNascimentoPessoa, double pesoPessoa, double alturaPessoa){
		super(nomePessoa,dataNascimentoPessoa,pesoPessoa,alturaPessoa);
	}

	public String toString(){

		String resultadoIMCdaMulher = "\nNome: " +nome+ 
						"\nData de Nascimento: "+dataNascimento+
						"\nPeso: "+peso+
						"\nAltura: "+altura+
						"\nIMC: "+resultIMC()+"\n";
		return resultadoIMCdaMulher;
	}
}