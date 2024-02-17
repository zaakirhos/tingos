from django.shortcuts import render

# Create your views here.

# we are 
def register(request):
    return render(request, 'accounts/register.html')