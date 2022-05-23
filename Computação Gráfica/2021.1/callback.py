# -*- coding: utf-8 -*-

zoom = 1
zoomRev = zoom / 2


def on_press(event):
    global zoom

    if event.button == 1:
        zoom = 1.5 * zoom
    elif event.button == 3:
        zoom = zoom * 0.75


def on_key(event):
    global end_loop
    global rotation
    global translation
    global scale

    if event.key == "q":
        end_loop = True
    elif event.key == "up":
        rotation += 0.5
    elif event.key == "down":
        rotation -= 0.5
    elif event.key == "left":
        translation += 0.5
    elif event.key == "right":
        translation -= 0.5
