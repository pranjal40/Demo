import requests
from bs4 import BeautifulSoup
import csv

# URL of the page we're scraping
url = 'http://example.com'

# Send a GET request to the URL
response = requests.get(url)

# Parse the page content with BeautifulSoup
soup = BeautifulSoup(response.content, 'html.parser')

# Find and extract the data you're interested in
data = []
for item in soup.find_all('div', class_='example-class'):
    title = item.find('h2').text
    description = item.find('p').text
    data.append([title, description])

# Write the data to a CSV file
with open('output.csv', 'w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    writer.writerow(['Title', 'Description'])
    writer.writerows(data)

print('Data scraped and saved to output.csv')
