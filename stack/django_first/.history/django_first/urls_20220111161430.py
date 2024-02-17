
from django.contrib import admin
from django.urls import path, include

"""
path(base_url, sub_urls)
Given the base_url, all the sub_urls will be appeend
"""
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('calc.urls') )
]
