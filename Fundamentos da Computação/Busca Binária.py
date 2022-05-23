vetor=[]
for i in range (0,4):
    vetor.append(raw_input("Nome: "))
vetor.sort()
elemen=(raw_input("Nome requerido: "))
inicio=0
fim=len(vetor)-1
achou=False
while inicio<=fim and not achou:
    meio=(inicio+fim)//2
    if elemen== vetor[meio]:
        pos=meio
        achou=True
    elif elemen<vetor[meio]:                                                    
        fim =meio-1
    else:
        inicio=meio+1
if achou:
    print vetor
    print "Encontrado Nome: ", elemen
    print "Posição: ", pos
else:
    print "Não Encontrado "
