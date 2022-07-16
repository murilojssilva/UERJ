public class EmpregadoContratado extends Empregado
{
	int numDep;
	protected double salarioFam,valorPorDep = 9.58;
	public double aliquota = 0.15;
	public EmpregadoContratado(String nome,String codigo,double salario,int numDep)
	{
		super (nome,codigo,salario);
		this.numDep = numDep;
	}
	public void calculaSalario()
	{
		super.calculaSalario(aliquota);
	}
	public void calculaSalario (int numDep)
	{
		salario += (numDep * valorPorDep);
		super.calculaSalario(aliquota);
	}
	public String toString()
	{
		return "Nome: "+nome+"\nCódigo do empregado: "+codigo+"\nSalário-base: "+salario+"\nSalário-líquido: "+salarioLiq;
	}
}