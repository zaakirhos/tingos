from django.db import models

class City(models.Model):
    name = models.CharField(max_length=50)
    def __str__(self):
        return self.name
    # need this because by default the plural will be citys'
    class Meta:
        verbose_name_plural = "cities"
