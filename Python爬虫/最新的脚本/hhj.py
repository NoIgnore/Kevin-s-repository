from selenium import webdriver
driver = webdriver.Edge(r'D:/Firefox/msedgedriver',{})
def hhj():
    link="https://f.lingxi360.com/f?fid=n7=EbhLzHY9ua&utm_bccid=LXEOWiccxPKIskHf"
    driver.get(link)
    hhj=r"form-control"
    Vmcode = driver.find_elements_by_class_name(hhj)
    if len(Vmcode)==0:
        driver.refresh()
        return
    name = '洪浩杰'
    number = '2018081311006'
    try:
        driver.find_element_by_id("btn_clear").click()
    except:
        trash=1
    try:
        driver.find_elements_by_class_name(hhj)[1].send_keys(number)
        driver.find_elements_by_class_name(hhj)[0].send_keys(name)
    except:
        driver.find_element_by_id("name").send_keys(name)
        driver.find_element_by_id("new_item_1").send_keys(number)
    driver.find_element_by_id("button").click()
    driver.refresh()
while(True):
    hhj()
