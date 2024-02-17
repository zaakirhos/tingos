
from django.contrib import admin
from django.urls import path, include

"""
path(base_url, sub_urls)
:param base_url: the base url
:param sub_urls: all the suburls in a view which shares the same :base_url:

Given the :base_url:, all the sub_urls will be appended to 
this :base_url:

Any urls in the :sub_urls: has base url to be :base_url:
"""
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('calc.urls') )
    path('', include('calc.urls'))
]
