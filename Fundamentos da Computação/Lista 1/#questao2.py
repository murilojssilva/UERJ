contAP=0
contPF=0
contRP=0
soma=0
n=input("Quantidade de alunos:")
for i in range (0,n):
    p1=input("Nota P1 = ")
    p2=input("Nota P2 = ")
    media=(p1+p2)/2.0
    if media>=7.0:
        contAP+=1
        print "Aprovado com média ", media
    elif media>=4.0:
        contPF+=1
        print "Prova Final com média ", media
    else:
        contRP+=1
        print "Reprovado com média ", media
    soma+=media
media_turma=float(soma)/n
print "APROVADOS =",contAP
print "PROVA FINAL =",contPF
print "REPROVADOS =",contRP
print "Média da Turma = ", media_turma
    
