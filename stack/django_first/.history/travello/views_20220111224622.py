from django.shortcuts import render
from django.http import HttpResponse
from .models import Destination

"""Each view returns a response, either from templates or a direct http response
The returning element is based on the request coming from the url
"""


def index(request):

    cities = ["New York", "Paris", "London", "Rome", "Barcelona"]
    pri
    destinations = []

    for 
    dest1 = Destination()
    dest1.name = "Philly"
    dest1.img = "destination_1.jpg"
    dest1.desc = "Brotherly Love City"
    dest1.price = 500
    return render(request, 'travello/index.html', {'dest1': dest1})

