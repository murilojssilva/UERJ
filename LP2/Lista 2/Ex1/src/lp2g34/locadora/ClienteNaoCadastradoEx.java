package lp2g34.locadora;
public class ClienteNaoCadastradoEx extends Exception 
{  
	private static final long serialVersionUID = 1L;
	ClienteNaoCadastradoEx(String message) 
	{
		super(message);
	}
}