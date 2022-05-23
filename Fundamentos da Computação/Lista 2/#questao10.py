def LerMatriz(matriz):
    matriz=[]
    for i in range(0,3):
        matriz.append(0)
        matriz[i]=[]
        for j in range(0,3):
            matriz[i].append(input("Número:"))
    return matriz

def SomaLinCol(matriz):
    aux=[0]*3
    vet1=[0]*3
    vet2=[0]*3
    for i in range(0,3):
        vet1[i]=matriz[0][i]
        vet2[i]=matriz[i][1]
        aux[i]=vet1[i]+vet2[i]
    return aux

mat=[]
mat=LerMatriz(mat)

print "\nMATRIZ:"
for i in range(0,3):
    for j in range(0,3):
        print "%2d"% mat[i][j],
    print

print "\nLinha 01 + Coluna 02:", SomaLinCol(mat)

