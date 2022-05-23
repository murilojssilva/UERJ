import numpy as np
import matplotlib.pyplot as plt

p = np.array([[1, 1], [0, 1]])
p = np.transpose(p)

plt.figure(figsize=(5, 5))
plt.xlim(-5, 5), plt.ylim(-5, 5)
plt.axhline(), plt.axvline()
plt.plot(p[0, 0], p[1, 0], "bo")
plt.show()

theta = 90
theta_rad = (theta / 180) * np.pi

R = np.array(
    [
        [np.cos(theta_rad)],
        [-np.sin(theta_rad)],
        [np.sin(theta_rad)],
        [np.cos(theta_rad)],
    ]
)

pT = np.matmul(R, p)

plt.figure(figsize=(5, 5))
plt.xlim(-5, 5), plt.ylim(-5, 5)
plt.axhline(), plt.axvline()
plt.plot(pT[0, 0], pT[1, 0], "ro")
plt.show()
