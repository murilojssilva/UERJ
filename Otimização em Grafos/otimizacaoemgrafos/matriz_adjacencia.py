arq = open('teste.txt', 'r')
m = int(arq.readline())
n = 5
def main():
	A = le_matriz(m,n)
	
	imprime_matriz(A)


def le_matriz(m, n):
	print("Digite os elementos da matriz de tamanho %dx%d:" %(m,n))
	matriz = []
	for i in range(m):
		matriz.append([])
		for j in range(n):
			elemento = 0
			matriz[i].append(elemento)
			
	return matriz

def imprime_matriz(matriz):
	print ("vertices: [")
	for i in range (1,m+1):
		print ("%2d," %i)
	print ("]")
main()








class Vertex:
	def __init__(self, n):
		self.name = n
		self.neighbors = list()
	
	def add_neighbor(self, v):
		if v not in self.neighbors:
			self.neighbors.append(v)
			self.neighbors.sort()

class Graph:
	vertices = {}
	
	def add_vertex(self, vertex):
		if isinstance(vertex, Vertex) and vertex.name not in self.vertices:
			self.vertices[vertex.name] = vertex
			return True
		else:
			return False
	
	def add_edge(self, u, v):
		if u in self.vertices and v in self.vertices:
			# my YouTube video shows a silly for loop here, but this is a much faster way to do it
			self.vertices[u].add_neighbor(v)
			self.vertices[v].add_neighbor(u)
			return True
		else:
			return False
			
	def print_graph(self):
		for key in sorted(list(self.vertices.keys())):
			print(key + str(self.vertices[key].neighbors))

g = Graph()
# print(str(len(g.vertices)))
a = Vertex('A')
g.add_vertex(a)
g.add_vertex(Vertex('B'))
for i in range(ord('A'), ord('F')):
	g.add_vertex(Vertex(chr(i)))

edges = [arq.readline(2), arq.readline(2), arq.readline(2), arq.readline(2)]
for edge in edges:
	g.add_edge(edge[:1], edge[1:])

g.print_graph()

arq.close()