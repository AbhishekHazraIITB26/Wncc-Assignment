import requests
import urllib.request
from bs4 import BeautifulSoup
from inscriptis import get_text
import numpy as np
import pandas as pd 
import nltk



url = 'https://itc.gymkhana.iitb.ac.in/wncc/soc/'
reqs = requests.get(url)
soup = BeautifulSoup(reqs.text, 'html.parser')

# list to store data from all HTML files
data = []

# loop through all URLs and extract data from each file
for link in soup.find_all('a'):
    href = link.get('href')
    if href and href.endswith('.html'): # check if the link is to an HTML file
        href='https://itc.gymkhana.iitb.ac.in'+href
        response = requests.get(href)

        soup = BeautifulSoup(response.content, 'html.parser')
        text = soup.get_text()
        text1=str(text)
        text1=text.replace(" ","")
        print(text1)
