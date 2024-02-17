from django import urls
from django.urls import path
from . import views

urls.patterns = [
    path('', views.index, name='hello'),
]