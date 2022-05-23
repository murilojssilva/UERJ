indice=[1,2,3,4,5,6,7,8,9]
valor=[5,7,6,9,2,8,4,0,3]
print "Índice:", indice
print "Valor:", valor
j=0
i=0
while j<=9:
    indice.append(valor[i])
    i=valor[i]-1
    j+=1
    print indice[i],
