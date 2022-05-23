vet1=[0]*50
vet2=[0]*50
soma1=0
soma2=0
for i in range(0,50):
    c=input("Temperatura em Celsius:")
    vet1[i]=c
    f=(9*c+150)/float(5)
    vet2[i]=f
    soma1+=c
    soma2+=f
mediac=float(soma1)/50
mediaf=float(soma2)/50
print "Média Temp. °C:", mediac
print "Média Temp. °F:", mediaf
for i in range(0,50):
    if vet2[i]>mediaf:
        print "Temp. °F acima da média:", vet2[i]

               
