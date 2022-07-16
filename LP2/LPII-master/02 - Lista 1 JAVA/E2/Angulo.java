public class Angulo{

	public static double converteAngulo(double valorDoAngulo){
		double radianos = Math.toRadians(valorDoAngulo);
		return radianos;
	}

	public static double funcaoSeno(double valorDoAngulo){
		double seno = Math.sin(converteAngulo(valorDoAngulo));
		return seno;
	}

	public static double funcaoCoseno(double valorDoAngulo){
		double coseno = Math.cos(converteAngulo(valorDoAngulo));
		return coseno;
	}

	public static double funcaoTangente(double valorDoAngulo){
		double tangente = Math.tan(converteAngulo(valorDoAngulo));
		return tangente;
	}

	public static double funcaoCotangente(double valorDoAngulo){
		double cotangente = 1.0 / Math.tan(converteAngulo(valorDoAngulo));
		return cotangente;
	}

}