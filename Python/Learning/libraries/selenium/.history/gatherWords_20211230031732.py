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
evident adj.
evolution n.
evolve v.
exceed v.
exception n.
excessive adj.
exclude v.
exotic adj.
expansion n.
expedition n.
expertise n.
exploit v.
exposure n.
extension n.
extensive adj.
extensively adv.
extract n.
fabric n.
fabulous adj.
faculty n.
failed adj.
fake adj.
fame n.
fantasy n.
fare n.
firefighter n.
firework n.
firm adj.
firmly adv.
flavor n.
fond adj.
fool n.
forbid v.
forecast n., v.
format n.
formation n.
formerly adv.
fortunate adj.
forum n.
fossil n.
foundation n.
founder n.
fraction n.
fragment n.
framework n.
fraud n.
freely adv.
frequent adj.
fulfill v.
full-time adj./adv.
fundamentally adv.
furious adj.
gallon n.
gaming n.
gay adj.
gender n.
gene n.
genetic adj.
genius n.
genuine adj.
genuinely adv.
gesture n.
globalization n.
globe n.
golden adj.
goodness n.
gorgeous adj.
graphic adj.
graphics n.
greatly adv.
greenhouse n.
guideline n.
habitat n.
harbor n.
headquarters n.
heal v.
healthcare n.
helmet n.
hence adv.
herb n.
hidden adj.
hilarious adj.
hip n.
historian n.
homeless adj.
honesty n.
honey n.
hook n.
hopefully adv.
hunger n.
hypothesis n.
icon n.
ID n.
identical adj.
illusion n.
immigration n.
immune adj.
implement v.
implication n.
incentive n.
incorporate v.
incorrect adj.
independence n.
index n.
indication n.
inevitable adj.
inevitably adv.
infer v.
inflation n.
info n.
infrastructure n.
inhabitant n.
inherit v.
ink n.
innovation n.
innovative adj.
input n.
insert v.
inspector n.
installation n.
instant adj.
instantly adv.
integrate v.
intellectual adj.
interact v.
interaction n.
interpretation n.
interval n.
invade v.
invasion n.
investor n.
isolate v.
isolated adj.
jail n., v.
jet n.
joint adj., n.
journalism n.
jury n.
kindergarten n.
kit n.
ladder n.
landing n.
lane n.
lately adv.
legend n.
lens n.
lifetime n.
lighting n.
likewise adv.
limitation n.
literally adv.
literary adj.
litter n.
logo n.
lottery n.
loyal adj.
lyric n.
makeup n.
making n.
manufacture v.
manufacturing n.
marathon n.
margin n.
marker n.
martial adj.
mate n., v.
mechanic n.
mechanical adj.
mechanism n.
medal n.
medication n.
membership n.
memorable adj.
metaphor n.
miner n.
miserable adj.
mode n.
modest adj.
monster n.
monthly adj.
monument n.
moreover adv.
mortgage n.
mosque n.
mosquito n.
motion n.
motivate v.
motivation n.
moving adj.
myth n.
naked adj.
nasty adj.
navigation n.
nearby adj., adv.
necessity n.
negotiate v.
negotiation n.
neutral adj.
newly adv.
nickel n.
norm n.
notebook n.
novelist n.
nowadays adv.
nursing adj.
nutrition n.
obesity n.
observer n.
obstacle n.
occupation n.
occupy v.
offender n.
ongoing adj.
openly adv.
opera n.
operator n.
optimistic adj.
orchestra n.
organic adj.
outfit n.
output n.
outstanding adj.
overcome v.
overnight adv.
ownership n.
oxygen n.
packet n.
palm n.
panic n.
parade n.
parallel adj., n.
participation n.
partnership n.
part-time adj./adv.
passionate adj.
password n.
patch n.
patience n.
pause v., n.
peer n.
penalty n.
perceive v.
perception n.
permanently adv.
pharmacy n.
physician n.
pill n.
pity n.
placement n.
portion n.
potentially adv.
precede v.
precious adj.
precise adj.
precisely adv.
predictable adj.
preference n.
presidential adj.
pride n.
primarily adv.
prior adj.
probability n.
probable adj.
proceed v.
programming n.
progressive adj.
prohibit v.
promising adj.
promotion n.
prompt v.
proportion n.
protein n.
protester n.
psychological adj.
publicity n.
publishing n.
punk n.
purely adv.
pursuit n.
puzzle n.
"""
