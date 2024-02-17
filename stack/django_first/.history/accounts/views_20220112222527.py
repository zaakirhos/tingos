from django.shortcuts import render

# Create your views here.

"""we are sending the form data back to the same view, register, this
is possible because the methods differ, GET vs. POST"""
def register(request):
    if request.method == 'POST':
        first_name = request.POST['first_name']
    else:
        return render(request, 'accounts/register.html')