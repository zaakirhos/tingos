from django.shortcuts import redirect, render
from django.contrib import messages
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
            if User.objects.filter(username=username).exists():
                messages.info(request, "Username Taken")
                return redirect('/accounts/register')
            elif User.objects.filter(email=email).exists():
                messages.info(request, "Email Taken")
                return redirect('/accounts/register')
            else:
                user = User.objects.create_user(username=username, password=password1,
                                                email=email, first_name=first_name, last_name=last_name)
                user.save()
                print("user created")
            return redirect('/accounts/login')
        else:
            messages.info(request, "Password not matching")
            return redirect('/accounts/register')

    else:
        return render(request, 'accounts/register.html')


def login(request):
    # redirect_to = request.get('next', '')
    if request.method == 'POST':
        username = request.POST['username']
        password = request.POST['password']
        user = auth.authenticate(username=username, password=password)
        if user is not None:
            # this user becomes available in the page being redirected
            auth.login(request, user)
            print("Logged in")
            return redirect("/")
        else:
            messages.info(request, "Invalid Credentials")
            return redirect('/accounts/login')
    return render(request, 'accounts/login.html')


def logout(request):
    auth.logout(request)
    # or redirect to a logged out page
    return redirect('/travello')