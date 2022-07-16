package lp2g34.locadora;
public class CopiaNaoDisponivelEx extends Exception 
{  
	private static final long serialVersionUID = 1L;
	CopiaNaoDisponivelEx(String message) 
	{
		super(message);
	}
}