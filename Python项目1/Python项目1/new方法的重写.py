class Musicplayer:
    def __new__(cls,*args,**kwargs):
        print ("创造对象，分配空间")
        intstance = super().__new__(cls)
        return intstance
    def __init__(self, *args, **kwargs):
        print("initializing")
player = Musicplayer()
print (player)