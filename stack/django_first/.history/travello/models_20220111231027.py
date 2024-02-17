from django.db import models

class Destination:
    id: int
    name: str
    img: str
    desc: str
    price: int
    offer: bool
    def __init__(self, id, name, img, desc, price, offer):
        self.id = id
        self.name = name
        self.img = img
        self.desc = desc
        self.price = price
        self.offer = offe