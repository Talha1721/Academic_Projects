import bs4
import requests
import csv

URL_LINK = 'national_unit_page_url.csv'
CSV_LINK = 'national_dataset_janakantha_news.csv'

def append_to_csv(row):

    global CSV_LINK

    with open(CSV_LINK, mode='a', newline='' , encoding='utf-8') as unit_new_article:
            news_article_writer = csv.writer(unit_new_article, delimiter=',' , quoting=csv.QUOTE_MINIMAL)
            news_article_writer.writerow(row)

    pass

def get_title_and_content(url):
    BASE_URL = url
    page = requests.get(BASE_URL)
    soup = bs4.BeautifulSoup(page.content, 'html.parser')


    newsTitle = soup.find_all("h1")[0].getText()
    newsTitle=newsTitle.strip()

    newsDate = soup.find("div", {"class": "article-info mb-4 md-text-center"})
    newsDate = newsDate.find_all("span")[0].getText()
    newsDate = newsDate.strip()

    article_text = soup.find("div", {"class": "article-details mb-5"})
    all_paragraphs = article_text("p")
    news_content = ""

    for paragraph in all_paragraphs:

        news_content += paragraph.getText()
        news_content=news_content.strip()

    
    cat="national"
    input_array = [cat, newsDate , newsTitle , news_content]
    append_to_csv(input_array)

    pass



with open(URL_LINK) as unit_url_csv:
    readCSV = csv.reader(unit_url_csv)

    i = 0

    for row in readCSV:
	print(i)
        get_title_and_content(row[0])

        i += 1
