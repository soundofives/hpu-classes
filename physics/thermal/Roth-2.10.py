
# coding: utf-8

# In[1]:

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import math as math
get_ipython().magic('matplotlib inline')


# In[ ]:




# In[2]:

def macrostates(qt):
    return qt+1


# In[3]:

def microstates(n, q):
    omega = math.factorial(n+q-1)/(math.factorial(q)*math.factorial(n-1))
    return omega


# In[15]:

na = 200
nb = 100
nt = na+nb
qt = 100
qa = 0
qb = 0


# In[16]:

elements = []


# In[17]:

while qa < macrostates(qt):
    
    elements.append([qa, microstates(na,qa), qt-qa, microstates(nb,(qt-qa)), microstates(na,qa)*microstates(nb,(qt-qa))])
    ##elements.append([qa, microstates(na,qa)])
    
    qa = qa+1
print(elements)
dataFrame = pd.DataFrame(elements)


# In[18]:

dataFrame


# In[19]:

##PLOT MULTIPLICITY VS QA

data = microstates(na, qa)*microstates(nb,qb)
#data.columns=['y']

qaList = []
multList = []
for i in range(0, macrostates(qt)):
    qaList.append(i)
    multList.append(microstates(na,i))
    
yval = multList

xval = qaList

fig = plt.figure(figsize=(10,10))
plt.plot(xval,yval)
#plt.ylim(-0.5e-18,0.5e-18)
#plt.xlim(66400,70000)


# In[20]:

##CALCULATE PROBABILITY OF EACH MACROPARTITION

probs = []
maxmacro = 0;
maxprob = 0;
minmacro = 1e40;
minprob = 1
for i in range(0, macrostates(qt)):
    probs.append((microstates(na,i)*microstates(nb,qt-i))/(microstates(nt,qt)))
    if max(probs) > maxprob:
        maxprob = max(probs)
        maxmacro = i
    if min(probs) < minprob:
        minprob = min(probs)
        minmacro = i
        
yval = probs
xval = range(0,macrostates(qt))

fig = plt.figure(figsize=(10,10))
plt.plot(xval, yval)


# In[21]:

##Most probable macrostate:
print("Probability of ",maxmacro, " qa")
##Probability of this macrostate: 
print(max(probs))

##Least probable macrostate
print("Probability of ",minmacro, " qa")
##Probability of this macrostate
print(min(probs))


# In[22]:

microstates(nt, qt)


# In[ ]:




# In[ ]:



