
from django.contrib import admin
from django.urls import path, include

"""
path(base)
"""
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('calc.urls') )
]
