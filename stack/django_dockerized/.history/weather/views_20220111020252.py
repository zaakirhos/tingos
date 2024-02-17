import requests
from django.shortcuts import redirect, render, redirect
from .models import City
from .forms import CityForm


def index(request):
    err_msg = ''
    message = ''
    message_class = ''
    url = 'https://api.openweathermap.org/data/2.5/weather?q={}&units=imperial&appid=c9ceb621d594924f58ab5a4104cba5ff'

    if request.method == 'POST':
        form = CityForm(request.POST)

        if form.is_valid():
            new_city = form.cleaned_data['name']
            count = City.objects.filter(name=new_city).count()

            if count == 0:
                r = requests.get(url.format(new_city)).json()
                if r['cod'] == 200:
                    form.save()
                else:
                    err_msg = "City does not exist in the world"
            else:
                err_msg = 'City already exists'
        if err_msg:
            message = err_msg
            message_class = 'is-danger'
        else:
            message = 'City added successfully'
            message_class = 'is-success'

    form = CityForm()

    cities = City.objects.all()
    weather_data = []
    for city in cities:

        r = requests.get(url.format(city)).json()

        city_weather = {
            'city': city.name,
            'temperature': r['main']['temp'],
            'decription': r['weather'][0]['description'],
            'icon': r['weather'][0]['icon'],
        }
        weather_data.append(city_weather)
    context = {'weather_data': weather_data, 'form': form,
               'message': message,
               'message_class': message_class
               }
    return render(request, 'weather/weather.html', context)

def delete_city(request,  city_name):
    Ci
    return redirect('index')