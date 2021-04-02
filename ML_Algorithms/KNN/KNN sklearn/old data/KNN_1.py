import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report, confusion_matrix

#url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"   # Assign colum names to the dataset
#names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'Class']    # Read dataset to pandas dataframe
#dataset = pd.read_csv(url, names=names)

names = ['thumb', 'index', 'middle', 'ring', 'little', 'gesture']
dataset = pd.read_csv('/Users/sjzzj/OneDrive - Imperial College London/AML_lab/fingerData/fingerdata_forknn1.csv', names=names)
dataset_test = pd.read_csv('/Users/sjzzj/OneDrive - Imperial College London/AML_lab/fingerData/fingerdata.csv', names=names)
dataset_test = dataset_test.sample(frac=0.1)

X_train = dataset.iloc[:, :-1].values
y_train = dataset.iloc[:, 5].values

X_test = dataset_test.iloc[:, :-1].values
y_test = dataset_test.iloc[:, 5].values
#X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20)    #20% for test



classifier = KNeighborsClassifier(n_neighbors=10)   #hyperparameter of KNN --- k
classifier.fit(X_train, y_train)       #training
y_pred = classifier.predict(X_test)   #prediction


#evaluation of the algorithm
print(confusion_matrix(y_test, y_pred))
print(classification_report(y_test, y_pred))


error = []
# Calculating error for K values between 1 and 40
for i in range(1, 40):
    knn = KNeighborsClassifier(n_neighbors=i)
    knn.fit(X_train, y_train)
    pred_i = knn.predict(X_test)
    error.append(np.mean(pred_i != y_test))

fig = plt.figure(figsize=(12, 6))
plt.plot(range(1, 40), error, color='red', linestyle='dashed', marker='o',
         markerfacecolor='blue', markersize=10)
plt.title('Error Rate K Value')
plt.xlabel('K Value')
plt.ylabel('Mean Error')
plt.show()
fig.savefig('test_error9.png', dpi=fig.dpi)
print(error)