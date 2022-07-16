public class AnguloObj{
	
	protected double arcoRad;
	private double seno, coseno, tangente, cotangente;

	AnguloObj(double valorDoAngulo){
		arcoRad = Math.toRadians(valorDoAngulo);
	}

	public double funcaoSeno(){
		seno = Math.sin(arcoRad);
		return seno;
	}
	public double funcaoCoseno(){
		coseno = Math.cos(arcoRad);
		return coseno;
	}
	public double funcaoTangente(){
		tangente = Math.tan(arcoRad);
		return tangente;
	}
	public double funcaoCotangente(){
		cotangente = 1.0 / Math.tan(arcoRad);
		return cotangente;
	}

	public String toString(){
		String resposta = "\nArco: " +arcoRad+ 
						"\nSeno: "+seno+
						"\nCoseno: "+coseno+
						"\nTangente: "+tangente+
						"\nCotangente: "+cotangente+"\n";
		return resposta;
	}

}