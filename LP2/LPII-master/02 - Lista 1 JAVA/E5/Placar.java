public class Placar {

	private String sorteado;
	private int numTentativas, numVitorias = 0;
	private boolean venceu;
	
	public Placar (String result, String tentativas, String sorteado){
		this.setSorteado(sorteado);
		this.setNumTentativas(Integer.parseInt(tentativas));
		this.setVenceu(result.equals("true")? true  : false);
		if(isVenceu()) this.setnumVitorias(1);
	}
		
	public boolean isVenceu(){
		return venceu;
	}
	
	public void setVenceu(boolean result){
		this.venceu = result;
	}
	
	public String getSorteado(){
		return sorteado;
	}
	
	public void setSorteado(String sort){
		this.sorteado = sort;
	}
	
	public int getNumTentativas(){
		return numTentativas;
	}
	
	public void setNumTentativas(int tentativas){
		this.numTentativas = tentativas;
	}
	
	public void setnumVitorias(int vitorias){
		this.numVitorias = vitorias;
	}
	
	public int getNumVitorias(){
		return numVitorias;
	}	
}
