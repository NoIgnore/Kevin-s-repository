airplanegame.py
import random
import pygame
SCREEN_RECT = pygame.Rect(0,0,480,700)
FPS = 60
CREATE_ENENMY_EVENT = pygame.USEREVENT
HERO_FIRE_EVENT = pygame.USEREVENT + 1
class Gamesprite(pygame.sprite.Sprite):
    def __init__(self,image_name,speed=3):
        super().__init__()
        self.image = pygame.image.load(image_name)
        self.rect = self.image.get_rect()
        #get_rect()是image的方法，获取image的rect对象
        self.speed = speed
    
    def update(self):
        self.rect.y += self.speed#这个应该是敌机吧
class Background(Gamesprite):
    def __init__(self,is_alt=False):
        super().__init__("C:\\Users\\12091\\source\\repos\\py_game\\py_game\\images\\background.png")
        if is_alt:
            self.rect.y = -self.rect.height
    def update(self):
        super().update()
        if self.rect.y >= SCREEN_RECT.height:
            self.rect.y = -self.rect.height
class Enemy(Gamesprite):
    def __init__(self):
        super().__init__("C:\\Users\\12091\\source\\repos\\py_game\\py_game\\images\\enemy1.png")
        self.speed = random.randint(4,9)
        self.rect.bottom = 0
        max_x = SCREEN_RECT.width - self.rect.width
        self.rect.x = random.randint(0,max_x)

    def update(self):
        super().update()
        if self.rect.y >= SCREEN_RECT.height:
            print ("delete the plane    ")
            self.kill()
class Hero(Gamesprite):
    def __init__(self):
        super().__init__("C:\\Users\\12091\\source\\repos\\py_game\\py_game\\images\\me1.png",0)
        self.rect.centerx = SCREEN_RECT.centerx
        self.rect.bottom = SCREEN_RECT.bottom - 120
        self.bullets = pygame.sprite.Group()
    def update(self):
        self.rect.x += self.speed
        if self.rect.x < 0 :
            self.rect.x = 0
        elif self.rect.right > SCREEN_RECT.right:
            self.rect.right = SCREEN_RECT.right
    def fire(self):
        for i in (0,1,2):
            bullet = Bullet()
            bullet.rect.bottom = self.rect.y - i * 20
            bullet.rect.centerx = self.rect.centerx
            self.bullets.add(bullet)

class Bullet(Gamesprite):
    def __init__(self):
        super().__init__("C:\\Users\\12091\\source\\repos\\py_game\\py_game\\images\\bullet1.png",-5)
        
    def update(self):
        super().update()
        if self.rect.bottom < 0:
            self.kill()
    def __del__(self):
        print("bullet is deleting  ")