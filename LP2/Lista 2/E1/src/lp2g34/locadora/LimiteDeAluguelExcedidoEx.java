package lp2g34.locadora;
public class LimiteDeAluguelExcedidoEx extends Exception 
{  
	private static final long serialVersionUID = 1L;
	LimiteDeAluguelExcedidoEx(String message) 
	{
		super(message);
	}
}