import pygame
from airplanegame import *
pygame.init()
class PlaneGame():
    def __init__(self):
        print ("initializing")
        self.screen = pygame.display.set_mode(SCREEN_RECT.size)
        self.clock = pygame.time.Clock()
        self.__create_sprites()
        pygame.time.set_timer(CREATE_ENENMY_EVENT,500)#这是1000毫秒
        pygame.time.set_timer(HERO_FIRE_EVENT,200)
    def __create_sprites(self):
        bg1 = Background()
        bg2 = Background(True)
        self.back_group = pygame.sprite.Group(bg1,bg2)
        self.enemy_group = pygame.sprite.Group()
        self.hero = Hero()
        self.hero_group = pygame.sprite.Group(self.hero)


    def start_game(self):
        print ("begining...")
        while True:
            self.clock.tick(FPS)
            self.__event_handler()
            self.__check_collide()
            self.__update_sprites()
            pygame.display.update()
            pass

    def __event_handler(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                print("退出游戏.....")
                PlaneGame.__game_over()
            elif event.type == CREATE_ENENMY_EVENT:
                print("enemy is coming！  ")
                #创建敌机精灵
                enemy = Enemy()
                self.enemy_group.add(enemy)
            elif event.type == HERO_FIRE_EVENT:
                self.hero.fire()
        keys_pressed = pygame.key.get_pressed()
        if keys_pressed[pygame.K_RIGHT]:
            self.hero.speed = 4
        elif keys_pressed[pygame.K_LEFT]:
            self.hero.speed = -4
        else :
            self.hero.speed = 0
    def __check_collide(self):
        pygame.sprite.groupcollide(self.hero.bullets,self.enemy_group,True,True)
        enemies = pygame.sprite.spritecollide(self.hero,self.enemy_group,True)
        if len(enemies) > 0:
            self.hero.kill()
            PlaneGame.__game_over()
    def __update_sprites(self):
        self.back_group.update()
        self.back_group.draw(self.screen)
        self.enemy_group.update()
        self.enemy_group.draw(self.screen)
        self.hero_group.update()
        self.hero_group.draw(self.screen)
        self.hero.bullets.update()
        self.hero.bullets.draw(self.screen)

    @staticmethod
    def __game_over():
        print("gameover!!")
        pygame.quit()
        exit()

if __name__ == '__main__':
    game = PlaneGame()
    game.start_game()
