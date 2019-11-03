class Soldier:
    def __init__(self,name):
       self.name = name
       self.gun =  None
    def fire(self):
        if self.gun == None :
            print("No gun!")
            return
        self.gun.add_bullet(50)
        print("Fire!!!")
        self.gun.shoot()

class Gun:
    def __init__(self,name):
        self.name = name
        self.bullet_count = 0
    def add_bullet(self,count):
        self.bullet_count += count
    def shoot(self):
        if self.bullet_count <= 0:
            print ("No bullet")
            return
        self.bullet_count -= 1
        print (" %s  Biu ! , and %s bullet left" % 
               (self.name,self.bullet_count))
ak47 = Gun("AK47")
people = Soldier("Kevin")
people.gun = ak47
people.fire()
print (people.gun)