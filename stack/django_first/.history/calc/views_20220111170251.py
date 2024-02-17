from django.shortcuts import render
from django.http import HttpResponse

"""Each view returns a response, either from templates or a direct http response
The returning element is based on the request coming from the url
"""


def home(request):
    # return HttpResponse('Hello World!')
    """
    render(request, template_name, context=None, content_type=None, status=None, using=None)
    :param request: the request object
    :param template_name: the template to be rendered
    :param context: the data to be passed to the template
    """
    return render(request, 'calc/home.html', {'name': 'Roger'})
