from django.shortcuts import render
from django.http import HttpResponse

"""Each view returns a response """
def home(request):
    return HttpResponse('Hello World!')

