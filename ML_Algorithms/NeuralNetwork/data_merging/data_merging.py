import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import random

folder_names = ['fingerData_jc', 'fingerData_wjq', 'fingerData_zjt', 'fingerData_zs'] # Set folder name

all_x_train = []
all_y_train = []

how_many = 500 # indicate the file 

def random_get(gesture, number):
    index = random.sample(range(gesture.shape[0]), number)
    return gesture[index]

# Merge the data
for folder_name in folder_names:
    print('You have the folder', folder_name)
    # Read the gesture 0 to 1
    gesture0 = pd.read_csv('FingerData/'+folder_name+'/fingerdata0.csv')
    #gesture0.as_matrix()
    gesture0 = random_get(np.array(gesture0), how_many)
    gesture1 = pd.read_csv('FingerData/'+folder_name+'/fingerdata1.csv')
    #gesture1.as_matrix()
    gesture1 = random_get(np.array(gesture1), how_many)
    x_train = np.r_[gesture0[:, 0 : 5], gesture1[:, 0 : 5]]
    y_train = np.r_[gesture0[:, 5], gesture1[:, 5]]
    # Read the rest gesture data
    for i in range(2, 10):
        csvFile = 'FingerData/'+folder_name+'/fingerdata'
        csvFile += str(i)
        csvFile += '.csv'
        gestureData = pd.read_csv(csvFile)
        #gestureData.as_matrix()
        gestureData = random_get(np.array(gestureData), how_many)
        x_train = np.r_[x_train, gestureData[:, 0 : 5]]
        y_train = np.r_[y_train, gestureData[:, 5]]
    #x_train = x_train/1023.0
    all_x_train.append(x_train)
    all_y_train.append(y_train)

# Pre-process the data and save them
all_x_train = np.array(all_x_train) / 1023.0
all_x_train.resize((20000, 5))
all_y_train = np.array(all_y_train)
all_y_train.resize((20000))
np.save('FingerData_np/all_x.npy', all_x_train)
np.save('FingerData_np/all_y.npy', all_y_train)

x_train,x_test,y_train,y_test= train_test_split(all_x_train, all_y_train,test_size=0.3,random_state=150)

# Save the merged data files
np.save('FingerData_np/x_train.npy', x_train)
np.save('FingerData_np/y_train.npy', y_train)
np.save('FingerData_np/x_test.npy', x_test)
np.save('FingerData_np/y_test.npy', y_test)
