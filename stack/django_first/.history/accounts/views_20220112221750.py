from django.shortcuts import render

# Create your views here.

# we are using this same 
def register(request):
    return render(request, 'accounts/register.html')