cadeia=raw_input('Cadeia: ')
fim=len(cadeia)-1
inicio=0
pali=False
while inicio<=fim and not pali:
    if cadeia[inicio]==cadeia[fim]:
        pali=True
    else:
        inicio+=1
        fim-=1
if pali:
    print 'É palíndromo'
else:
    print 'Não é palíndromo'
