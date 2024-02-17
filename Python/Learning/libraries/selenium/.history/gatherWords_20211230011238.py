from selenium import webdriver

driver = webdriver.Chrome()

main = driver.get('https://app.memrise.com/course/254000/1500-advanced-english-words/')

section = driver.find_element_by_xpath('//*[@id="content"]/div/div/div[1]/div/a[1]')

section

