import random
random.seed()
f = open("list.txt", "w")
f.write("20\n")
for i in range(20):
	f.write("%d\n" % (random.randint(0,99)))
f.close()
