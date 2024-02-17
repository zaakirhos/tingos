import requests
from django.shortcuts import render
from .models import City
from .forms import CityForm


def index(request):
    url = 'https://api.openweathermap.org/data/2.5/weather?q={}&units=imperial&appid=c9ceb621d594924f58ab5a4104cba5ff'

    if request.method == 'POST':
        pass

    
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
    print(weather_data)
    context = {'weather_data': weather_data}
    return render(request, 'weather/weather.html', context)
