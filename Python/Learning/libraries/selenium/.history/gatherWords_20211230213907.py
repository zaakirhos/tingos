import pymongo
import requests
import time
# from selenium import webdriver
# from selenium.webdriver.support.ui import WebDriverWait
# from selenium.webdriver.common.by import By
# from selenium.webdriver.support import expected_conditions as EC
# import time

# words = []

# driver = webdriver.Chrome()

# main = driver.get('https://app.memrise.com/course/254000/1500-advanced-english-words/')

# cookie = driver.find_element_by_xpath('/html/body/div[1]/a')
# cookie.click()
# # section = driver.find_element_by_xpath(
# #     '//*[@id="content"]/div/div/div[1]/div/a[11]')
# # time.sleep(3)
# # section.click()

# try:
#     for i in range(50):
#         section = driver.find_element_by_xpath(
#             f'//*[@id="content"]/div/div/div[1]/div/a[{i+1}]')
#         section.click()
#         # time.sleep(5)
#         for j in range(30):
#             word = driver.find_element_by_xpath(f'//*[@id="content"]/div/div/div[2]/div[{4+j}]/div[3]/div').text
#             defi = driver.find_element_by_xpath(f'//*[@id="content"]/div/div/div[2]/div[{4+j}]/div[4]/div').text
#             word_and_definition = {
#                 'word': word,
#                 'definition': defi
#             }
#             words.append(word_and_definition)
#         #click the browser backward once.
#         # time.sleep(1)
#         driver.execute_script("window.history.go(-1)")
# except Exception as e:
#     print("Failed")

# finally:
#     client = pymongo.MongoClient(
#         'mongodb+srv://zakir:mongo123@cluster0.abqkq.mongodb.net/zakir?retryWrites=true&w=majority')

#     db = client.get_database('pool')
#     wordC = db.words
#     wordC.delete_many({ })
#     wordC.insert_one({'words': words, 'count': len(words)})
    
#     print(len(words))
#     driver.close()


client = pymongo.MongoClient(
        'mongodb+srv://zakir:mongo123@cluster0.abqkq.mongodb.net/zakir?retryWrites=true&w=majority')
db = client.get_database('pool')
wordC = db.words

updating_doc = list(wordC.find({"_id": "61ce1361c1fa56f1ee5367d0"}))
updating_word = updating_doc["words"]
print(len())
new_set = []

for i in range(len(updating_word)):
    url = f"https://api.dictionaryapi.dev/api/v2/entries/en/{updating_word[i]}"
    response = requests.request("GET", url)
    response = response.json()
    print(response)
    # definition = response[0]["meanings"][0]["definitions"][0]["definition"]
    # except Exception as e:
    #     print(e, i)
    # finally:
    # new_set.append({"word": diff[i], "definition": definition})

# wordC.insert_one({'words': diff, 'count': len(diff)})

# url = "https://api.dictionaryapi.dev/api/v2/entries/en/theology"
# response = requests.request("GET", url).json()
# print(response)

# print(diff[28])
# url = f"https://www.dictionaryapi.com/api/v3/references/thesaurus/json/{diff[0]}?key=2e87c6b8-f1de-4822-971a-29dd639ba2ff"
# response = requests.request("GET", url).json()
# print(response[0]["shortdef"][0])