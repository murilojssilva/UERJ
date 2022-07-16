import random
f1=open('a.1M.in', 'w')
f2=open('b.1M.in', 'w')
for i in range(1000000): f1.write(str(random.uniform(-10,+10))+'\n')
for i in range(1000000): f2.write(str(random.uniform(-10,+10))+'\n')
f1.close()
f2.close()