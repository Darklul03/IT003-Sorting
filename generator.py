import os
import random
path = "./data"

if not os.path.exists(path):
    os.makedirs(path)

nums = [[random.uniform(0,1) for i in range(int(1e6))] for j in range(10)]
nums[0].sort()
nums[1].sort(reverse=True)

for i in range(10):
    with open(os.path.join(path,"input"+str(i)+".txt"),"w") as f:
        print(*["{0:.10f}".format(j) for j in nums[i]], sep='\n', file=f)
        f.close()