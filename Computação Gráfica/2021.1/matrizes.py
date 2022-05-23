import numpy as np


def matrix_rotation(theta):
    theta_rad = (theta / 180) * np.pi

    return np.array([[np.cos(theta_rad), -np.sin(theta_rad), 0], [np.sin(theta_rad), np.cos(theta_rad), 0], [0, 0, 1]])


def matrix_scale(cx, cy):
    return np.array([[cx, 0, 0], [0, cy, 0], [0, 0, 1]])


def matrix_translation_origin(x, y):
    return np.array([[1, 0, -x], [0, 1, -y], [0, 0, 1]])


def matrix_translation(x, y):
    return np.array([[1, 0, x], [0, 1, y], [0, 0, 1]])
