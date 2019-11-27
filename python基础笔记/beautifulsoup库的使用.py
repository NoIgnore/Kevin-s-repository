from bs4 import BeautifulSoup

html = '''
<html><head><title>The Dormouse's story</title></head>
<body>
<p class="title"><b>The Dormouse's story</b></p>

<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="link1">Elsie</a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
and they lived at the bottom of a well.</p>
<p class="story">...</p>
'''
def generator_1():
	for n in range(100):
		yield n
a = generator_1()

soup = BeautifulSoup(html,'lxml')
print(next(a),soup.prettify())

print("-"*100)

print(next(a),soup.title)#next(a)=1
print(next(a),soup.title.name)
print(next(a),soup.title.string)
print(next(a),soup.title.parent.name)
print(next(a),soup.p)
print(next(a),soup.p["class"])
print(next(a),soup.a)
print(next(a),soup.find_all('a'))
print(next(a),soup.find(id='link3'))
'''
0 <html>
 <head>
  <title>
   The Dormouse's story
  </title>
 </head>
 <body>
  <p class="title">
   <b>
    The Dormouse's story
   </b>
  </p>
  <p class="story">
   Once upon a time there were three little sisters; and their names were
   <a class="sister" href="http://example.com/elsie" id="link1">
    Elsie
   </a>
   ,
   <a class="sister" href="http://example.com/lacie" id="link2">
    Lacie
   </a>
   and
   <a class="sister" href="http://example.com/tillie" id="link3">
    Tillie
   </a>
   ;
and they lived at the bottom of a well.
  </p>
  <p class="story">
   ...
  </p>
 </body>
</html>
----------------------------------------------------------------------------------------------------
1 <title>The Dormouse's story</title>
2 title
3 The Dormouse's story
4 head
5 <p class="title"><b>The Dormouse's story</b></p>
6 ['title']
7 <a class="sister" href="http://example.com/elsie" id="link1">Elsie</a>
8 [<a class="sister" href="http://example.com/elsie" id="link1">Elsie</a>, <a class="sister" href="http://example.com/lacie" id="link2">Lacie</a>, <a class="sister" href="http://example.com/tillie" id="link3">Tillie</a>]
9 <a class="sister" href="http://example.com/tillie" id="link3">Tillie</a>
[Finished in 0.2s]
'''