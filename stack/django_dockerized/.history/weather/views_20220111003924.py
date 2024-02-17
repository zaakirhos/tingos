import requests
from django.shortcuts import render
def index(request):
    url = 'https://api.openweathermap.org/data/2.5/weather?q={}&units=imperial&appid=c9ceb621d594924f58ab5a4104cba5ff'
    city = 'Philadelphia'

    r = requests.get(url.format(city)).json()

    city_weather = {
        'city' : city,
        'temperature' : r['main']['temp'],
        'decription' : r['weather'][0]['description'],
        'icon' : r['weather'][0]['icon'],
    }
    return render(request, 'weather/weather.html')