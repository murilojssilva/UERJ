import numpy as np
from scipy.optimize import linprog

c = [0.0037, 0.0024, 0.0014, 0.0030, 0.0024, 0.0019, 0.0028, 0.0018, 0.0025, 0.0024]
c = np.multiply(-1.0, c)

A_eq = np.ones((1,10))
b_eq = np.array([1.0])

A_ub = np.append(np.eye(10), -1.0*np.eye(10), axis=0)
b_ub = np.append(0.30*np.ones((10,)), np.zeros((10,)), axis=0)
A_ub = np.append(A_ub, [[0.0248, 0.0216, 0.0195, 0.0293, 0.0240, 0.0200, 0.0263, 0.0214, 0.0273, 0.0247]], axis=0)
b_ub = np.append(b_ub, [0.0250])

res = linprog(c, A_eq=A_eq, b_eq=b_eq, A_ub=A_ub, b_ub=b_ub, method='simplex', options = {'disp': True, 'maxiter': 1000})

print "Valor otimo: ", -res.fun
print "X:"
for k, xk in enumerate(res.x):
    print "x_{", str(k+1), "} = ", xk
