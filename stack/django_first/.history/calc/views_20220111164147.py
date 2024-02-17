from django.shortcuts import render
from django.http import HttpResponse

"""Each view returns a response, either from templates or a direct http response
The returning element is based on the request coming from the url
"""
def home(request):   
    # return HttpResponse('Hello World!')

    """
    render(request, template_name, context=None, content_type=None, status=None, using=None)
    
    """
    return render(request, 'calc/home.html')

