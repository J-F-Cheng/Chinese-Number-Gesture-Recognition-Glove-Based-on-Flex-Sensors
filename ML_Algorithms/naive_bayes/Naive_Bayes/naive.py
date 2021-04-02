import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB

x_t = np.load('x_train.npy')
x_v = np.load('x_test.npy')
y_t = np.load('y_train.npy')
y_v = np.load('y_test.npy')

clf = GaussianNB()
clf.fit(x_t, y_t)

print(clf.score(x_t, y_t))
print(clf.score(x_v, y_v))
print(clf.epsilon_)
print('-------------------------------------------')
print(clf.sigma_)
print('-------------------------------------------')
print(clf.theta_)