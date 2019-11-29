class Mystructure:
	def __init__(self):
		self.data = 0
		self.next = None
a = Mystructure()
b = Mystructure()
b = a
for i in range(10):
	c = Mystructure()
	c.data = i+1
	b.next = c
	b = c
b.next = a
c = Mystructure()
c.next=a
for i in range(15):
	print(c.next.data,end="-")
	c = c.next
print("")