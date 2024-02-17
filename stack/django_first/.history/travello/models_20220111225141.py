from django.db import models

class Destination:
    id: int
    name: str
    img: str
    desc: str
    price: int
    def __init__(self) -> None:
        pass
