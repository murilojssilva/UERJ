

public class Homem extends PessoaIMC{
	double Imc = 0.0;
	//String frase;
	public Homem(String nome, String dataNascimento, double peso, double altura) {
		super(nome, dataNascimento, peso, altura);
		resultIMC();
	}
	public Resultado resultIMC() {
		Imc = calculaIMC();
		int dist;
		if(Imc < 20.7){
			super.frase = "IMC: " + Imc + " Abaixo do peso ideal";
			dist = (int) (21 - Imc);
			//System.out.println("IMC: " + Imc + " Abaixo do peso ideal");
		}
		else if(Imc > 20.7 && Imc < 26.4){
			super.frase = "IMC: " + Imc + " Peso Ideal";
			dist = 0;
			//System.out.println( "IMC: " + Imc + " Peso Ideal");
			
		} 
		else{
			super.frase = "IMC: " + Imc + " Acima do peso ideall";
			dist = (int) (26 - Imc);
			//System.out.println("IMC: " + Imc + " Acima do peso ideal");
			
		}
		return new Resultado(super.frase, dist);
	}
}
