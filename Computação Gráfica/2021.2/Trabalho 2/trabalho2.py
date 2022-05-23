# Murilo de Jesus Santos Silva
import numpy as np
import matplotlib.pyplot as plt

scaleSup = 1
scaleInf = scaleSup / 2
centerX = 0
centerY = 0


def on_press(event):
    global centerX
    global centerY

    if event.button == 3:
        centerX = round(event.xdata, 2)
        centerY = round(event.ydata, 2)


def on_key(event):
    global end_loop
    global speedRotation
    global scaleSup
    global scaleInf
    if event.key == "escape":
        end_loop = True
    elif event.key == "up":
        scaleSup += 0.5
        scaleInf /= 2
    elif event.key == "down":
        scaleSup -= 0.5
        scaleInf /= 2
    elif event.key == "right":
        speedRotation += 1
    elif event.key == "left":
        speedRotation -= 1


def rotation(theta):
    theta_rad = (theta / 180) * np.pi
    return np.array([[np.cos(theta_rad), -np.sin(theta_rad), 0], [np.sin(theta_rad), np.cos(theta_rad), 0], [0, 0, 1]])


def scale(cx, cy):
    return np.array([[cx, 0, 0], [0, cy, 0], [0, 0, 1]])


def translation(centerX, centerY):
    return np.array([[1, 0, -centerX], [0, 1, -centerY], [0, 0, 1]])


def translationBack(centerX, centerY):
    return np.array([[1, 0, centerX], [0, 1, centerY], [0, 0, 1]])


po = np.array([[-0.5, -0.5, 1], [0.5, -0.5, 1], [0.5, 0.5, 1], [-0.5, 0.5, 1]])
po = np.transpose(po)

xmin = np.amin(po[0, :])
xmax = np.amax(po[0, :])

ymin = np.amin(po[1, :])
ymax = np.amax(po[1, :])

originX = (xmin + xmax) / 2
originY = (ymin + ymax) / 2


plt.close("all")
fig, ax = plt.subplots()
ax.cla()

cid = fig.canvas.mpl_connect("button_press_event", on_press)
cid = fig.canvas.mpl_connect("key_press_event", on_key)


end_loop = False

cx = 1.0
cy = 1.0
zoom = True
speedRotation = 1
speedTranslation = 1

while not end_loop:
    for theta in range(0, 361, 5):

        theta_rad = theta * speedRotation

        thetaTranslation = theta * speedTranslation

        theta_rad = (theta / 180) * np.pi

        R = np.array([[np.cos(theta_rad), -np.sin(theta_rad), 0], [np.sin(theta_rad), np.cos(theta_rad), 0], [0, 0, 1]])

        Tr1 = np.matmul(R, translation(originX, originY))
        Tr2 = np.matmul(scale(cx, cy), Tr1)
        Tr3 = np.matmul(translationBack(originX, originY), Tr2)

        mF = np.matmul(Tr3, po)

        mT = np.matmul(rotation(thetaTranslation), mF)

        ax.set_xlim([-7, 7]), ax.set_ylim([-7, 7])
        ax.set_aspect(1)

        plt.clf()
        plt.xlim(-5, 5), plt.ylim(-5, 5)
        plt.axhline(), plt.axvline()

        xlist = np.append(mT[0, :], mT[0, 0])
        ylist = np.append(mT[1, :], mT[1, 0])
        plt.plot(
            xlist,
            ylist,
            "-r",
        )
        plt.show()
        plt.pause(0.001)
        if zoom:
            cx = cx + 0.05
            cy = cy + 0.05
        else:
            cx = cx - 0.05
            cy = cy - 0.05

        if cx >= scaleSup:
            zoom = False
        if cx <= scaleInf:
            zoom = True
