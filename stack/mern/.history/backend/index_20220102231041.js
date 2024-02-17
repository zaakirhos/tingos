import app from './server.js'
import mongodb from 'mongodb'
import dotenv from 'dotenv'
dotenv.config()
const MongoClient = mongodb.MongoClient

const port = process.env.PORT

MongoClient.connect(
    process.env.DB_URI, {
        maxPoolSize: 50,
        wtimeoutMS: 2500,
    }
).catch(err => {
    console.error(err.stack)
    process.exit()
}).then(async client => {
    app.listen(port)
    console.log(`listeninng on port ${port}`)
})