import requests
from bs4 import BeautifulSoup
url = 'https://itc.gymkhana.iitb.ac.in/wncc/soc/'
html_text= requests.get(url).text
soup = BeautifulSoup(html_text, 'lxml')
Project_names=[]
Mentors=[]
Mentees=[]
Descriptions=[]
Resources_Prereqs=[]
i=0
# loop through all URLs and extract data from each file
for link in soup.find_all('a'):
    href = link.get('href')
    if href and href.endswith('.html'): # check if the link is to an HTML file
        href='https://itc.gymkhana.iitb.ac.in'+href
        html_text2 = requests.get(href).text
        soup1=BeautifulSoup(html_text2,'lxml')
        Project_names.append(soup1.find('h2',class_='display1 m-3 p-3 text-center project-title').text)        
print(Project_names)
 
