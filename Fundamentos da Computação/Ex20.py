mat=[0.0]*4
mat2=[0.0]*4
for i in range(0,4):
    mat[i]=[0.0]*4
    mat2[i]=[0.0]*4
    for j in range(0,4):
        mat[i][j]=input('Digite um núm: ')
for i in range(0,4):
    for j in range (0,4):
        if i==1:
            mat2[j][i]=mat[i+2][j]
        elif j==3:
            mat2[i][j]=mat[j-2][i]
        else:
            mat2[i][j]=mat[i][j]            
for line in mat:
    print '%4d%4d%4d%4d'%tuple(line)
for line in mat2:
    print '%4d%4d%4d%4d'%tuple(line)
