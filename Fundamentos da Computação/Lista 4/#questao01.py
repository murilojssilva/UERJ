soma=0
cont1=0
cont2=0
notas=[0.0]*10
for i in range(0,10):
    notas[i]=input("Nota:")
    soma+=notas[i]
print "Notas:", notas
media=float(soma)/len(notas)
for i in range(0,10):
    if notas[i]>media:
        cont1+=1
    elif notas[i]<media:
        cont2+=1
print "Quantidade de notas acima da média da turma:", cont1
print "Quantidade de notas abaixo da média da turma:", cont2
