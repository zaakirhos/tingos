import pymongo
import random
import names
import json
import requests

client = pymongo.MongoClient('mongodb+srv://zakir:mongo123@cluster0.abqkq.mongodb.net/zakir?retryWrites=true&w=majority')

db = client.get_database('pool')

accounts = db.accounts
quotes = db.quotes

# print(accounts.count_documents({}))

# accounts.delete_many({ }) # removes all the existing documents

# months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']

# # insert 1000 records to the collection
# leading_zero_indexer = 3
# new_digit_updater = 10
# gender = ['male', 'female']

# for i in range(1, 20):
#     first_name = names.get_first_name(gender=random.choice(gender))
#     last_name = names.get_last_name()
#     full_name = first_name + ' ' + last_name
#     if i/new_digit_updater == 1:
#         new_digit_updater *=10
#         leading_zero_indexer -=1
#     account = {
#         'account_num': leading_zero_indexer*'0' + str(i),
#         'first_name': first_name,
#         'last_name': last_name,
#         'full_name': full_name,
#         'DOB': random.choice(months) +'-' + str(random.randint(1, 30)) + '-' + str(random.randint(1940, 2031)),
#         'balance' :  round(10000*random.random() +1, 2)
#     }
#     accounts.insert_one(account)

# print(accounts.count_documents({}))
# item = accounts.find_one()
# print(item["first_name"])


# api_url = "https://zenquotes.io/api/quotes"
# response = requests.get(api_url)
# print(response.json())

setTwo = []
api_url = "https://zenquotes.io/api/quotes"
for _ in range(100):
    response = requests.get(api_url)
    print(len(response.json()))
    for q in response.json():
        quote = {
            "text": q['q'],
            "author": q['a']
        }
        if quote not in setTwo:
            setTwo.append(quote)

print(len(setTwo))
with open('quotes.json', 'r') as f:
    f.write(json.dumps(data))
    f.write(",")
    f.close()
