from django.shortcuts import redirect, render
from django.contrib.auth.models import User, auth

# Create your views here.

"""we are sending the form data back to the same view, register, this
is possible because the methods differ, GET vs. POST"""


def register(request):
    if request.method == 'POST':
        first_name = request.POST['first_name']
        last_name = request.POST['last_name']
        username = request.POST['username']
        email = request.POST['email']
        password1 = request.POST['password1']
        password2 = request.POST['password2']

        if password1 == password2:
            if User.objects.filter(username=username)
            user = User.objects.create_user(username=username, password=password1,
                                            email=email, first_name=first_name, last_name=last_name)
            user.save()
            print("user created")
        return redirect('/travello')

    else:
        return render(request, 'accounts/register.html')
