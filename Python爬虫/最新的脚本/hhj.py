from selenium import webdriver
driver = webdriver.Edge(r'D:/Firefox/msedgedriver',{})
def hhj():
    link="https://ff.lingxi360.com/formfill?fid=imjEnaSiXxIS=&utm_bccid=LXExvNspO80BTohM&disable_autofill=0"
    driver.get(link)
    hhj=r"form-control"
    Vmcode = driver.find_elements_by_class_name(hhj)
    if len(Vmcode)==0:
        driver.refresh()
        return
    try:
        driver.find_elements_by_class_name(hhj)[1].send_keys("2018081311006")
        driver.find_elements_by_class_name(hhj)[0].send_keys("洪浩杰")
    except:
        driver.find_element_by_id("name").send_keys("洪浩杰")
        driver.find_element_by_id("new_item_1").send_keys("2018081311006")
    driver.find_element_by_id("button").click()
    driver.refresh()
while(True):
    hhj()