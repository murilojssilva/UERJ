public class Empregado
{
	public String nome,codigo;
	public double salario,salarioLiq;
	public Empregado(String nome,String codigo,double salario)
	{
		this.nome = nome;
		this.codigo = codigo;
		this.salario = salario;
		this.salarioLiq = salario;
	}
	public double calculaSalario(double desconto)
	{
		salarioLiq *= (1-desconto);
		return salarioLiq;
	}
}