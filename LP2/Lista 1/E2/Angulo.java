public class Angulo
{
	public static double converteAngulo(double ang)
	{
		double rad = Math.toRadians(ang);
		return rad;
	}
	public static double funcaoSeno(double ang)
	{
		double sen = Math.sin(converteAngulo(ang));
		return sen;
	}
	public static double funcaoCosseno(double ang)
	{
		double cos = Math.cos(converteAngulo(ang));
		return cos;
	}
	public static double funcaoTangente(double ang)
	{
		double tan = Math.tan(converteAngulo(ang));
		return tan;
	}
	public static double funcaoCotangente(double ang)
	{
		double cot = 1/(Math.tan(converteAngulo(ang)));
		return cot;
	}
}
