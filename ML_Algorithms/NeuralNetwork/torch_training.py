#import nn
import pandas as pd
import numpy as np
#import random
import torch
from sklearn.model_selection import train_test_split
from torch.utils.data import TensorDataset, DataLoader
import torch.nn.functional as F

class Net(torch.nn.Module):
        def __init__(self):
            super(Net, self).__init__()
            self.l1 = torch.nn.Linear(5, 16)
            self.l2 = torch.nn.Linear(16, 10)
    
        def forward(self, x):
            x = F.relu(self.l1(x))
            x = F.softmax(self.l2(x))
            return x

def transform2OneZero(number):
    r = np.zeros(10)
    r[number] = 1
    return r

if __name__ == '__main__':
        
    #x_t,x_v,y_t,y_v= train_test_split(x_train, y_train,test_size=0.2,random_state=150)
    
    x_t = np.load('data_merging/FingerData_np/x_train.npy')
    x_v = np.load('data_merging/FingerData_np/x_test.npy')
    y_t = np.load('data_merging/FingerData_np/y_train.npy')
    y_v = np.load('data_merging/FingerData_np/y_test.npy')
    
    wholeDataSize = x_t.shape[0]
    x_t = torch.tensor(x_t, dtype = torch.float)
    x_v = torch.tensor(x_v, dtype = torch.float)
    y_t = torch.tensor(y_t, dtype = torch.long)
    trainloader = DataLoader(TensorDataset(x_t, y_t), batch_size=16, shuffle=True)
    # nn structure
    
    model = Net()
    
    loss_fn = torch.nn.CrossEntropyLoss()
    learning_rate = 3e-3
    optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)
    for epoch in range(60):  # loop over the dataset multiple times
        running_loss = 0.0
        for i, data in enumerate(trainloader, 0):
            # get the inputs; data is a list of [inputs, labels]
            inputs, labels = data
            #print(labels)
            #labels_ = torch.max(labels, 1)[1]
            # zero the parameter gradients
            optimizer.zero_grad()
    
            # forward + backward + optimize
            outputs = model(inputs)
            #print(outputs)
            loss = loss_fn(outputs, labels)
            loss.backward()
            optimizer.step()
    
            # print statistics
            running_loss += loss.item()
            #print(j)
        print('epoch', epoch)
        print('loss', running_loss/wholeDataSize)
    
    #result = model(x_v).detach().numpy()
    PATH = './gestureModel_3.pth'
    torch.save(model.state_dict(), PATH)
    
    #evaluation
    
    my_model = Net()
    my_model.load_state_dict(torch.load(PATH))
    result = my_model(x_v).detach().numpy()
    correct = 0
    for i in range(result.shape[0]):
        c = np.argmax(result[i])
        if c == y_v[i]:
            correct += 1
    print('The accuracy is ', correct/result.shape[0])