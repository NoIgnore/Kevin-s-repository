import os 
import time 
import ntplib 
c = ntplib.NTPClient() 
response = c.request('ntp.aliyun.com') 
ts = response.tx_time 
_date = time.strftime('%Y-%m-%d',time.localtime(ts)) 
_time = time.strftime('%X',time.localtime(ts+0.7)) 
os.system('date {} && time {}'.format(_date,_time))