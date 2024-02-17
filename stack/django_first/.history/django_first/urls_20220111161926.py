
from django.contrib import admin
from django.urls import path, include

"""
path(base_url, sub_urls)
 
Given the base_url, all the sub_urls will be appended to 
this base_url

An urls in the sub_urls has base url to be base_url
"""
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('calc.urls') )
]
