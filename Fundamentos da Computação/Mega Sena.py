from random import*
a=0
vetcand=vetsort=aux=[0]*6
print 'Mega Sena'.center(50)
for j in range (0,6):
    vetcand[j]=input('Digite um dos números que você escolheu: ')
    while vetcand[j]>60 or vetcand[j]<1:
        print 'Número inválido. Escreva-o novamente'
        vetcand[j]=input('Digite um dos números que você escolheu: ')
    while vetcand[j]==vetcand[j-1]:
        print 'Número repetido. Escreva-o novamente'
        vetcand[j]=input('Digite um dos números que você escolheu: ')
    for i in range (0,6):
        vetsort[i]=randint(1,61)
        if vetsort[i]==vetsort[i-1]:
            vetsort[i]=randint(1,61)
    for k in range (0,6):
        if vetcand[j]==vetsort[i]:
            a+=1
vetcand.sort()
vetsort.sort()
print vetcand
print vetsort
if a==4:
    print 'Parabéns, você ganhou a quadra'
elif a==5:
    print 'Parabéns, você ganhou a quina'
elif a==6:
    print 'Parabéns. Você ganhou a sena'
else:
    print 'Que pena. Tente Novamente'
