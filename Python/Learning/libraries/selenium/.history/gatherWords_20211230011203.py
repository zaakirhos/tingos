from selenium import webdriver

driver = webdriver.Chrome()

main = driver.get('https://app.memrise.com/course/254000/1500-advanced-english-words/')

section = driver.fin