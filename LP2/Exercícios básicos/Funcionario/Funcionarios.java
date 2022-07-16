import java.util.Scanner;
public abstract class Funcionarios extends Data
{
	Scanner dado = new Scanner (System.in);
	protected String nome,departamento,rg;
	protected double salario;
	protected boolean funcEmpresa;
	public Funcionarios(int dia,int mes, int ano, String nome,String departamento,String rg, double salario, boolean funcEmpresa)
	{
		super(dia,mes,ano);
		this.nome = nome;
		this.departamento = departamento;
		this.rg = rg;
		this.salario = salario;
		this.funcEmpresa = funcEmpresa;
	}
	public void demite()
	{
		this.funcEmpresa = false;
	}
	public void bonifica(double aumento)
	{
		double novoSalario = this.salario + aumento;
		this.salario = novoSalario;
	}
	public String estaNaEmpresa()
	{
		if (funcEmpresa == true)
			return "Sim";
		else
			return "Não";
	}
	public String toString()
	{
		return "\n\nNome do funcionário: "+nome+"\nDepartamento do funcionário: "+departamento+super.toString()+"\nRG do funcionário: "+rg+"\nSalário do funcionário: "+salario+"O funcionário está na empresa?: "+estaNaEmpresa();
	}
}