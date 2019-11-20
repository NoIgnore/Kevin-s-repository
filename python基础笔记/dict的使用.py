dict = {'Name': 'Zara', 'Age': 27}

print ("Value : %s" %  dict.get('Age'))
print ("Value : %s" %  dict.get('Sex', "Never"))
print(dict['Name'])
if dict['Name'] == dict.get('Name'):
	print ("ture")