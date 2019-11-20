import os
import requests
url = 'https://pic.ibaotu.com/00/51/34/88a888piCbRB.mp4'
root = "D://Pythontestpath//"
path =  root + "getvedio.mp4"
try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r = requests.get(url, stream=True)
        with open(path,'wb') as f:
            for chunk in r.iter_content(chunk_size=1024 * 1024):
                if chunk:
                    f.write(chunk)
        f.close()
        print ("Success...")
    else:
        print("File exists...")
except:
    print ("Failed to get..")
