from django.db import models

class Destination(models.Model):
    name: models.CharField(max_length=100)
    img: str
    desc: models.T
    price: int
    offer: bool
    def __init__(self, id, name, img, desc, price, offer):
        self.id = id
        self.name = name
        self.img = img
        self.desc = desc
        self.price = price
        self.offer = offer