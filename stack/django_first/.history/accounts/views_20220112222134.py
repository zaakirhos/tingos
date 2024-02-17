from django.shortcuts import render

# Create your views here.

"""we are sending the form data back to the same view, register, this
is possible because"""
def register(request):
    return render(request, 'accounts/register.html')