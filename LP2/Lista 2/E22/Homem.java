class Homem extends PessoaIMC
{
	public Homem(String nome,String dataNascimento,double peso,double altura)
	{
		super(nome,dataNascimento,peso,altura);
	}
	public String resultIMC()
	{
		double imc = CalculaIMC(peso,altura);
		if (imc < 20.7)
		{
			return "Abaixo do peso ideal";
		}
		else if (imc > 26.4)
		{
			return "Acima do peso ideal";
		}
		else
		{
			return "Dentro do peso ideal";
		}
	}
}