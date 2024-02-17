import express from 'express'
import RestaurantsCtrl from './restaurants.controller.js'
import ReviewsCtrl from "./restaurants.controller.js";
const router = express.Router()

router.route('/').get(RestaurantsCtrl.apiGetRestaurants)
router.route("/id/:id").get(RestaurantsCtrl.apiGetRestaurantById);


export default router