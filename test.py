import numpy as np


np.set_printoptions(edgeitems=30, linewidth=100000,
                    formatter=dict(float=lambda x: "%.15g" % x))


# A = np.array([
#        [1, 5, 3],
#        [4, 5, 5],
#        [7, 8, 9]])


A = np.array([
    [0, 0, -np.pi/2, 89 * np.pi / 2000],
    [0, 0, 0, 0],
    [np.pi/2, 0, 0, 0],
    [0, 0, 0, 0]])


B = A
QQQ = np.eye(np.size(A, 1))


mu1 = 0
mu2 = float('nan')

for i in range(10000):
    [Q, R] = np.linalg.qr(B)
    B = np.dot(R, Q)

    QQQ = np.dot(QQQ, Q)

Q = QQQ
R = B

# Q = np.array([
#    [0.3159072174397452, -0.9485941878747374, 0.0192794372258135],
#    [0.4747040458534322, 0.1404300246343774, -0.8688702302597152],
#    [0.8214978385971934, 0.283634403610448, 0.49466435718443]])
# R = np.array([
#    [16.3146667058391017, -3.0386548755318708, -3.6911370657721734],
#    [0, -1.6491690257162538, 1.772592369691685],
#    [0, 0, 0.3345023198771524]])


print("values:\n", R)
print()
print("schur:\n", Q)
print()


V = np.eye(np.size(A, 1))
for i in range(1, np.size(A, 1)):
    # print(np.dot(R[i, i], np.eye(i)))
    # print(R[0:i, 0:i])
    # print(i, "eye:\n", np.dot(R[i, i], np.eye(i)))
    # print(i, "thing subtracting:\n", R[0:i, 0:i])
    # print(i, "before inverse:\n", np.dot(R[i, i], np.eye(i)) - R[0:i, 0:i])
    # print(i, "upper_biased_factor:\n", np.linalg.inv(np.dot(R[i, i], np.eye(i)) - R[0:i, 0:i]))
    # print(i, "column_vector:\n", R[0:i, i])
    print("What's inside:", np.dot(R[i, i], np.eye(i)) - R[0:i, 0:i])
    temp_inv = np.dot(R[i, i], np.eye(i)) - R[0:i, 0:i]
    try:
        temp_inv = np.linalg.inv(temp_inv)
    except np.linalg.LinAlgError:
        temp_inv = np.eye(i)
    V[0:i, i] = np.dot(temp_inv, R[0:i, i])
    # print(i, "result:\n", V[0:i, i])
    # print()


print()
print(V)
print()


# W_norm = np.dot(Q, V)
# W_norm[:, 0] = W_norm[:, 0] / W_norm[2, 0]
# W_norm[:, 1] = W_norm[:, 1] / W_norm[2, 1]
# W_norm[:, 2] = W_norm[:, 2] / W_norm[2, 2]
#
# print(W_norm)


# print(Q)
# print(R)

# [Q, R] = np.linalg.qr(A)

# v = np.dot(R, Q)
# print(v)
