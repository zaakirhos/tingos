from django.db import models

class Destination(models.Model):
    name = models.CharField(max_length=100)
    img = models.ImageField(upload_to='pics')
    desc = models.TextField()
    price = models.IntegerField()
    offer = models.BooleanField(default=False)
    # def __init__(self, name, img, desc, price, offer):
    #     self.name = name
    #     self.img = img
    #     self.desc = desc
    #     self.price = price
    #     self.offer = offer

    class Destination(models.Model):
    name = models.CharField(max_length=100)
    img = models.ImageField(upload_to='pics')
    desc = models.TextField()
    price = models.IntegerField()
    offer = models.BooleanField(default=False)
    # def __init__(self, name, img, desc, price, offer):
    #     self.name = name
    #     self.img = img
    #     self.desc = desc
    #     self.price = price
    #     self.offer = offer
