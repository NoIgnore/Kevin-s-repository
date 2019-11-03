class Cat:
    def __init__(self,new_name):
        self.name = new_name
    def eat(self):
        print ("cat is eating")
    def run(self):
        print ("cat is runing")
tom = Cat("Tom")
print (tom.name)