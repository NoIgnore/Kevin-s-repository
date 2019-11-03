class Cat:
    def __init__(self,new_name):
        self.name = new_name
    def eat(self):
        print ("cat is eating")
    def run(self):
        print ("cat is runing")
    def __str__(self):
        return "I am %s " % self.name
tom = Cat("Tom")
print (tom)
tom.eat()
tom.run()
