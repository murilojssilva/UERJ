class Mulher extends PessoaIMC
{
	public Mulher(String nome,String dataNascimento,double peso,double altura)
	{
		super(nome,dataNascimento,peso,altura);
	}
	public String resultIMC()
	{
		double imc = CalculaIMC(peso,altura);
		if (imc < 19.0)
		{
			return "Abaixo do peso ideal";
		}
		else if (imc > 25.8)
		{
			return "Acima do peso ideal";
		}
		else
		{
			return "Dentro do peso ideal";
		}
	}
}