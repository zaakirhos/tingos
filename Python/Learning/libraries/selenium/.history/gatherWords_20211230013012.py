from selenium import webdriver
import time

words = []

driver = webdriver.Chrome()

main = driver.get('https://app.memrise.com/course/254000/1500-advanced-english-words/')


for i in range(50):
    section = driver.find_element_by_xpath(f'//*[@id="content"]/div/div/div[1]/div/a[i]')

    section.click()
    # time.sleep(5
    print(word.text)
    driver.execute_script("window.history.go(-1)")
