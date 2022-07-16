public class AnguloObj
{
	protected double arcoRad;
	double sen,cos,tan,cot;
	String impressao;
	public double AngObj(double ang)
	{
		arcoRad = Math.toRadians(ang);
		return arcoRad;
	}
	public double funcaoSeno()
	{
		sen = Math.sin(arcoRad);
		return sen;
	}
	public double funcaoCosseno()
	{
		cos = Math.cos(arcoRad);
		return cos;
	}
	public double funcaoTangente()
	{
		tan = Math.tan(arcoRad);
		return tan;
	}
	public double funcaoCotangente()
	{
		cot = 1/(Math.tan(arcoRad));
		return cot;
	}
	public String toString()
	{
		impressao = "Arco: " +arcoRad+ "\nSeno: "+sen+"\nCoseno: "+cos+"\nTangente: "+tan+"\nCotangente: "+cot+"\n";
		return impressao;
	}
}	
