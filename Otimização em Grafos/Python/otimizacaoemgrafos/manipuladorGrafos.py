class ManipuladorGrafos:

    def __init__(self):
        pass

    def gerarGrafoZero(self, tam):
        matriz = []
        for i in range(tam):
            matriz.append([])
            for j in range(tam):
                elemento = 0
                matriz[i].append(elemento)
        return matriz
    
    def gerarGrafdZeroLista(self,tam):
        grau = []
        for i in range(tam):
            elemento = 0
            grau[i].append(elemento)
        return grau

    def gerarMatrizAdjacencia(self, matriz, indice):
        linhas = len(matriz)
        colunas = len(matriz[0])

        k = 0
        for i in range(linhas):
            for j in range(colunas):

                if k < len(indice.getMassaGrafos['arestas']):
                    matriz[indice.getMassaGrafos['arestas'][k][0]][indice.getMassaGrafos['arestas'][k][1]] = 1
                    matriz[indice.getMassaGrafos['arestas'][k][1]][indice.getMassaGrafos['arestas'][k][0]] = 1
                    matriz[i][j]
                    k += 1
                else:
                    matriz[i][j]
        return matriz

    def gerarListaAdjacencia(self, grau, indice):
        linha = len(grau)
        k = 0
        for i in range(linha):
            if k < len(indice.getMassaGrafos['arestas']):
                grau[indice.getMassaGrafos['arestas'][k][0]][indice.getMassaGrafos['arestas'][k][1]] = 1
                grau[indice.getMassaGrafos['arestas'][k][1]][indice.getMassaGrafos['arestas'][k][0]] = 1
                grau[i]
                k += 1
            else:
                grau[i]
        return grau

    def removerArestas(self, vertice, matrizRemovida):

        linhas = len(matrizRemovida)
        colunas = len(matrizRemovida[0])

        verticelist = list(vertice)

        for i in range(linhas):
            for j in range(colunas):

                if matrizRemovida[int(verticelist[0])][int(verticelist[1])] == 1 and matrizRemovida[int(verticelist[1])][
                    int(verticelist[0])] == 1:
                    matrizRemovida[int(verticelist[0])][int(verticelist[1])] = 0
                    matrizRemovida[int(verticelist[1])][int(verticelist[0])] = 0
            return matrizRemovida

    def vizinhosVertice(self, vertice, matrizAdjacencia):
        linhas = len(matrizAdjacencia)
        colunas = len(matrizAdjacencia[0])
        listaIndices = []
        for i in range(linhas):
            for j in range(colunas):
                if i == vertice and matrizAdjacencia[i][j] == 1:
                    listaIndices.append(j)
        print (listaIndices)

    def imprimeGrafos(self, matrizAdjacencia):
        linhas = len(matrizAdjacencia)
        colunas = len(matrizAdjacencia[0])
        for i in range(linhas):
            for j in range(colunas):
                print (matrizAdjacencia[i][j]),
            print ('\n')

    def imprimeListaAdjacencia(self, listaAdjacencia):
        linha = len(listaAdjacencia)
        print ("Lista de adjacência: ")
        for i in range(linha):
            print (grau[i])
        print ('\n')
    
    def dfs(ManipuladorGrafos,vertice, start):
        visited, stack = set(), [start]
        while stack:
            if vertice not in visited:
                visited.add(vertice)
                stack.extend(ManipuladorGrafos[vertice] - visited)
        print (visited)

    def bfs(ManipuladorGrafos, start):
        visited, queue = set(), [start]
        while queue:
            vertex = queue.pop(0)
            if vertex not in visited:
                visited.add(vertex)
                queue.extend(ManipuladorGrafos[vertex] - visited)
        print (visited)
        
def buscaGrafo(self,start):
    visitado, stack = set(), [start]
    while stack:
        vertice = stack.pop()
        if vertice not in visitado:
            visitado.add(vertice)
    print (visitado)

    labelExplorado = []
    labelDescoberto = []
    r = 1