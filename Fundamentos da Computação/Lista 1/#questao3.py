soma1=0
soma2=0
n=input("Número Final da seqüência:")
for i in range (1000,n+1):
        if i%11==5:
            soma1+=i
        if i%17==0:
            soma2+=i
dif=soma1-soma2
print dif
