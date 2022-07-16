
public class Mulher extends PessoaIMC{
	double Imc;
	String frase;
	public Mulher(String nome, String dataNascimento, double peso, double altura){
		super(nome, dataNascimento, peso, altura);
		resultIMC();
	}
	
	public Resultado resultIMC(){
		Imc = calculaIMC();
		int dist;
		if(Imc < 19){
			super.frase = "IMC: " + Imc +" Abaixo do peso ideal";
			dist = (int) (19 - Imc);
		}
		else if(Imc > 19 && Imc < 25.8){
			super.frase = "IMC: " + Imc + " Peso Ideal";
			dist = 0;
		} 
		else{
			super.frase = "IMC: " + Imc + " Acima do peso ideal";
			dist = (int) (25 - Imc);
		}
		return new Resultado(super.frase, dist);
	}

}
