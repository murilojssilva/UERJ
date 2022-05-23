def LerMatriz(matriz,linha,coluna):
    matriz=[]
    for i in range(0,linha):
        matriz.append(0)
        matriz[i]=[]
        for j in range(0,coluna):
            matriz[i].append(input("Número:"))
    return matriz

def SomaMatriz(matriz1,matriz2,linha,coluna):
    matriz_soma=[]
    for i in range(0,linha):
        matriz_soma.append(0)
        matriz_soma[i]=[]
        for j in range(0,coluna):
            matriz_soma[i].append(0)
    for i in range(0,linha):
        for j in range(0,coluna):
            matriz_soma[i][j]=matriz1[i][j]+matriz2[i][j]
    return matriz_soma

for i in range(0,2):
    lin=input("Número de linhas:")
    col=input("Número de colunas:")
    mat=[]
    mat=LerMatriz(mat,lin,col)
    if i==0:
        mat1=mat
    else:
        mat2=mat
print "\n MATRIZ 1:"
for i in range(0,lin):
    for j in range(0,col):
        print "%2d"% mat1[i][j],
    print
print "\n MATRIZ 2:"
for i in range(0,lin):
    for j in range(0,col):
        print "%2d"% mat2[i][j],
    print
soma=[]
soma=SomaMatriz(mat1,mat2,lin,col)
print "\n MATRIZ 1  +  MATRIZ 2:"
for i in range(0,lin):
    for j in range(0,col):
        print "%2d"% soma[i][j],
    print
