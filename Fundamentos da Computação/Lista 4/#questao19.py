def LerMatriz(mat):
    for i in range(0,2):
        mat.append(0)
        mat[i]=[]
        for j in range(0,2):
            mat[i].append(input("Numero:"))
    return mat

def BuscaValor(mat,a):
    vet=[0]*2
    for i in range(0,2):
        for j in range(0,2):
            if mat[i][j]==a:
                vet[0]=i+1
                vet[1]=j+1
                break
    return vet
                

vet_busca=[]
matriz=[]
matriz=LerMatriz(matriz)

for i in range(0,2):
    for j in range(0,2):
        print "%2d"% matriz[i][j],
    print
    
x=input("Valor Procurado:")
vet_busca=BuscaValor(matriz,x)
if vet_busca[0]==0 and vet_busca[1]==0:
    print "Elemento não encontrado"
else:
    print "Linha", vet_busca[0]
    print "Coluna:", vet_busca[1]




