import pymongo
import requests
from bson.objectid import ObjectId
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

def getDiff(list1, list2):
    return list(set(list1) - set(list2))

client = pymongo.MongoClient(
    'mongodb+srv://zakir:mongo123@cluster0.abqkq.mongodb.net/zakir?retryWrites=true&w=majority')
db = client.get_database('pool')
wordC = db.words

updating_doc = wordC.find_one({"_id": ObjectId("61ce1361c1fa56f1ee5367d0")})
updating = list(updating_doc["words"])
new_word = updating_word

just_words = list(map(lambda w: w["word"], updating_word))


# for i in range(len(updating_word)):
#     url = f"https://api.dictionaryapi.dev/api/v2/entries/en/{updating_word[i]}"
#     response = requests.request("GET", url)
#     try:
#         resJSON = response.json()
#         if response.status_code == 429:
#             i -= 1
#             time.sleep(int(response.headers["Retry-After"]))
#         elif response.status_code == 200:
#             print(response, i)
#             definition = resJSON[0]["meanings"][0]["definitions"][0]["definition"]
#             new_word.append({"word": updating_word[i], "definition": definition})
#         else:
#             i += 1
#     except Exception as e:
#         break
# wordC.update_one({"_id": ObjectId("61ce1361c1fa56f1ee5367d0")},
#                  {"$set": {
#                      'words': new_word, 'count': len(new_word)
#                  }},
#                  upsert=True
# )

# url = "https://api.dictionaryapi.dev/api/v2/entries/en/theology"
# response = requests.request("GET", url).json()
# print(response)

# print(diff[28])
# url = f"https://www.dictionaryapi.com/api/v3/references/thesaurus/json/{diff[0]}?key=2e87c6b8-f1de-4822-971a-29dd639ba2ff"
# response = requests.request("GET", url).json()
# print(response[0]["shortdef"][0])
