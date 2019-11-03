import pygame
from airplanegame import *

#游戏的初始化
pygame.init()
screen = pygame.display.set_mode((480,700))
bg = pygame.image.load("C:\\Users\\12091\\source\\repos\\py_game\\py_game\\images\\background.png")
#blit:绘制图像
screen.blit(bg,(0,0))
#update:更新屏幕显示
#pygame.display.update()
hero = pygame.image.load("C:\\Users\\12091\\source\\repos\\py_game\\py_game\\images\\me1.png")
screen.blit(hero,(187,500))#元组的第一个数值是水平坐标，第二个是垂直坐标
pygame.display.update()
clock = pygame.time.Clock()
#定义rect记录飞机的初始位置，102为x长度,126为y高度
hero_rect = pygame.Rect(187,500,102,126)




enemy = Gamesprite("C:\\Users\\12091\\source\\repos\\py_game\\py_game\\images\\enemy1.png")
enemy1 = Gamesprite("C:\\Users\\12091\\source\\repos\\py_game\\py_game\\images\\enemy1.png", 3)
enemy_group = pygame.sprite.Group(enemy,enemy1)


while True:
    clock.tick(60)#刷新频率
    hero_rect.y -= 5#向Y轴缩小的速度
    #判断飞机的位置
    if hero_rect.y <= -126:
        hero_rect.y = 700
    screen.blit(bg,(0,0))
    screen.blit(hero,hero_rect)


    enemy_group.update()
    enemy_group.draw(screen)




    pygame.display.update()


    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            print("退出游戏.....")
            pygame.quit()
            exit()

"""
for event in pygame.event.get():
if event.type == pygame.QUIT:
pygame.quit()
"""