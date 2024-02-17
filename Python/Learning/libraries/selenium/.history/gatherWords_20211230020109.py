from selenium import webdriver
import time

words = []

driver = webdriver.Chrome()

main = driver.get('https://app.memrise.com/course/254000/1500-advanced-english-words/')

section = driver.fin
time.sleep(3)
section.click()

# try:
#     for i in range(10, 50):
#         section = driver.find_element_by_css_selector(
#             f'#content > div > div > div.course-progress-container > div > a:nth-child(11)')
#         section.click()
#         # time.sleep(5)
#         for j in range(30):
#             word = driver.find_element_by_xpath(
#                 f'//*[@id="content"]/div/div/div[2]/div[{4+j}]/div[3]/div')
#             defi = driver.find_element_by_xpath(
#                 f'//*[@id="content"]/div/div/div[2]/div[{4+j}]/div[4]/div')
#             word_and_definition = {
#                 'word': word,
#                 'definition': defi
#             }
#             words.append(word_and_definition)
#         #click the browser backward once.
#         time.sleep(1)
#         driver.execute_script("window.history.go(-1)")
# except Exception as e:
#     print("Failed")
# finally:
#     print(len(words))