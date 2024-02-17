import express from 'express'
import RestaurantsCtrl from './restaurants.controller.js'
import ReviewsCtrl from "./restaurants.controller.js";
const router = express.Router()

router.route('/').get(RestaurantsCtrl.apiGetRestaurants)
router.route("/").get(ReviewsCtrl.apiGetRestaurants);


export default router