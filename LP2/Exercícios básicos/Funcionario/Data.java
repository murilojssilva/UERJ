public class Data
{
	protected int dia,mes,ano;//super
	public Data(int dia,int mes,int ano)
	{
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
	public String toString()
	{
		return "Data de entrada do funcionário na empresa: "+dia/mes/ano;
	}
}