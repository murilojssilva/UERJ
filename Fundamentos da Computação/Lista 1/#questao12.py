x=input("Digite um número:")
y=input("Digite um número:")
resto=x%y
while resto!=0:
    x=y
    y=resto
    resto=x%y
print "MDC =", y
