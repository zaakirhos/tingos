"""This is where the mapping between urls and views happens"""

from django.urls import path
from . import views

urlpatterns = [
    path('register', views.register, name='register'),
    path('register', views.register, name='register'),
]
