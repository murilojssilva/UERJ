import numpy as np
import matplotlib.pyplot as plt
import matrizes as mt
import callback as cb


def anima(hx):

    po = np.transpose(hx)

    xmin = np.amin(po[0, :])
    xmax = np.amax(po[0, :])

    ymin = np.amin(po[1, :])
    ymax = np.amax(po[1, :])

    x = (xmin + xmax) / 2
    y = (ymin + ymax) / 2

    plt.close("all")
    fig, ax = plt.subplots()
    ax.cla()

    cid = fig.canvas.mpl_connect("button_press_event", cb.on_press)
    cid = fig.canvas.mpl_connect("key_press_event", cb.on_key)

    cx = 1.0
    cy = 1.0
    zoomIn = True
    cb.end_loop = False

    cb.rotation = 1
    cb.translation = 1

    while not cb.end_loop:
        for theta in range(0, 360, 5):

            cb.zoomRev = cb.zoom / 2

            if cb.end_loop == True:
                break

            theta_1 = theta * cb.velocidade_rotacao

            theta_2 = theta * cb.velocidade_translacao

            if theta_2 > 360:
                continue

            tr_1 = np.matmul(mt.matrix_rotation(theta_1), mt.matrix_translation_origin(x, y))
            tr_2 = np.matmul(mt.matrix_scale(cx, cy), tr_1)
            tr_3 = np.matmul(mt.matrix_translation(x, y), tr_2)

            matrix = np.matmul(tr_3, po)

            matrixT = np.matmul(mt.matrix_rotation(theta_2), matrix)

            plt.clf()
            plt.xlim((-xmax * 4, xmax * 4)), plt.ylim((-ymax * 4, ymax * 4))
            xlist = np.append(matrixT[0, :], matrixT[0, 0])
            ylist = np.append(matrixT[1, :], matrixT[1, 0])
            plt.plot(
                xlist,
                ylist,
                "-r",
            )
            plt.fill_between(xlist, ylist)
            plt.show()
            plt.pause(0.001)

            if zoomIn:
                cx += 0.02
                cy += 0.02
            else:
                cx -= 0.02
                cy -= 0.02

            if cx >= cb.zoom:
                zoomIn = False
            if cx <= cb.zoomRev:
                zoomIn = True
