from selenium import webdriver
driver = webdriver.Edge(r'D:/Firefox/msedgedriver',{})
def hhj():
    link="https://f.lingxi360.com/f?fid=QQwLeTNyQpUkC&utm_bccid=LXEHwOX2KbX4rqE2"
    driver.get(link)
    hhj=r"form-control"
    Vmcode = driver.find_elements_by_class_name(hhj)
    if len(Vmcode)==0:
        driver.refresh()
        return
    driver.find_elements_by_class_name(hhj)[0].send_keys("洪浩杰")
    driver.find_elements_by_class_name(hhj)[1].send_keys("2018081311006")
    driver.find_element_by_id("button").click()
    driver.refresh()
while(True):
    hhj()