from selenium import webdriver
driver = webdriver.Edge(r'D:/Firefox/msedgedriver',{})
hhj2=0
def hhj():
    link="https://f.lingxi360.com/f?fid=n7=EbhLzHY9ua&utm_bccid=LXEOWiccxPKIskHf"
    driver.get(link)
    hhj=r"form-control"
    Vmcode = driver.find_elements_by_class_name(hhj)
    if len(Vmcode)==0:
        driver.refresh()
        return
    name = 'xxx'
    number = 'xxxxxxxxx'
    global hhj2
    try:
        driver.find_element_by_id("new_item_1").send_keys(number)
        driver.find_element_by_id("name").send_keys(name)
        hhj2=1
    except:
        driver.find_elements_by_class_name(hhj)[1].send_keys(number)
        driver.find_elements_by_class_name(hhj)[0].send_keys(name)
        hhj2=1
    driver.find_element_by_id("button").click()
    driver.refresh()
while(hhj2!=1):
    hhj()
