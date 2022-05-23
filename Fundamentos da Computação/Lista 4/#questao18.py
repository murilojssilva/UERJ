def LerMatriz(mat):
    for i in range(0,6):
        mat.append(0)
        mat[i]=[]
        for j in range(0,6):
            mat[i].append(input("Numero:"))
    return mat

def ElemMaior10(mat):
    cont=0
    for i in range(0,6):
        for j in range(0,6):
            if mat[i][j]>10:
                cont+=1
    return cont

matriz=[]
matriz=LerMatriz(matriz)
maior10=ElemMaior10(matriz)

for i in range(0,6):
    for j in range(0,6):
        print "%2d"% matriz[i][j],
    print
    
if maior10==0:
    print "\n Não Existem Números maiores que 10 nesta matriz"
elif maior10==1:
    print maior10, "\n número maior que 10"
else:
    print maior10, "\n números maiores que 10"
