class Musicplayer(object):
    instance = None
    def __new__(cls,*args,**kwargs):
        if cls.instance is None:
            cls.instance = super().__new__(cls)
            
        return cls.instance
player1 = Musicplayer()
print (player1)
player2 = Musicplayer()
print (player2)
"""
<__main__.Musicplayer object at 0x0000024FB5AFE888>
<__main__.Musicplayer object at 0x0000024FB5AFE888>
请按任意键继续. . .
（返回结果如上）
"""