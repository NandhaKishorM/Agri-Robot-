import numpy as np
a1 = 0.185
a2 = 0.155
x = 0.028
y = 0
def inverse_kinematics(x,y,a1,a2):
    x2 = np.square(x)
    y2 = np.square(y)
    a = np.square(a1)
    b= np.square(a2)
    c = 2*a1*a2
    q2 = np.arccos(x2+y2-a-b/c)
    
    #q2 = np.degrees(q2)
    q1 = np.arctan(y2/x2) - np.arctan((a2*np.sin(q2)) / (a1+a2*np.cos(q2)))
   
    q1 = np.degrees(q1)
    q2 = np.degrees(q2)
    return q1,q2

q1,q2 = inverse_kinematics(x,y,a1,a2)
print(q1)
print(q2)
