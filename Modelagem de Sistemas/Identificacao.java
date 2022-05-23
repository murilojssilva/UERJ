static class Identificacao{
	protected String ID, senha;
	protected bool Identificacao (String ID, senha)
	{
		if (validaIdentificacao(ID,senha))
		{
			this.ID = ID;
			this.senha = senha;
			return true;
		}else return false;
	}
	protected static string setID (String ID)
	{
		this.ID = ID;
	}
