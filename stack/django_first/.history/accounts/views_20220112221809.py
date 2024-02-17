from django.shortcuts import render

# Create your views here.

# we are usi
def register(request):
    return render(request, 'accounts/register.html')