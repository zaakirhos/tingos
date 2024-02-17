from django.forms import ModelForm, TextInput

from .models import City

class CityForm(ModelForm):
    model = City
    fields = ['name']
    widgets = {'name'