from django.shortcuts import render
from django.http import HttpResponse
from .models import Destination

"""Each view returns a response, either from templates or a direct http response
The returning element is based on the request coming from the url
"""


def index(request):

    cities = ["New York", "Paris", "London", "Rome", "Barcelona"]
    prices = [1000, 2000, 3000, 4000, 5000]
    descriptions = ["Liberty Bell", "Eiffel Tower", "Big Ben", "Colosseum", "Sagrada Familia"]
    
    dests = []

    for i, (city, price, desc) in enumerate(zip(cities, prices, descriptions)):
        i
        dest = Destination(i, city, f"destination_{i+1}.jpg", desc, price) 
        dests.append(dest)

    return render(request, 'travello/index.html', {'dests': dests})

