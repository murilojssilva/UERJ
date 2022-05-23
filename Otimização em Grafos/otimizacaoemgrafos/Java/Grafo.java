import java.util.ArrayList;
import java.util.List;

public class Grafo {

	private List<Vertice> grafo = new ArrayList<Vertice>();

	public void setVertices(List<Vertice> vertices) {

		this.grafo.addAll(vertices);
	}

	public void adicionarVertice(Vertice novoVertice) {

		this.grafo.add(novoVertice);
	}

	public List<Vertice> getVertices() {

		return this.grafo;
	}

	// Metodo que retorna o vertice cuja descricao e igual a procurada.
	public Vertice encontrarVertice(String nome) {

		for (int i = 0; i < this.getVertices().size(); i++) {

			if (nome.equalsIgnoreCase(this.getVertices().get(i).getDescricao())) {

				return this.getVertices().get(i);

			}
		}

		return null;

	}

}