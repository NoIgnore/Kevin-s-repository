# 导入Selenium包和time包
from selenium import webdriver
from time import sleep
driver = webdriver.Firefox()
def hhj():
    driver.get("https://f.lingxi360.com/f?fid=QQwLeTNyQpUkC&utm_bccid=LXEHwOX2KbX4rqE2")
    driver.find_element_by_id("btn_clear").click()
    driver.find_element_by_id("name").send_keys("杰哥")
    driver.find_element_by_id("member").send_keys("cypher")
    driver.find_element_by_id("button").click()
    driver.refresh()
while(True):
    hhj()