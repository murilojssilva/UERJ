def LerMatriz(mat):
    mat=[]
    for i in range(0,3):
        mat.append(0)
        mat[i]=[]
        for j in range(0,3):
            mat[i].append(input("Número:"))
    return mat

def SomaDiagonal(mat):
    soma1=0
    soma2=0
    for i in range(0,3):
        soma1+=mat[i][i]
        soma2+=mat[i][2-i]
    dif=soma1-soma2
    return dif

matriz=[]
matriz=LerMatriz(matriz)
for i in range(0,3):
    for j in range(0,3):
        print "%2d"% matriz[i][j],
    print
diferenca=SomaDiagonal(matriz)
print "\nDiferença da soma das diagonais:", diferenca
