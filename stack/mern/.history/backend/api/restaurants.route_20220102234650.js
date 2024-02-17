import express from 'express'
import 
const router = express.Router()

router.route('/').get((req, res) => res.send("Hello World!"))


export default router