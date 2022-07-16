import java.util.*;
public class Banheiro 
{
	int qtd, capacidade;
	Scanner dado = new Scanner(System.in);
	Humano[] humano = new Humano[];
	public Banheiro (int capacidade)
	{
		this.humano.length = capacidade;
		this.capacidade =  5;
	}
	public void entraBanheiro(Humano h)
	{
		try
		{
			System.out.printf("Digite o gênero da pessoa\th- Homem\tm-Mulher: ");
			do
			{
				h.genero = dado.next();
			}while (h.genero != "h"||h.genero !="m");
			qtd++;
			
			if (h.genero == "h")
				h.identificador
			if (qtd > h
		}
		catch (e)
		{
			
		}
	}
}
