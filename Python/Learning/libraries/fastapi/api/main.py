from fastapi import FastAPI
from pydantic import BaseModel
from typing import Optional


app = FastAPI()

fakeDB = []

class Course(BaseModel):
    id: int 
    name: str
    price: float
    is_early_bird: Optional[bool] = None


@app.get("/")
def read_root():
    return {"Greetings": "Welcome to FAST"}

@app.get("/course")
def get_courses():
    return fakeDB

@app.get("/courses/{course_id}")
def getACourse(course_id: int):
    course = course_id - 1
    return fakeDB[course]

@app.post("/courses")
def add_courses(course: Course):
    fakeDB.append(course.dict())
    return fakeDB[-1]

@app.delete("/courses/{course_id}")
def delete_courses(course_id: int):
    fakeDB.pop(course_id-1)
    return {"task": "deletion successful"}
