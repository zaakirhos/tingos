import express from 'express'
import cors from 'cors'
import restaurants from './api/restaurants.route.js'

const app = express()

app.use(cors())
app.use(express.json()) // our server can accept and read json

app.use("/api/v1/restaurants", restaurants)
app.use("*", (req, res0)) // * wildcard means routes that are not in our routes file