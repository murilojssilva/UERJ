def LerMatriz(mat,lin,col):
    mat=[]
    for i in range(0,lin):
        mat.append(0)
        mat[i]=[]
        for j in range(0,col):
            mat[i].append(input("Número:"))
    return mat
  
def MatrizTransposta(mat,lin,col):
        aux=[]
        for j in range(0,col):
            aux.append(0)
            aux[j]=[]
            for i in range(0,lin):
                aux[j].append(mat[i][j])
        return aux

linha=input("Quantidade de Linhas:")
coluna=input("Quantidade de Colunas:")
matriz=[]
matriz=LerMatriz(matriz,linha,coluna)

print "\nMATRIZ:"
for i in range(0,linha):
    for j in range(0,coluna):
        print "%2d"% matriz[i][j],
    print

mat_transp=[]
mat_transp=MatrizTransposta(matriz,linha,coluna)

print "\nMATRIZ TRANSPOSTA:"
for i in range(0,coluna):
    for j in range(0,linha):
        print "%2d"% mat_transp[i][j],
    print
