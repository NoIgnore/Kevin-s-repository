class Animal:
    def eat(self):
        print("I am eating")
    def run(self):
        print("I am runing")
class Dog(Animal):
    def bark(self):
        print ("I am barking")
class Goddog(Dog):
    def fly(self):
        print ("I am flying")
    def bark(self):#方法的重写
        print ("I can bark louder!")
goddogy = Goddog()
goddogy.fly()
goddogy.bark()