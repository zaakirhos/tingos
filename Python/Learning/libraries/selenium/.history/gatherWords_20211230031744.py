import pymongo
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


# client = pymongo.MongoClient(
#         'mongodb+srv://zakir:mongo123@cluster0.abqkq.mongodb.net/zakir?retryWrites=true&w=majority')

# db = client.get_database('pool')
# wordC = db.words
# print(wordC.count_documents({}))
# # wordC.insert_one({'words': words, 'count': len(words)})
# #     print(len(words))

token = """B2
absorb v.
abstract adj.
accent n.
accidentally adv.
accommodate v.
accommodation n.
accomplish v.
accountant n.
accuracy n.
accurately adv.
acid n.
acre n.
activate v.
addiction n.
additionally adv.
adequate adj.
adequately adv.
adjust v.
affordable adj.
aged adj.
agriculture n.
AIDS n.
alien n.
alongside prep.
altogether adv.
ambitious adj.
ambulance n.
amusing adj.
analyst n.
ancestor n.
animation n.
annually adv.
anticipate v.
anxiety n.
apology n.
applicant n.
appropriately adv.
arrow n.
artwork n.
asset n.
assign v.
assistance n.
assumption n.
assure v.
astonishing adj.
athletic adj.
attachment n.
audio adj.
awareness n.
awkward adj.
badge n.
balanced adj.
ballet n.
balloon n.
barely adv.
bargain n.
basement n.
basket n.
bat n.
beneficial adj.
beside prep.
besides prep., adv.
bias n.
bid n., v.
biological adj.
blanket n.
blow n.
bold adj.
bombing n.
boost v., n.
bound adj.
brick n.
briefly adv.
broadcaster n.
broadly adv.
buck n.
bug n.
cabin n.
canal n.
candle n.
carbon n.
castle n. B2
casual adj.
cave n.
certainty n.
certificate n.
challenging adj.
championship n.
charming adj.
chase v., n.
cheek n.
cheer v., n.
chop v.
circuit n.
civilization n.
clarify v.
classify v.
cliff n.
clinic n.
clip n.
coincidence n.
collector n.
colony n.
colorful adj.
comic adj., n.
commander n.
comparative adj.
completion n.
compose v.
composer n.
compound n.
comprehensive adj.
comprise v.
compulsory adj.
concrete adj., n.
confess v.
confusion n.
consequently adv.
conservation n.
considerable adj.
considerably adv.
consistently adv.
conspiracy n.
consult v.
consultant n.
consumption n.
controversial adj.
controversy n.
convenience n.
convention n.
conventional adj.
convey v.
convincing adj.
cop n.
cope v.
corporation n.
corridor n.
counter (long flat surface) n.
coverage n.
cowboy n.
crack v., n.
craft n.
creativity n.
critically adv.
cruise n., v.
cue n.
curious adj.
curriculum n.
cute adj.
dairy n., adj.
dare v.
darkness n.
database n.
deadline n.
deadly adj.
dealer n.
deck n.
defender n.
delete v.
delighted adj. B2
democracy n.
democratic adj.
demonstration n.
depart v.
dependent adj.
deposit n., v.
depression n.
derive v.
desperately adv.
destruction n.
determination n.
devote v.
differ v.
dime n.
disability n.
disabled adj.
disagreement n.
disappoint v.
disappointment n.
discourage v.
disorder n.
distant adj.
distinct adj.
distinguish v.
distract v.
disturb v.
dive v., n.
diverse adj.
diversity n.
divorce n., v.
dominant adj.
donation n.
dot n.
dramatically adv.
drought n.
dull adj.
dump v.
duration n.
dynamic adj.
eager adj.
economics n.
economist n.
editorial adj.
efficiently adv.
elbow n.
electronics n.
elegant adj.
elementary adj.
eliminate v.
embrace v.
emission n.
emotionally adv.
empire n.
enjoyable adj.
entertaining adj.
entrepreneur n.
envelope n.
equip v.
equivalent n., adj.
era n.
erupt v.
essentially adv.
ethic n.
ethnic adj.
evaluation n

"""
