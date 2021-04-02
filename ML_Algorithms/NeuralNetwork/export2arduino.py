# -*- coding: utf-8 -*-
"""
Created on Fri Jan  1 16:53:23 2021

@author: c1027
"""

import torch_training as myTT
import torch

def python2Cpp2D(tensor, name):
    s = 'const float ' + name + '[' + str(tensor.shape[0]) + '][' + str(tensor.shape[1]) + '] = {'
    for row in range(tensor.shape[0]):
        s += '{'
        for col in range(tensor.shape[1]):
            if col != tensor.shape[1] - 1:
                s += (str(tensor[row, col]) + ', ')
            else:
                s += (str(tensor[row, col]))
        if row != tensor.shape[0] - 1:
            s += '},\n'
        else:
            s += '}'
    s += '}'
    print(s)

def python2Cpp1D(tensor, name):
    s = 'const float ' + name + '[' + str(tensor.shape[0]) + '] = {'
    for col in range(tensor.shape[0]):
        if col != tensor.shape[0] - 1:
            s += (str(tensor[col]) + ', ')
        else:
            s += (str(tensor[col]))
    s += '}'
    print(s)

if __name__ == '__main__':
    model = myTT.Net()
    PATH = './gestureModel_3.pth'
    model.load_state_dict(torch.load(PATH))
    #print(model.l1.weight.T.detach().numpy())
    #print(model.l1.bias)
    python2Cpp2D(model.l1.weight.T.detach().numpy(), 'w1')
    python2Cpp1D(model.l1.bias.detach().numpy(), 'b1')
    python2Cpp2D(model.l2.weight.T.detach().numpy(), 'w2')
    python2Cpp1D(model.l2.bias.detach().numpy(), 'b2')