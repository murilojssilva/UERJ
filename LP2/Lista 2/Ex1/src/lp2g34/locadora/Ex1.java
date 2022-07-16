package lp2g34.locadora;

import java.io.BufferedReader;

public class Ex1
{
	public static void main(String[] args)
	{
		module Manuntencao:
			Hashtable <Integer,Cliente> cadastroClientes = new Hashtable();
			Hashtable <String,Filme>cadastroFilmes = new Hashtable();
			String curLine;
			int linha = 0,paragrafo = 1;
			//FileReader txtFile = newFileReader(args[0]);
			BufferedReader txtBuffer = new BufferedReader(new FileReader(cadastroClientes));
			curline = txtBuffer.readLine();
			while (curline != null)
			{
				linha++;
				curLine = txtBuffer.readLine();
			}
			txtBuffer.close();
	}
}