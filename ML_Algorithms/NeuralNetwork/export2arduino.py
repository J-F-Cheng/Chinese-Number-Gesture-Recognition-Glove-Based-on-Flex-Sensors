# -*- coding: utf-8 -*-
"""
Created on Fri Jan  1 16:53:23 2021

@author: c1027
"""

import torch_training as myTT
import torch
# get the C++ array for 2D array
def python2Cpp2D(tensor, name):
    s = 'const float ' + name + '[' + str(tensor.shape[0]) + '][' + str(tensor.shape[1]) + '] = {'
    for row in range(tensor.shape[0]): # For each row of the array
        s += '{'
        for col in range(tensor.shape[1]): # For each column of the array
            if col != tensor.shape[1] - 1:
                s += (str(tensor[row, col]) + ', ')
            else:
                s += (str(tensor[row, col])) # No need for ',' for the last entry
        if row != tensor.shape[0] - 1:
            s += '},\n' # At the end of the row, add symbol '},', and '\n' for new line
        else:
            s += '}'
    s += '};'
    print(s)

# get the C++ array for 1D array
def python2Cpp1D(tensor, name):
    s = 'const float ' + name + '[' + str(tensor.shape[0]) + '] = {'
    for col in range(tensor.shape[0]): # For each column
        if col != tensor.shape[0] - 1:
            s += (str(tensor[col]) + ', ')
        else:
            s += (str(tensor[col])) # No need for ',' for the last entry
    s += '};'
    print(s)

if __name__ == '__main__':
    # Load the model
    model = myTT.Net()
    PATH = './gestureModel_3.pth'
    model.load_state_dict(torch.load(PATH))
    #print(model.l1.weight.T.detach().numpy())
    #print(model.l1.bias)
    
    # Get the arrays
    python2Cpp2D(model.l1.weight.T.detach().numpy(), 'w1')
    python2Cpp1D(model.l1.bias.detach().numpy(), 'b1')
    python2Cpp2D(model.l2.weight.T.detach().numpy(), 'w2')
    python2Cpp1D(model.l2.bias.detach().numpy(), 'b2')