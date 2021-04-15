from selenium import webdriver
driver = webdriver.Edge(r'D:/Firefox/msedgedriver',{})
def hhj():
    link="??"
    driver.get(link)
    hhj=r"form-control"
    Vmcode = driver.find_elements_by_class_name(hhj)
    if len(Vmcode)==0:
        driver.refresh()
        return
    try:
        driver.find_elements_by_class_name(hhj)[1].send_keys("2xxx")
        driver.find_elements_by_class_name(hhj)[0].send_keys("xxx")
    except:
        driver.find_element_by_id("name").send_keys("xxx")
        driver.find_element_by_id("new_item_1").send_keys("xxx")
    driver.find_element_by_id("button").click()
    driver.refresh()
while(True):
    hhj()