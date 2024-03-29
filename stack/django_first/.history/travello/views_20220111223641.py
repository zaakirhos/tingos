from django.shortcuts import render
from django.http import HttpResponse
from .models import Destination

"""Each view returns a response, either from templates or a direct http response
The returning element is based on the request coming from the url
"""


def index(request):

    dest1 = Destination()
    dest1.name = "Philly"
    dest1.desc = "The city that never sleeps"
    return render(request, 'travello/index.html', {'dest1': dest1})

