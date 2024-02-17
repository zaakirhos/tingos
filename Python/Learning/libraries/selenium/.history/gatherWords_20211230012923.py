from selenium import webdriver
import time

words = []

driver = webdriver.Chrome()

main = driver.get('https://app.memrise.com/course/254000/1500-advanced-english-words/')


for i in range(50):
    section = driver.find_element_by_xpath(
        '//*[@id="content"]/div/div/div[1]/div/a[1]')

    section.click()
    time.sleep(5)
    word = driver.find_element_by_xpath(
        '//*[@id="content"]/div/div/div[2]/div[4]/div[3]/div')
    print(word.text)
    driver.execute_script("window.history.go(-1)")
