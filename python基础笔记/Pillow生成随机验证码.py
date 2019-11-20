from PIL import Image, ImageDraw, ImageFont, ImageFilter
import random

def rndChar():
    '''随机字母'''
    return chr(random.randint(65, 90))  # a-z的ASCII码

def rndColor():
    '''随机颜色(rgb)'''
    return (random.randint(64, 255), random.randint(64, 255), random.randint(64, 255))

def rndColor2():
    '''随机颜色(rgb)'''
    return (random.randint(32, 127), random.randint(32, 127), random.randint(32, 127))

def draw_txt_image():
    '''创建随机颜色文字图像'''
    # 240 x 60:
    width = 60 * 4
    height = 60
    image = Image.new('RGB', (width, height), (255, 255, 255))    # 创建RGB图像image对象

    font_fullpath = r'C:\Windows\Fonts\Arial.ttf'  # win下需要全路径
    font = ImageFont.truetype(font_fullpath, 36)  # 创建Font对象
    draw = ImageDraw.Draw(image)  # 创建Draw对象

    for x in range(width):        # 填充每个像素
        for y in range(height):
            draw.point((x, y), fill=rndColor())
    for t in range(4):            # 输出文字
        draw.text((60 * t + 10, 10), rndChar(), font=font, fill=rndColor2())

    image = image.filter(ImageFilter.BLUR)  # 模糊
    image.save(r'D:\Pythontestpath\code.jpg', 'jpeg')# 把图像用jpeg格式保存:


if __name__ == '__main__':
    draw_txt_image()