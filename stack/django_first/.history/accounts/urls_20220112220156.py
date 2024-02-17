"""This is where the mapping between urls and views happens"""

from django.urls import path
from . import views

urlpatterns = [
    # when arrived at home page, the home function from views will be loaded
    path('register', views.register, name='register'),
]
