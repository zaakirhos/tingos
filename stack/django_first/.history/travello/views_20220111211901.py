from django.shortcuts import render
from django.http import HttpResponse

"""Each view returns a response, either from templates or a direct http response
The returning element is based on the request coming from the url
"""


def index(request):
    return render(request, 'travello/index.html')

}