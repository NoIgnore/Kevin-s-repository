# 导入Selenium包和time包
from selenium import webdriver
from time import sleep
driver = webdriver.Firefox()
def hhj():
    driver.get("http://yck.mumuceo.com/")
    hhj=r"form-control.span6"
    Vmcode = driver.find_elements_by_class_name(hhj)
    if len(Vmcode)==0:
        driver.refresh()
        return
    #driver.find_element_by_id("btn_clear").click()
    driver.find_elements_by_class_name(hhj)[0].send_keys("姓名")
    driver.find_elements_by_class_name(hhj)[1].send_keys("学号")
    driver.find_element_by_id("button").click()
    driver.refresh()
while(True):
    hhj()