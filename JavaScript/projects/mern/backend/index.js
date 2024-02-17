import app from "./server.js";
import mongodb from 'mongodb'
import dotenv from 'dotenv'

dotenv.config()
const MongoClient = mongodb.MongoClient

const port = process.env.PORT || 8000

 MongoClient.connect(process.env.RESTREVIEWS_DB_URI,{

    poolSize: 50, // people can connect at a time
    writeConcern: 2500, //time for request
    useNewUserParse: true
 })
 .catch(err => {
     console.log(err)
     process.exit(1).stack
 })
 .then(async client =>{
     app.listen(port, () =>{
         console.log(`Listening on port ${port}`)
     })
 })