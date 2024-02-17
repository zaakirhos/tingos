from django.shortcuts import render
from django.http import HttpResponse

"""Each view returns """
def home(request):
    return HttpResponse('Hello World!')

