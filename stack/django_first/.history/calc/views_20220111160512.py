from django.shortcuts import render
from django.http import HttpResponse

"""Each view returns a response, either from templates or from a function. """
def home(request):
    return HttpResponse('Hello World!')

