from selenium import webdriver
import os 
import time 
import ntplib 
c = ntplib.NTPClient() 
response = c.request('ntp.aliyun.com') 
ts = response.tx_time 
#_date = time.strftime('%Y-%m-%d',time.localtime(ts)) 
_time = time.strftime('%X',time.localtime(ts+0.7))
normaltime = '16:59:30'
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
driver=webdriver.Firefox()
#driver=webdriver.Edge()
name = ['adsf','adf','adsfads']
number = ['adf','rewh','hfdsfgf']
i_i = 0
def get_now_path(kkk):
    c1 = ntplib.NTPClient() 
    response1 = c1.request('ntp.aliyun.com')
    ts1 = response1.tx_time
    _time1 = time.strftime('%X',time.localtime(ts+0.7))
    return 'C:\\Users\\ttrre\\Desktop\\'+ str(timetransform(_time1)+kkk) +'.png'
def hhj(get_1):
    link="http://lxi.me/rfphd 「成都」"
    driver.get(link)
    hhj=r"form-control"
    Vmcode = driver.find_elements_by_class_name(hhj)
    if len(Vmcode)==0:
        driver.refresh()
        return
    global i_i
    try:
        driver.find_element_by_id("new_item_1").send_keys(number[get_1])
        driver.find_element_by_id("name").send_keys(name[get_1])
        driver.save_screenshot(get_now_path(i_i))
        driver.find_element_by_id("button").click()
        i_i+=1
    except:
        driver.find_elements_by_class_name(hhj)[1].send_keys(number[get_1])
        driver.find_elements_by_class_name(hhj)[0].send_keys(name[get_1])
        driver.save_screenshot(get_now_path(i_i))
        driver.find_element_by_id("button").click()
        i_i+=1
    driver.refresh()
while(i_i!=3):
    hhj(i_i)