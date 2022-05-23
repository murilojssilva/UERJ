def LerMatriz(mat):
    mat=[]
    for i in range(0,3):
        mat.append(0)
        mat[i]=[]
        for j in range(0,3):
            mat[i].append(input("Número:"))
    return mat

def SomaDiagonal(mat):
    vet=[0]*2
    soma1=0
    soma2=0
    for i in range (0,3):
        soma1+=mat[i][i]
        soma2+=mat[2-i][i]
    vet[0]=soma1
    vet[1]=soma2
    return vet

soma=[]
matriz=[]
matriz=LerMatriz(matriz)
soma=SomaDiagonal(matriz)

for i in range (0,3):
    for j in range(0,3):
        print "%2d"% matriz[i][j],
    print

print "Soma Diagonal Principal:", soma[0]
print "Soma Diagonal Secundária:", soma[1]
