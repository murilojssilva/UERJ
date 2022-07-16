public class Placar
{
	private String placar;//campo de instância
	private boolean resultado = false;
	public Placar (String placar)
	{
		//this.setResultado();
		//this.setTentativas;
		//this.setVitorias;
		this.placar = placar;
	}
	/*
	public int getTentativas
	* 
	{
		return tentativas;
	}
	public void setTentativas
	{
		this.tentativas = tentativas;
	}
	public int getTentativas
	{
		return vitorias;
	}
	public void setTentativas
	{
		this.vitorias = vitorias;
	}*/
	public boolean getResultado()
	{
		return resultado = true;
	}
	public void setResultado()
	{
		this.resultado = resultado;
	}
	public String toString()
	{
		return placar;
	}
}
