cont1=0
cont2=0
cont3=0
frase=raw_input("Frase:")
frase=frase.upper()
for i  in range(0,len(frase)):
    if frase[i]=="A" or frase[i]=="E" or frase[i]=="I" or\
       frase[i]=="O" or frase[i]=="U":
        cont1+=1
    elif frase[i]==" ":
        cont2+=1
    else:
        cont3+=1
print "\nVogais:", cont1
print "Brancos:", cont2
print "Outrs:", cont3
                
               
