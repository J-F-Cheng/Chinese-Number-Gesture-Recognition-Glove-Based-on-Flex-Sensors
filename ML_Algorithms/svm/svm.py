import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split

# Load the training and testing data
x_t = np.load('train_test/x_train.npy')
x_v = np.load('train_test/x_test.npy')
y_t = np.load('train_test/y_train.npy')
y_v = np.load('train_test/y_test.npy')

from sklearn.svm import SVC, LinearSVC
from sklearn.multiclass import OneVsRestClassifier
clf = OneVsRestClassifier(SVC(C = 1e3, kernel = 'linear'))
clf.fit(x_t, y_t)

np.set_printoptions(suppress=True)
# Get the model parameters
print(clf.score(x_v, y_v))
print(clf.score(x_t, y_t))
print(clf.coef_)
print(clf.intercept_)
n = 5
a = x_v[n:n+1, :]
print('a is ', a*1023)
print(np.dot(clf.coef_,a.T)+clf.intercept_)
print(clf.predict(a))