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
    
    dest

    for i, (city, price, desc) in enumerate(zip(cities, prices, descriptions)):
        dest = Destination(i, city, f"description_{i+1}.jpg", desc, price) 
         # id, name, img, desc, pric
    return render(request, 'travello/index.html', {'dest1': dest1})

