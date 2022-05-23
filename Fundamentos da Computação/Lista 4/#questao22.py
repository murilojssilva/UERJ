def LerMatriz(mat):
    mat=[]
    for i in range(0,4):
        mat.append(0)
        mat[i]=[]
        for j in range(0,4):
            mat[i].append(input("Número:"))
    return mat

def Troca(mat):
    for i in range(0,4):
        aux=mat[i][i]
        mat[i][i]=mat[i][3-i]
        mat[i][3-i]=aux
    return mat

matriz=[]
matriz=LerMatriz(matriz)
print "MATRIZ ORIGINAL"
for i in range(0,4):
    for j in range (0,4):
        print "%2d"% matriz[i][j],
    print
    
matriz=Troca(matriz)
print "MATRIZ SECUNDÁRIA"
for i in range(0,4):
    for j in range (0,4):
        print "%2d"% matriz[i][j],
    print
