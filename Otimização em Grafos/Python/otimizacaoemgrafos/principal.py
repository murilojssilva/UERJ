from manipuladorJson import ManipuladorJson
from manipuladorGrafos import ManipuladorGrafos

mjson = ManipuladorJson('grafo_aleatorio_n_6')
mgrafos = ManipuladorGrafos()

#  Pegando o tamanho para fazer a Matriz
tam = mjson.getTamanho(mjson.getMassaGrafos)

# Gerar a matriz Adjacencia
matrizAdjacencia = mgrafos.gerarMatrizAdjacencia(mgrafos.gerarGrafoZero(tam), mjson)
#listaAdjacencia = mgrafos.gerarListaAdjacencia(mgrafos.gerarGrafoZero(tam),mjson)

# Imprimir a matriz Adjacencia
#mgrafos.imprimeGrafos(matrizAdjacencia)
#print ("-------------------------------------------------")

# Lista de Adjacencias
#mgrafos.vizinhosVertice(5, matrizAdjacencia)

# Remover Arestas da Matriz
#matrizRemovida = mgrafos.removerArestas("01", matrizAdjacencia)

mgrafos.dfs(3)
#bfs(mgrafos,2)

# Imprimir a matriz removida
#mgrafos.imprimeGrafos(matrizRemovida)