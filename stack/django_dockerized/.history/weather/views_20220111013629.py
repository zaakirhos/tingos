import requests
from django.shortcuts import render
from .models import City
from .forms import CityForm

err_
def index(request):
    url = 'https://api.openweathermap.org/data/2.5/weather?q={}&units=imperial&appid=c9ceb621d594924f58ab5a4104cba5ff'

    if request.method == 'POST':
        form = CityForm(request.POST)

        if form.is_valid():
            new_city = form.cleaned_data['name']
            count = City.objects.filter(name=new_city).count()
            
            if count == 0:
                form.save()
            

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
    context = {'weather_data': weather_data, 'form': form}
    return render(request, 'weather/weather.html', context)
