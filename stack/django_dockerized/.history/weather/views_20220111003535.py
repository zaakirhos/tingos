from django.shortcuts import render
def index(request):
    url = 'https://api.openweathermap.org/data/2.5/weather?q={}&units=imperial&appid=c9ceb621d594924f58ab5a4104cba5ff'
    city
    return render(request, 'weather/weather.html')