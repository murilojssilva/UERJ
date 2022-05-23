def LerMatriz(mat):
    for i in range(0,5):
        mat.append(0)
        mat[i]=[]
        for j in range(0,5):
            mat[i].append(0)
    for i in range(0,5):
        mat[i][i]=1
    return mat

matriz=[]
matriz=LerMatriz(matriz)
for i in range(0,5):
    for j in range(0,5):
        print "%2d"% matriz[i][j],
    print

