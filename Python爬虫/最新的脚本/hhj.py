from selenium import webdriver
import os 
import time 
import ntplib 
c = ntplib.NTPClient() 
response = c.request('ntp.aliyun.com') 
ts = response.tx_time 
#_date = time.strftime('%Y-%m-%d',time.localtime(ts)) 
_time = time.strftime('%X',time.localtime(ts+0.7))
normaltime = '11:59:30'
presentime = _time
def timetransform(a):
    h_to_s = (int(a[0])*10+int(a[1]))*3600
    m_to_s = (int(a[3])*10+int(a[4]))*60
    second = int(a[6])*10+int(a[7])
    allsecond = h_to_s+m_to_s+second
    return allsecond
nn = timetransform(normaltime)
pp = timetransform(presentime)
minus = nn-pp
print(minus)
if(minus>=0):
    time.sleep(minus)
#driver = webdriver.Edge(r'D:/Firefox/msedgedriver',{})
driver = webdriver.Firefox()
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
        driver.find_element_by_id("button").click()
        hhj2=1
    except:
        driver.find_elements_by_class_name(hhj)[1].send_keys(number)
        driver.find_elements_by_class_name(hhj)[0].send_keys(name)
        driver.find_element_by_id("button").click()
        hhj2=1
    driver.refresh()
while(hhj2!=1):
    hhj()