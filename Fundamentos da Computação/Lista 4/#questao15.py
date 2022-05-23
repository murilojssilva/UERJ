def LerMatriz(mat):
    for i in range(0,5):
        mat.append(0)
    	mat[i]=[]
    	for j in range(0,5):
            mat[i].append(input("Número:"))
    return mat

def BuscaMaiorElem(mat):
    vet=[0]*3
    maior=10000
    for i in range(0,5):
        for j in range(0,5):
            if mat[i][j]>maior:
                maior=matriz[i][j]
                vet[0]=maior
                vet[1]=i
                vet[2]=j
    return vet

matriz=[]
vet_aux=[]
matriz=LerMatriz(matriz)
vet_aux=BuscaMaiorElem(matriz)
print "Maior Elemento:", vet_aux[0]
print "Linha:", vet_aux[1]
print "Coluna:", vet_aux[2]

