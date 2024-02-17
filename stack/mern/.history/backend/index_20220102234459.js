import app from './server.js'
import mongodb from 'mongodb'
import dotenv from 'dotenv'
import RestaurantsDAO from '.'
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
    process.exit(1)
}).then(async client => {
    app.listen(port, ()=>{
          console.log(`listening on port ${port}`);
    })
})