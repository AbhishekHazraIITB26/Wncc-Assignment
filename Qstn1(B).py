import requests
from bs4 import BeautifulSoup
import pandas as pd
url = 'https://itc.gymkhana.iitb.ac.in/wncc/soc/'
html_text= requests.get(url).text
soup = BeautifulSoup(html_text, 'lxml')
Project_names=[]
Mentors_Mentees=[]
c=[]
# loop through all URLs and extract data from each file
for link in soup.find_all('a'):
    href = link.get('href')
    if href and href.endswith('.html'): # check if the link is to an HTML file
        href='https://itc.gymkhana.iitb.ac.in'+href
        html_text2 = requests.get(href).text
        soup1=BeautifulSoup(html_text2,'lxml')
        Project_names.append(soup1.find('h2',class_='display1 m-3 p-3 text-center project-title').text)
        for i in soup1.find_all("li"):
          for j in i.find_all("p",class_="lead"):
               Mentors_Mentees.append(j.get_text())
    x=len(Mentors_Mentees)
        
    if x>1:
        l=""
        for f in Mentors_Mentees:
            l=l+f+" "+","
        c.append(l)
    
    Mentors_Mentees.clear()
Final_Tuple=list(zip(Project_names,c))
df=pd.DataFrame(Final_Tuple, columns=["NAME OF PROJECT","MENTORS, NUMBER OF MENTEES"])
df.to_csv("Abhishek Hazra.csv")

 
