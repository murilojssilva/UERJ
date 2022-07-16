
import java.lang.Math;

abstract public class PessoaIMC extends pessoa{
	protected double peso; // tem que ser private?
	protected double altura; // tem ser private?
	protected String frase;
	public PessoaIMC(String nome, String dataNascimento, double peso, double altura) {
		super(nome, dataNascimento);
		this.altura = altura;
		this.peso = peso;
	}
	
	public double getAltura(){
		return altura;
	}
	
	public double getPeso(){
		return peso;
	}
	
	public double calculaIMC(){
		return peso/(Math.pow(altura,2));
	}
	
	public abstract Resultado resultIMC();
	
	public String toString(){
		return "Nome: " + nome + "\n" + "Data de Nascimento: " + dataNascimento + "\nPeso: " + peso + "\nAltura: " + altura+"\n"+ resultIMC() + "\n";
	}
}
	
