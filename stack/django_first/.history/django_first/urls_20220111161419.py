
from django.contrib import admin
from django.urls import path, include

"""
path(base_url, sub_urls)
Given the base_url
"""
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('calc.urls') )
]
