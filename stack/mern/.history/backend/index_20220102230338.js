import app from './server.js'
import mongodb from 'mongodb'
import dotenv from 'dotenv'
dotenv.config()
const MongoClient = mongodb.MongoClient

const port = process.env.PORt || 8000

MongoClient.connect(
    process.env.DB_URI, {
        poolSize: 50,
        wtimeout: 2500,
    }
).catch(err => {
    console.error(err.stack)
    process.exit()
}).then(async client => {
    console.log(`listeninng on port ${port}`)
})