def LerMatriz(mat):
    mat=[]
    for i in range(0,10):
        mat.append(0)
        mat[i]=[]
        for j in range(0,3):
            mat[i].append(input("Número:"))
    return mat

def Perimetros(mat):
    vet=[0]*10
    for i in range(0,10):
        soma_linha=0
        for j in range(0,3):
            soma_linha+=mat[i][j]
            vet[i]=soma_linha
    return vet

matriz=[]
matriz=LerMatriz(matriz)
for i in range(0,10):
    for j in range(0,3):
        print "%2d"% matriz[i][j],
    print

print Perimetros(matriz)
