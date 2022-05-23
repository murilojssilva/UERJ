cont=0
soma=0
for i in range(92,1479):
    for j in range(2,i):
        if i%j==0:
            cont+=1
    if cont==0:
        soma+=i
    cont=0
print "Soma dos primos entre 92 e 1478:",soma
